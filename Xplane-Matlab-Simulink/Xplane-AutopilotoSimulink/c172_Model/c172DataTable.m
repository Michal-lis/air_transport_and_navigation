function [CD,CL,CY,Cl,Cm,Cn,CT,RPM] = c172DataTable(x,u)

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



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% CESSNA C-182 NONLINEAR MODEL
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

global  altitude_trim b c_bar D_prop

% STATE *******
V        = sqrt(x(1)^2+x(2)^2+x(3)^2);   % ft/s
BETAr    = asin(x(2)/V);                 % rad
BETAmax  = 0.3490;                       % rad
BETAnorm = BETAr/BETAmax;
ALPHAr   = atan(x(3)/x(1));              % rad
ALPHAdot = 0;                            % rad/s
P        = x(4);                         % rad/s
Q        = x(5);                         % rad/s
R        = x(6);                         % rad/s

% CONTROLS *******
ELEVr    = u(1);                         % rad
AILEr    = u(2);                         % rad
RUDDr    = u(3);                         % rad
THTL     = u(4);                         % %/100
FLAPdeg  = u(5);                         % deg

FlapVector  = [0.0000 10.0000 20.0000 30.0000]; % deg



%% DRAG FORCE %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

CDalphaVector = [-0.0873 -0.0698 -0.0524 -0.0349 -0.0175 0.0000 0.0175...
    0.0349 0.0524 0.0698 0.0873 0.1047 0.1222 0.1396 0.1571 0.1745...
    0.1920 0.2094 0.2269 0.2443 0.2618 0.2793 0.2967 0.3142 0.3316...
    0.3491]'; % rad

CDalphaTable = [0.0041
                0.0013
                0.0001
                0.0003
                0.0020
                0.0052
                0.0099
                0.0162
                0.0240
                0.0334
                0.0442
                0.0566
                0.0706
                0.0860
                0.0962
                0.1069
                0.1180
                0.1298
                0.1424
                0.1565
                0.1727
                0.1782
                0.1716
                0.1618
                0.1475
                0.1097];

CDdfTable    = [0.0000	0.0030	0.0084	0.0153
                0.0000	0.0061	0.0131	0.0208
                0.0000	0.0092	0.0178	0.0263
                0.0000	0.0124	0.0225	0.0317
                0.0000	0.0155	0.0272	0.0372
                0.0000	0.0186	0.0319	0.0427
                0.0000	0.0218	0.0367	0.0483
                0.0000	0.0250	0.0415	0.0539
                0.0000	0.0282	0.0463	0.0594
                0.0000	0.0314	0.0511	0.0650
                0.0000	0.0346	0.0558	0.0706
                0.0000	0.0378	0.0606	0.0762
                0.0000	0.0409	0.0654	0.0818
                0.0000	0.0441	0.0702	0.0873
                0.0000	0.0461	0.0731	0.0907
                0.0000	0.0480	0.0760	0.0941
                0.0000	0.0499	0.0789	0.0975
                0.0000	0.0518	0.0818	0.1008
                0.0000	0.0538	0.0847	0.1043
                0.0000	0.0559	0.0879	0.1080
                0.0000	0.0582	0.0913	0.1120
                0.0000	0.0590	0.0925	0.1133
                0.0000	0.0581	0.0911	0.1117
                0.0000	0.0567	0.0890	0.1093
                0.0000	0.0546	0.0859	0.1056
                0.0000	0.0485	0.0767	0.0950];

CD0     = 0.027;                                                      % Drag at zero lift
CDalpha = interp1(CDalphaVector,CDalphaTable,ALPHAr);                 % Drag due to alpha
CDbeta  = 0.1700;                                                     % Drag due to sideslip
CDde    = 0;                                                          % Drag due to elevator deflection
CDdf    = interp2(FlapVector,CDalphaVector,CDdfTable,FLAPdeg,ALPHAr); % Drag due to flap deflection

CD = CD0 + CDalpha + CDbeta*BETAnorm + CDde*ELEVr + CDdf;             % Drag coefficient

% plot(CDalphaVector*180/pi,CDalphaTable)
% xlabel('\alpha (deg)')
% ylabel('C_D_\alpha')
% grid

% figure
% plot(CDalphaVector*180/pi,CDdfTable)
% legend('Flaps 0º','Flaps 10º','Flaps 20º','Flaps 30º','Location','Best')
% xlabel('\alpha (deg)')
% ylabel('C_D_\delta_F')
% grid



%% LIFT FORCE %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

CLalphaVector = [-0.0900 0.0000 0.1400 0.2100 0.2400 0.2600 0.2800...
    0.3000 0.3200 0.3400 0.3600]'; % rad

CLalphaTable  = [-0.5270
                 -0.0570
                 0.7130
                 0.9450
                 1.0470
                 1.1330
                 1.1590
                 1.1250
                 1.0740
                 0.9910
                 0.6630];

h_b = altitude_trim/b;

h_b_Vector = [0.0000 0.1000 0.1500 0.2000 0.3000 0.4000 0.5000 0.6000...
    0.7000 0.8000 0.9000 1.0000 1.1000]';

kCLgeTable    = [1.2030
                 1.1270
                 1.0900
                 1.0730
                 1.0460
                 1.0550
                 1.0190
                 1.0130
                 1.0080
                 1.0060
                 1.0030
                 1.0020
                 1.0000];

CLdfTable     = [0.0000
                 0.2000
                 0.3000
                 0.4000];
 
CL0        = 0.307;                                      % Lift at zero alpha
CLalpha    = interp1(CLalphaVector,CLalphaTable,ALPHAr); % Lift due to alpha
CLalphadot = 1.700;                                      % Lift due to alpha rate
CLq        = 3.900;                                      % Lift due to pitch rate
CLde       = 0.430;                                      % Lift due to elevator deflection
CLdf       = interp1(FlapVector,CLdfTable,FLAPdeg);      % Lift due to flap deflection
% kCLge      = interp1(h_b_Vector,kCLgeTable,h_b);         % Change in lift due to ground effect
kCLge      = 1;

CL = CL0*kCLge + CLalpha*kCLge + c_bar/2/V*CLalphadot*ALPHAdot +...
    c_bar/2/V*CLq*Q + CLde*ELEVr + CLdf*kCLge;           % Lift coefficient

% figure
% plot(CLalphaVector*180/pi,CLalphaTable)
% xlabel('\alpha (deg)')
% ylabel('C_L_\alpha')
% grid



%% SIDE FORCE %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

AlphaVector = [0.0000 0.0943]'; % rad

CYbetaTable = [-0.3930
               -0.4040];

CYpTable    = [-0.0750
               -0.1450];

CYrTable    = [0.2140
               0.2670];
           
CYbeta = interp1(AlphaVector,CYbetaTable,ALPHAr); % Side force due to beta
CYp    = interp1(AlphaVector,CYpTable,ALPHAr);    % Side force due to roll rate
CYr    = interp1(AlphaVector,CYrTable,ALPHAr);    % Side force due to yaw rate
CYda   = 0.0000;                                  % Side force due to aileron
CYdr   = 0.1870;                                  % Side force due to rudder

CY = CYbeta*BETAr + b/2/V*CYp*P + b/2/V*CYr*R + CYda*AILEr + CYdr*RUDDr; % Side coefficient



%% ROLL MOMENT %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

ClbetaVector = [-0.3490 0.0000 0.3490]'; % rad

ClbetaTable = [0.0322	0.0312
               0.0000	0.0000
              -0.0322  -0.0312];

ClpTable   = [-0.4840
              -0.4870];

ClrTable   = [0.0798
              0.1869];

Clbeta = interp2(AlphaVector,ClbetaVector,ClbetaTable,ALPHAr,BETAr); % Roll moment due to beta
Clp    = interp1(AlphaVector,ClpTable,ALPHAr);                       % Roll moment due to rall rate
Clr    = interp1(AlphaVector,ClrTable,ALPHAr);                       % Roll moment due to yaw rate
Clda   = 0.15;                                                       % Roll moment due to aileron
Cldr   = -0.0147;                                                    % Roll moment due to rudder

Cl = Clbeta + b/2/V*Clp*P + b/2/V*Clr*R + Clda*AILEr + Cldr*RUDDr;     % Roll coefficient



%% PITCH MOMENT %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

CmalphaTable = [-0.6130
                -0.6500];

CmalphadotTable = [-7.2700
                   -5.5700];

CmdeTable = [-0.6220
             -0.8690];
         
CmdfTable = [0.0000
             -0.0654
             -0.0981
             -0.1140];

Cm0        = 0.0400;                                      % Pitch moment at zero alpha
Cmalpha    = interp1(AlphaVector,CmalphaTable,ALPHAr);    % Pitch moment due to alpha
Cmalphadot = interp1(AlphaVector,CmalphadotTable,ALPHAr); % Pitch moment due to alpha rate
Cmq        = -12.4000;                                    % Pitch moment due to pitch rate
Cmde       = interp1(AlphaVector,CmdeTable,ALPHAr);       % Pitch moment due to elevator deflection
Cmdf       = interp1(FlapVector,CmdfTable,FLAPdeg);       % Pitch moment due to flap deflection

Cm = Cm0 + Cmalpha*ALPHAr + c_bar/2/V*Cmalphadot*ALPHAdot +...
    c_bar/2/V*Cmq*Q + Cmde*ELEVr + Cmdf;                   % Pitch coefficient



%% YAW MOMENT %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

CnbetaTable  = [0.0587
                0.0907];

CnpTable  = [-0.0278
             -0.0649];

CnrTable  = [-0.0937
             -0.1199];

CndaTable = [-0.0216
             -0.0504];

CndrTable = [-0.0645
             -0.0805];

Cnbeta = interp1(AlphaVector,CnbetaTable,ALPHAr); % Yaw moment due to beta
Cnp    = interp1(AlphaVector,CnpTable,ALPHAr);    % Yaw moment due to roll rate
Cnr    = interp1(AlphaVector,CnrTable,ALPHAr);    % Yaw moment due to yaw rate
Cnda   = interp1(AlphaVector,CndaTable,ALPHAr);   % Yaw moment due to aileron
Cndr   = interp1(AlphaVector,CndrTable,ALPHAr);   % Yaw moment due to rudder

Cn = Cnbeta*BETAr + b/2/V*Cnp*P + b/2/V*Cnr*R + Cnda*AILEr + Cndr*RUDDr; % Yaw coefficient



%% THRUST %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Fixed-Pitch 75-inch Two-Blade Propeller

RPM = 950*THTL + 4.4*V + 740;   % Revolutions per minute
J   = V/RPM*60/D_prop;          % Advance ratio

JVector = [0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2 1.3 1.4...
    1.5 1.6 1.7 1.8 1.9 2.0 2.1 2.2 2.3 5.0]';

CTTable = [0.068
           0.068
           0.067
           0.066
           0.064
           0.061
           0.057
           0.050
           0.040
           0.029
           0.019
           0.008
           -0.001
           -0.008
           -0.019
           -0.029
           -0.040
           -0.050
           -0.057
           -0.061
           -0.064
           -0.066
           -0.067
           -0.068
           -0.068];

CT = interp1(JVector,CTTable,J);    % Thrust coefficient

% figure
% plot(JVector,CTTable)
% title('Thrust Model')
% xlabel('J')
% ylabel('C_T')
% grid
