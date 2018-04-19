function MAIN4_dref_write_Xplane
addpath('lib/xplane');
clc; clear all; close all;
ip='127.0.0.1';
port_Xplane = 49000;

% Select datarefs to write ------------------------------------------------
dataref{1}='sim/joystick/yoke_roll_ratio';        % Ailerons
dataref{2}='sim/joystick/yoke_pitch_ratio';       % Elevators
dataref{3}='sim/joystick/yoke_heading_ratio';     % Rudder
dataref{4}='sim/flightmodel/engine/ENGN_thro[0]'; % Throttle
dataref{5}='sim/flightmodel/controls/parkbrake';  % Parkbrake
dataref{6}='sim/flightmodel/controls/flaprqst';   % Flaps
%dataref{7}='sim/flightmodel/movingparts/gear1def';% Gear
%--------------------------------------------------------------------------
try
    % Set the control actions
    values(1) = -1.0;  % [-1..1]  The deflection of the joystick axis controlling roll.
    values(2) =  0.0;  % [-1..1]  The deflection of the joystick axis controlling pitch. Use override_joystick
    values(3) = -1.0;  % [-1..1]  The deflection of the joystick axis controlling yaw.
    values(4) =  1.0;  % [0..1]   Throttle (per engine) as set by user, 0 = idle, 1 = max
    values(5) =  0.0;  % [0..1]	  Parking Brake, 1 = max.
    values(6) =  1.0;  % [0..1]   Flap positions
    % Write parameters into Xplane
    dref_writeXPLANE(ip,port_Xplane,dataref,values)
    
catch err
    rethrow(err);
end
end