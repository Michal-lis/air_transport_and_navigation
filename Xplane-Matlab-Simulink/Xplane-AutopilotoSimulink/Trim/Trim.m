function [xTrim, uTrim, exitflag] = Trim(FASE, V_N, h_ft, vpath)

% CALCULO CONDICIONES DE TRIM PARA VUELO A V_N y h_ft %%%%%%%%%%%%%%%%%%%%%

global airspeed_trim pitchrate_trim vpath_trim FLAPdeg q_bar rho g

% run c172Model

airspeed_trim  = V_N;       % True airspeed (ft/s)
altitude_trim  = h_ft;      % Altitude (ft)
pitchrate_trim = 0;         % Pitch rate (rad/s)
vpath_trim     = vpath;     % Flight path angle (rad)

FLAPvec = [10 0 30];        % Flap position vector
FLAPdeg = FLAPvec(FASE);    % Flap position (deg)


% Flight Condition Data %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

[q_bar, MACH, rho, g] = ISA(altitude_trim,airspeed_trim);


% Minimiza del vector {ParamOpt} de componentes: %%%%%%%%%%%%%%%%%%%%%%%%%%
%	1 = ELEV [rad]
%	2 = THTL [%]
%	3 = THETA [rad]

ELEVr    = 5*0.0175;            % Initial elevator angle [rad]
THTLvec  = [1 0.4 0];           % Initial throttle setting vector
THTL     = THTLvec(FASE);       % Initial throttle setting [%/100]
THETA_Nr = vpath + 4*0.0175;    % Initial pitch [rad]

ParamIni = [ELEVr THTL THETA_Nr];
[ParamOpt,f,exitflag,output] = fminsearch('TrimCost', ParamIni);
    
% Vector de estado y de control trimado
    
if exitflag == 1
    xTrim(1) = airspeed_trim;
    xTrim(2) = ParamOpt(3);
    xTrim(3) = pitchrate_trim;
    xTrim(4) = vpath_trim;

    uTrim(1) = ParamOpt(1);
    uTrim(2) = ParamOpt(2);

else
    xTrim(1) = airspeed_trim;
    xTrim(2) = 1*0.0175;
    xTrim(3) = pitchrate_trim;
    xTrim(4) = vpath_trim;

    uTrim(1) = 0;
    uTrim(2) = 0.5;
end
