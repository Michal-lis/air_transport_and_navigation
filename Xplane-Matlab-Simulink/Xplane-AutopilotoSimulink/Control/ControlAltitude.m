function [K,L,A11,A12,A21,A22,B1,B2] = ControlAltitude(xTrim,k,Ts)
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
%      x(1) = VT (ft/s)     Velocity
%      x(2) = THETA (rad)   Pitch angle
%      x(3) = q (rad/s)     Pitch rate
%      x(4) = h (ft)        Altitude
%      x(5) = GAMMA (rad)   Flight path angle
%     %%%%%%
%      x(6) = ref - h (ft)  Altitude error
%
%   Vector de control U
%      u(1) = ELEV (rad)
%      u(2) = THTL (%)
%
% El programa calculas las matrices A, B, C, D del control por espacio de
% estados para el movimiento en el plano longitudinal, las discretiza y
% construye un observador de orden reducido para gamma.
% Al vector de estado se le añade la variable de error v, que integra el
% error de la diferencia entre la referencia de altitud y el valor actual.

global g elevators_min

V_N      = xTrim(1);
THETA_Nr = xTrim(2);
GAMMA_Nr = xTrim(4);
AOA_Nr   = THETA_Nr - GAMMA_Nr;


% Modelo Lineal Cessna C-172 (ROSKAM) %

run c172LonStabilityDer


%----------------------------------------------------------------------
% Modelo continuo en espacio de estados
%----------------------------------------------------------------------

A = zeros(5,5);
B = zeros(5,1);
C = eye(5);
D = 0;
E = eye(5);

% Velocity dynamics

A(1,1) = X_V + X_T_V*cos(AOA_Nr);
A(1,2) = X_alpha - g*cos(GAMMA_Nr);
A(1,3) = 0;
A(1,4) = 0;
A(1,5) = -X_alpha;

B(1,1) = X_d_e;
%B(1,2) = X_d_t*cos(AOA_Nr);

% Pitch angle dynamics

A(2,1) = 0;
A(2,2) = 0;
A(2,3) = 1;
A(2,4) = 0;
A(2,5) = 0;

B(2,1) = 0;
%B(2,2) = 0;

% Pitch rate dynamics

A(3,1) = M_V + M_T_V;
A(3,2) = (M_alpha + M_T_alpha);
A(3,3) = M_q + M_alpha_dot;
A(3,4) = 0;
A(3,5) = -(M_alpha + M_T_alpha);

B(3,1) = M_d_e;
%B(3,2) = M_d_t;

E(3,5) = M_alpha_dot;

% Altitude dynamics

A(4,1) = sin(GAMMA_Nr);
A(4,2) = 0;
A(4,3) = 0;
A(4,4) = 0;
A(4,5) = V_N*cos(GAMMA_Nr);

B(4,1) = 0;
%B(4,2) = 0;

% Flight Path Angle dynamics

A(5,1) = -(Z_V - X_T_V*sin(AOA_Nr));
A(5,2) = -(Z_alpha - g*sin(GAMMA_Nr));
A(5,3) = -(Z_q + Z_alpha_dot);
A(5,4) = 0;
A(5,5) = Z_alpha;

B(5,1) = -Z_d_e;
%B(5,2) = X_d_t*sin(AOA_Nr);

E(5,5) = (V_N - Z_alpha_dot);

% Altitude error dynamics (integrador)

Aa = [A, zeros(5,1); 0 0 0 -1 0 0];
Ba = [B; 0];
Ca = C; Ca(5,6) = 0;
Da = D;
Ea = E; Ea(6,6) = 1;


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

% polos_sistema = [0.999
%                  0.998
%                  0.99+1i*0.007
%                  0.99-1i*0.007
%                  0.78+1i*0.04
%                  0.78-1i*0.04];
% K = place(Ad, Bd, polos_sistema)   % Matriz de control

% Control LQR (Linear-quadratic regulator)

Q = eye(6);
R = 1;

Q(1,1) = .01; 
Q(2,2) = 0.1;
Q(3,3) = 1000;
Q(4,4) = 0.5;
Q(5,5) = 0.1;
Q(6,6) = 0.1;

R(1,1) = elevators_min^-2;

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

polos_observador = 0.86;

L = place(A22', A12', polos_observador)';
