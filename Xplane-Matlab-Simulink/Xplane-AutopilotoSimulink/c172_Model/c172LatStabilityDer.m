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


% MODELO LINEAL TRANSVERSAL CESSNA C-172 (ROSKAM) %%%%%%%%%%%%%%%%%%%%%%%%%

global S b m I_xx I_yy I_zz I_xz q_bar

% Lateral-Directional Stability Derivatives (Stability Axes, Dimensionless)

C_l_beta   = [-0.0895 -0.0923 -0.0969]; % 1/rad
C_l_p      = [-0.487  -0.484  -0.494];  % 1/rad
C_l_r      = [ 0.1869  0.0798  0.2039]; % 1/rad
C_Y_beta   = [-0.404  -0.393  -0.303];  % 1/rad
C_Y_p      = [-0.145  -0.075  -0.213];  % 1/rad
C_Y_r      = [ 0.267   0.214   0.201];  % 1/rad
C_n_beta   = [ 0.0907  0.0587  0.0701]; % 1/rad
C_n_T_beta = [ 0       0       0];
C_n_p      = [-0.0649 -0.0278 -0.0960]; % 1/rad
C_n_r      = [-0.1199 -0.0937 -0.1151]; % 1/rad

% Lateral-Directional Control and Hinge Moment Derivatives (Stability Axes, Dimensionless)

C_l_d_a  = [ 0.229   0.229   0.229];  % 1/rad
C_l_d_r  = [ 0.0147  0.0147  0.0147]; % 1/rad
C_Y_d_a  = [ 0       0       0];      % 1/rad
C_Y_d_r  = [ 0.187   0.187   0.187];  % 1/rad
C_n_d_a  = [-0.0504 -0.0216 -0.0786]; % 1/rad
C_n_d_r  = [-0.0805 -0.0645 -0.0604]; % 1/rad

C_h_d_a  = [-0.369  -0.363  -0.369];  % 1/rad
C_h_d_r  = [-0.579  -0.567  -0.579];  % 1/rad
C_h_beta_r = [0.0819 0.0819  0.0819]; % 1/rad



% CONTROL POR ESPACIO DE ESTADOS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%----------------------------------------------------------------------
% Lateral derivatives
%----------------------------------------------------------------------

I_xx_s = I_xx*cos(AOA_Nr)^2 + I_zz*sin(AOA_Nr)^2 - I_xz*sin(2*AOA_Nr);
I_yy_s = I_yy;
I_zz_s = I_xx*sin(AOA_Nr)^2 + I_zz*cos(AOA_Nr)^2 + I_xz*sin(2*AOA_Nr);
I_xz_s = .5*(I_xx - I_zz)*sin(2*AOA_Nr) + I_xz*cos(2*AOA_Nr);

% Stability axis %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Y_beta   = q_bar*S/m * C_Y_beta(k);               % ft/s^2
Y_p      = q_bar*S*b/2/m/V_N * C_Y_p(k);          % ft/s
Y_r      = q_bar*S*b/2/m/V_N * C_Y_r(k);          % ft/s
Y_d_a    = q_bar*S/m * C_Y_d_a(k);                % ft/s^2
Y_d_r    = q_bar*S/m * C_Y_d_r(k);                % ft/s^2
L_beta   = q_bar*S*b/I_xx_s * C_l_beta(k);        % 1/s^2
L_p      = q_bar*S*b^2/2/I_xx_s/V_N * C_l_p(k);   % 1/s
L_r      = q_bar*S*b^2/2/I_xx_s/V_N * C_l_r(k);   % 1/s
L_d_a    = q_bar*S*b/I_xx_s * C_l_d_a(k);         % 1/s^2
L_d_r    = q_bar*S*b/I_xx_s * C_l_d_r(k);         % 1/s^2
N_beta   = q_bar*S*b/I_zz_s * C_n_beta(k);        % 1/s^2
N_T_beta = q_bar*S*b/I_zz_s * C_n_T_beta(k);
N_p      = q_bar*S*b^2/2/I_zz_s/V_N * C_n_p(k);   % 1/s
N_r      = q_bar*S*b^2/2/I_zz_s/V_N * C_n_r(k);   % 1/s
N_d_a    = q_bar*S*b/I_zz_s * C_n_d_a(k);         % 1/s^2
N_d_r    = q_bar*S*b/I_zz_s * C_n_d_r(k);         % 1/s^2