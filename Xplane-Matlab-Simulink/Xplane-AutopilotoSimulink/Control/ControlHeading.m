function [K,L,A11,A12,A21,A22,B1,B2] = ControlHeading(xTrim,k,Ts)
% Copyright 2012 Borja Fons Albert, Hèctor Usach Molina, Joan Vila Carbó.
% All rights reserved.
% 
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are
% met:
% 
%  1. Redistributions of source code must retain the above copyright
%     notice, this list of conditions and the following disclaimer.
% 
%  2. Redistributions in binary form must reproduce the above copyright
%     notice, this list of conditions and the following disclaimer in the
%     documentation and/or other materials provided with the distribution.
% 
% THIS SOFTWARE IS PROVIDED BY BORJA FONS ALBERT, HÈCTOR USACH MOLINA AND
% JOAN VILA CARBÓ ''AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
% INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
% AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
% BORJA FONS ALBERT, HÈCTOR USACH MOLINA AND JOAN VILA CARBÓ OR
% CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
% EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
% PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
% PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
% LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
% NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
% SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
% 
% The views and conclusions contained in the software and documentation are
% those of the authors and should not be interpreted as representing
% official policies, either expressed or implied, of Borja Fons Albert,
% Hèctor Usach Molina and Joan Vila Carbó.


% CONTROL POR ESPACIO DE ESTADOS
%
%   Vector de estado X
%      x(1) = p (rad/s)        Roll rate
%      x(2) = r (rad/s)        Yaw rate
%      x(3) = PHI (rad)        Roll angle
%      x(4) = PSI (rad)        Heading angle
%      x(5) = BETA (rad)       Sideslip angle
%     %%%%%%
%      x(6) = e1 = ref - PSI (rad)  Heading error
%      x(7) = e2 = ref - BETA (rad) Turn coordinator
%
%   Vector de control U
%      u(1) = AILE (rad)
%      u(2) = RUDD (rad)
%
% El programa calculas las matrices A, B, C, D del control por espacio de
% estados para el movimiento en el plano lateral, las discretiza y
% construye un observador de orden reducido para beta.
% Al vector de estado se le añade la variable de error e1, que integra el
% error del rumbo, y la variable e2, que minimiza el angulo de deslizamiento.

global g ailerons_min rudder_max

% run c172Model

V_N      = xTrim(1);
THETA_Nr = xTrim(2);
GAMMA_Nr = xTrim(4);
AOA_Nr   = THETA_Nr - GAMMA_Nr;


% Modelo Lineal Cessna C-172 (ROSKAM) %

run c172LatStabilityDer


%----------------------------------------------------------------------
% Modelo continuo en espacio de estados
%----------------------------------------------------------------------

A = zeros(5,5);
B = zeros(5,2);
C = eye(5);
D = 0;
E = eye(5);

% Roll rate dynamics

A(1,1) = L_p;
A(1,2) = L_r;
A(1,3) = 0;
A(1,4) = 0;
A(1,5) = L_beta;

B(1,1) = L_d_a;
B(1,2) = L_d_r;

E(1,2) = -I_xz_s/I_xx_s;

% Yaw rate dynamics

A(2,1) = N_p;
A(2,2) = N_r;
A(2,3) = 0;
A(2,4) = 0;
A(2,5) = N_T_beta + N_beta;

B(2,1) = N_d_a;
B(2,2) = N_d_r;

E(2,1) = -I_xz_s/I_zz_s;

% Roll angle dynamics

A(3,1) = 1;
A(3,2) = tan(THETA_Nr);
A(3,3) = 0;
A(3,4) = 0;
A(3,5) = 0;

B(3,1) = 0;
B(3,2) = 0;

%E(3,4) = -sin(THETA_Nr);

% Yaw angle dynamics

A(4,1) = 0;
A(4,2) = 1;
A(4,3) = 0;
A(4,4) = 0;
A(4,5) = 0;

B(4,1) = 0;
B(4,2) = 0;

E(4,4) = cos(THETA_Nr);

% Sideslip angle dynamics

A(5,1) = Y_p;
A(5,2) = Y_r - V_N;
A(5,3) = g*cos(THETA_Nr);
A(5,4) = 0;
A(5,5) = Y_beta;

B(5,1) = Y_d_a;
B(5,2) = Y_d_r;

E(5,5) = V_N;

% Heading error dynamics (integrador)

Aa = [A, zeros(5,1); 0 0 0 -1 0 0];
Ba = [B; zeros(1,2)];
Ca = C; Ca(5,6) = 0;
Da = D;
Ea = E; Ea(6,6) = 1;

% Integrador (beta)

Aa = [Aa, zeros(6,1); 0 0 0 0 -1 0 0];
Ba = [Ba; zeros(1,2)];
Ca(5,7) = 0;
Ea(7,7) = 1;


sistema = dss(Aa, Ba, Ca, Da, Ea);


%--------------------------------------------------------------------------
% Modelo discreto
%--------------------------------------------------------------------------

sistema_discreto = c2d(sistema, Ts);

Ad = sistema_discreto.a;
Bd = sistema_discreto.b;
Cd = sistema_discreto.c;
Dd = sistema_discreto.d;


%--------------------------------------------------------------------------
% Análisis del sistema
%--------------------------------------------------------------------------

% Frecuencias naturales, coef de amortiguamiento y polos del sistema

[Wn,Z,Polos] = damp(sistema_discreto);

Estabilidad = abs(Polos);

co = ctrb(Ad,Bd);   % Matriz de controlabilidad
Controlabilidad = rank(co);

ob = obsv(Ad,Cd);   % Matriz de observabilidad
Observabilidad = rank(ob);


%--------------------------------------------------------------------------
% Control estabilizante
%--------------------------------------------------------------------------

% Control por asignación de polos

% polos_sistema = .98*Polos;
% K = place(Ad, Bd, polos_sistema);   % Matriz de control

% Control LQR (Linear-quadratic regulator)

Q = eye(6);
R = eye(2);

Q(1,1) = 500;               % rollrate
Q(2,2) = 0;                 % yawrate
Q(3,3) = 300;               % roll (5*pi/180)^-2;
Q(4,4) = 0;                 % heading
Q(5,5) = 0;                 % beta
Q(6,6) = 10;                % e_heading
Q(7,7) = 10;                % e_beta

R(1,1) = ailerons_min^-2;
R(2,2) = rudder_max^-2;

[K, sol, e] = dlqr(Ad,Bd,Q,R);

% K    Ganancia óptima
% sol  Solución de la ecuación de Riccati
% e    Polos del sistemaen bucle cerrado


%--------------------------------------------------------------------------
% Observador de orden reducido
%--------------------------------------------------------------------------

% Para usar el observador reducido hay que definir las submatrices
% observables y no observables. Si las variables no estuviesen ordenadas
% habria que ordenarlas, en este caso si lo estan.

n_estados = 5;
n_estados_observables = 4;

% Submatrices A
A11 = Ad(1:n_estados_observables, 1:n_estados_observables);
A12 = Ad(1:n_estados_observables, n_estados_observables+1:n_estados);
A21 = Ad(n_estados_observables+1:n_estados, 1:n_estados_observables);
A22 = Ad(n_estados_observables+1:n_estados, n_estados_observables+1:n_estados);

% Submatrices B
B1 = Bd(1:n_estados_observables,:);
B2 = Bd(n_estados_observables+1:n_estados,:);

% Diseño de la dinamica del observador
% Se trata de que el modelo sea capaz de alcanzar al sistema real, es
% decir, que la estimacion tienda a la  realidad. Para ello se define una
% dinamica que debe ser estable (polos discretos dentro del circulo unidad)
% Se usa el mismo comando que para el controlador. El criterio para la
% asignacion de polos en este caso es que sean mas rapidos que el propio
% sistema para que la estimacion pueda alcanzar a la realidad.

polos_observador = 0.4;
L = place(A22', A12', polos_observador)';
