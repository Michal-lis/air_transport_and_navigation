function MAIN2_write_Xplane
addpath('lib/xplane');
clc; clear all; close all;
xp_ip='127.0.0.1';
xp_port_in = 9005;

try
    actions=create_actionsXPLANE();
    % Set the control actions
    actions.ailerons = -1.0;  % [-1..1]	The deflection of the joystick axis controlling roll.
    actions.rudder   = -1.0;  % [-1..1]	The deflection of the joystick axis controlling yaw.
    actions.throttle =  0.0;  % Throttle (per engine) as set by user, 0 = idle, 1 = max
    actions.elevators=  0.0;  % [-1..1]	The deflection of the joystick axis controlling pitch. Use override_joystick
    actions.brake    =  1.0;  % [0..1]	Parking Brake, 1 = max.
    actions.flaps    =  1.0;  % [0..1] Flap positions
    
    % Write parameters into Xplane
    writeXPLANE(xp_ip,xp_port_in,actions);
    
catch err
    rethrow(err);
end
end




