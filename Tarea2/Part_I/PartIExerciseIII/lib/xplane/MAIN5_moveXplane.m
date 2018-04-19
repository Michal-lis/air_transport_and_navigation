function MAIN5_moveXplane
addpath('lib/xplane');

clc; clear all; close all;
ip='127.0.0.1';
port_Xplane = 49000;
try
    % Set the position and initial control actions
    plane=0;                   % uint32 - plane index. Use 0 for main plane
    position.lat =39.4963;     % double - latitude in degrees of desired position
    position.lon =-0.4999;     % double - longitude in degrees of desired position
    position.alt =73.8389;     % double - elevation in feet of desired position
    eulers.heading = 115.8;    % single - heading in degrees at desired position
    eulers.pitch = 2.5;        % single - pitch in degrees at desired position
    eulers.roll  = 0.158;      % single - roll in degrees at desired position
    controls.gear = 1;         % single [0..1] - value of gear at desired position
    controls.flaps = 0;        % single [0..1] - value of flaps at desired position
    controls.throttle = 0.0;   % single [0..1] - value of thrust at desired position
    
    % Move plane 0 in Xplane
    moveXPLANE(ip, port_Xplane, plane, position, eulers, controls);
    
catch err
    rethrow(err);
end
end