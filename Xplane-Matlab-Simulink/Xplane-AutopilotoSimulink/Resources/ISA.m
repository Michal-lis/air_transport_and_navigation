function [q_bar, MACH, rho, g] = ISA(h,V)
% Atmosfera ISA
% Inputs ********
%   h      Altitud [ft]
%   V      Velocidad [ft/s]
% Outputs ********
%   q_bar  Presion dinamica [psf]
%   MACH   Numero de Mach
%   rho    Densidad atmosferica [lb/ft^3]
%   g      Gravedad [ft/s^2]


h = h*0.3048;   % (ft to m)
V = V*0.3048;   % (ft/s to m/s)

g0 = 9.81;  % Aceleracion de la gravedad [m/s^2]
R  = 287;   % Constante de los gases [m^2/(s^2·K)]

if h <= 11000
    % Troposfera
    T0   = 288.15;  % Temperatura al nivel del suelo [K]
    p0   = 101325;  % Presion al nivel del suelo [Pa=N/m^2]
    rho0 = 1.225;   % Densidad al nivel del suelo [Kg/m^3]
    Th   = -0.0065; % Gradiente termico [K/m]

    T_atm   = T0+Th*h;
    p_atm   = p0*(1+Th/T0*h)^(-g0/R/Th);
    rho_atm = rho0*(1+Th/T0*h)^(-g0/R/Th-1);
else
    % Estratosfera
    T11000   = 216.65;  % Temperatura a 11000 m [K]
    p11000   = 22630;   % Presion a 11000 m [Pa]
    rho11000 = 0.3636;  % Densidad a 11000 m [Kg/m^3]
    Th       = 0;       % Gradiente termico [K/m]
    
    T_atm   = T11000;
    p_atm   = p11000*exp(-g0/R/T11000*(h-11000));
    rho_atm = rho11000*exp(-g0/R/T11000*(h-11000));
end

a     = sqrt(1.4*R*T_atm);  % Velocidad del sonido [m/s]
MACH  = V/a;                % Numero de Mach
q_bar = .5*rho_atm*V^2;     % Presion dinamica [Pa]

% Conversion de unidades
q_bar = q_bar/g0*0.2048161; % (Pa to psf)
g     = g0*3.2808;          % (m/s^2 to ft/s^2)
rho   = rho_atm*0.06242796; % (kg/m^3 to lb/ft^3)
