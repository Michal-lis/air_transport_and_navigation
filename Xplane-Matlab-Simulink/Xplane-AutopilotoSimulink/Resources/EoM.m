function xdot = EoM(x,u)
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


% Cálculo de las ecuaciones del movimiento

global S b c_bar m I_xx I_yy I_zz I_xz q_bar g D_prop ALPHAr rho

% Coeficientes de Fuerza, Empuje y Momento %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

[CD,CL,CY,Cl,Cm,Cn,CT,RPM] = c172DataTable(x,u);
    
CX = -CD*cos(ALPHAr) + CL*sin(ALPHAr);	% Body-axis X coefficient
CZ = -CD*sin(ALPHAr) - CL*cos(ALPHAr);	% Body-axis Z coefficient

THR = (CT*rho*(RPM/60)^2*D_prop^4)/g;   % Thrust force [lbf]
Xb  = (CX*q_bar*S + THR)/m;             % Longitudinal force [lbf]
Yb  = CY*q_bar*S/m;                     % Side force [lbf]
Zb  = CZ*q_bar*S/m;                     % Vertical force [lbf]
Lb  = Cl*q_bar*S*b;                     % Roll moment [lbf·ft]
Mb  = Cm*q_bar*S*c_bar;                 % Pitch moment [lbf·ft]                  
Nb  = Cn*q_bar*S*b;                     % Yaw moment  [lbf·ft]



% Ecuaciones de fuerza %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

xd1 = Xb - g * sin(x(8)) + x(6) * x(2) - x(5) * x(3);               % ub_dot
xd2 = Yb + g * sin(x(7)) * cos(x(8)) - x(6) * x(1) + x(4) * x(3);   % vb_dot
xd3 = Zb + g * cos(x(7)) * cos(x(8)) + x(5) * x(1) - x(4) * x(2);   % wb_dot

% Ecuaciones de momento %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

xd4	= (I_zz * Lb + I_xz * Nb - (I_xz * (I_yy - I_xx - I_zz) * x(4) + ...
  (I_xz^2 + I_zz * (I_zz - I_yy)) * x(6)) * x(5)) / (I_xx * I_zz - I_xz^2); % p_dot
xd5 = (Mb - (I_xx - I_zz) * x(4) * x(6) - I_xz * (x(4)^2 - x(6)^2)) / I_yy; % q_dot
xd6 = (I_xz * Lb + I_xx * Nb + (I_xz * (I_yy - I_xx - I_zz) * x(6) + ...
  (I_xz^2 + I_xx * (I_xx - I_yy)) * x(4)) * x(5)) / (I_xx * I_zz - I_xz^2); % r_dot

% Ecuaciones cinemáticas %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

cosPitch = cos(x(8));
if abs(cosPitch) <= 0.00001
	cosPitch = 0.00001*sign(cosPitch);
end
tanPitch = sin(x(8)) / cosPitch;
	
xd7	= x(4) + (sin(x(7)) * x(5) + cos(x(7)) * x(6)) * tanPitch;      % phi_dot
xd8	= cos(x(7)) * x(5) - sin(x(7)) * x(6);                          % theta_dot
xd9	= (sin(x(7)) * x(5) + cos(x(7)) * x(6)) / cosPitch;             % psi_dot


xdot = [xd1 xd2 xd3 xd4 xd5 xd6 xd7 xd8 xd9]';