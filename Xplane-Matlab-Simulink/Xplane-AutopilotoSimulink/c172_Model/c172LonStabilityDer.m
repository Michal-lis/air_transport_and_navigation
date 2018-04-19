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


% MODELO LINEAL LONGITUDINAL CESSNA C-172 (ROSKAM) %%%%%%%%%%%%%%%%%%%%%%%%

global S c_bar m I_yy q_bar

% Steady State Coefficients %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

C_L_N   = [0.719  0.307   1.120];
C_D_N   = [0.057  0.032   0.132];
C_T_N   = [0.057  0.032   0.132];
C_m_N   = [0      0       0];
C_m_T_N = [0      0       0];

% Longitudinal Coefficients and Stability Derivatives [Dimensionless] %%%%%

C_D_0         = [0.0270 0.0270  0.0605];
C_D_V         = [0      0       0];
C_D_alpha     = [0.380  0.121   0.547];  % 1/rad
C_T_V         = [-0.171 -0.096  -0.396];
C_L_0         = [0.307  0.307   0.807];
C_L_V         = [0      0       0];
C_L_alpha     = [4.41   4.41    4.41];   % 1/rad
C_L_alpha_dot = [1.7    1.7     1.7];    % 1/rad
C_L_q         = [3.9    3.9     3.9];    % 1/rad
C_m_0         = [0.04   0.04    0.09];
C_m_V         = [0      0       0];
C_m_alpha     = [-0.650 -0.613  -0.611]; % 1/rad
C_m_alpha_dot = [-5.57  -7.27   -5.40];  % 1/rad
C_m_q         = [-15.2  -12.4   -11.4];  % 1/rad
C_m_T_V       = [0      0       0];
C_m_T_alpha   = [0      0       0];

% Longitudinal Control and Hinge Moment Derivatives [1/rad] %%%%%%%%%%%%%%%

C_D_d_e = [0        0       0];          % 1/rad
C_L_d_e = [0.43     0.43    0.43];       % 1/rad
C_m_d_e = [-1.369   -1.122  -1.029];     % 1/rad
C_D_i_h = [0        0       0];
C_L_i_h = [0        0       0];
C_m_i_h = [0        0       0];



% CONTROL POR ESPACIO DE ESTADOS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%----------------------------------------------------------------------
% Longitudinal derivatives
%----------------------------------------------------------------------

X_V         = -q_bar*S/m/V_N*(2*C_D_N(k)+C_D_V(k));              % 1/s
X_T_V       =  q_bar*S/m/V_N*(2*C_T_N(k)+C_T_V(k));              % 1/s
X_alpha     =  q_bar*S/m*(C_L_N(k)-C_D_alpha(k));                % ft/s^2
X_d_e       = -q_bar*S/m*C_D_d_e(k);                             % ft/s^2
Z_V         = -q_bar*S/m/V_N*(2*C_L_N(k)+C_L_V(k));              % 1/s
Z_alpha     = -q_bar*S/m*(C_D_N(k)+C_L_alpha(k));                % ft/s^2
Z_alpha_dot = -q_bar*S*c_bar/2/m/V_N*C_L_alpha_dot(k);           % ft/s
Z_q         = -q_bar*S*c_bar/2/m/V_N*C_L_q(k);                   % [ft/s
Z_d_e       = -q_bar*S/m*C_L_d_e(k);                             % ft/s^2
M_V         =  q_bar*S*c_bar/V_N/I_yy*(2*C_m_N(k)+C_m_V(k));     % 1/ft·s
M_T_V       =  q_bar*S*c_bar/V_N/I_yy*(2*C_m_T_N(k)+C_m_T_V(k)); % 1/ft·s
M_T_alpha   =  q_bar*S*c_bar/I_yy*C_m_T_alpha(k);                % 1/s^2
M_alpha     =  q_bar*S*c_bar/I_yy*C_m_alpha(k);                  % 1/s^2
M_alpha_dot =  q_bar*S*c_bar^2/2/V_N/I_yy*C_m_alpha_dot(k);      % 1/s
M_q         =  q_bar*S*c_bar^2/2/V_N/I_yy*C_m_q(k);              % 1/s
M_d_e       =  q_bar*S*c_bar/I_yy*C_m_d_e(k);                    % 1/s^2
%Obtener X_d_t y M_d_t para modelo del motor en espacio de estados
X_d_t       =  0;
M_d_t       =  0;
