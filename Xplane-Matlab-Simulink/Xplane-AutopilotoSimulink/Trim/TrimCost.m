function f = TrimCost(ParamOpt)

% Vector de estado ampliado
%   x(1), x(2), x(3): Componentes de velocidad (sistema cuerpo)
%   x(4), x(5), x(6): Velocidades angulares (sistema cuerpo)
%   x(7), x(8), x(9): Ángulos de Euler (sistema inercial)
%
% Vector de control ampliado
%   u(1) Elevator angle (rad)
%   u(2) Left aileron angle (rad)
%   u(3) Rudder angle (rad)
%   u(4) Throttle (%)
%   u(5) Flap angle (deg)


global airspeed_trim pitchrate_trim vpath_trim FLAPdeg x u ALPHAr BETAr elevators_max elevators_min

% Valores limite de las variables de control

if ParamOpt(1) > elevators_max
    ParamOpt(1) = elevators_max;
elseif ParamOpt(1) < elevators_min
    ParamOpt(1) = elevators_min;
end

ParamOpt(2) = min(ParamOpt(2), 1);

% Variables de estado y control para EdM Lateral %%%%%%%%%%%%%%%%%%%%%%%%%%

BETAr  = 0;                  % Sideslip angle [rad]
P      = 0;                  % Roll rate [rad/s]
R      = 0;                  % Yaw rate [rad/s]
PHIr   = 0;                  % Roll angle [rad]
PSIr   = 0;                  % Yaw angle [rad]
AILEr  = 0;                  % Left aileron angle [rad]
RUDDr  = 0;                  % Rudder angle [rad]

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

ALPHAr = ParamOpt(3)-vpath_trim;     % Ángulo de ataque [rad]

x(1) = airspeed_trim*cos(ALPHAr)*cos(BETAr); % ub
x(2) = airspeed_trim*sin(BETAr);             % vb
x(3) = airspeed_trim*sin(ALPHAr)*cos(BETAr); % wb
x(4) = P;
x(5) = pitchrate_trim;
x(6) = R;
x(7) = PHIr;
x(8) = ParamOpt(3);
x(9) = PSIr;
    
u(1) = ParamOpt(1);
u(2) = AILEr;
u(3) = RUDDr;
u(4) = ParamOpt(2);
u(5) = FLAPdeg;
    
xdot = EoM(x,u);

f = xdot(1)^2 + xdot(3)^2 + xdot(5)^2 + xdot(8)^2;  % Función coste