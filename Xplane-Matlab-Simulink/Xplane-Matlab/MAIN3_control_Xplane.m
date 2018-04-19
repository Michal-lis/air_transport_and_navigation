function MAIN3_control_Xplane
addpath('lib/xplane');
clc; clear all; close all;
xp_ip='127.0.0.1';
xp_port_out=49000;
xp_port_in = 9005;

try
    PHASE=1;
    brake=0;
    
    % Set initial control actions
    actions.throttle = 1;   % Throttle (per engine) as set by user, 0 = idle, 1 = max
    actions.rudder   = 0; % [-1..1]	The deflection of the joystick axis controlling yaw.
    actions.ailerons = 0;   % [-1..1]	The deflection of the joystick axis controlling roll.
    actions.elevators = 0;  % [-1..1]	The deflection of the joystick axis controlling pitch. Use override_joystick
    actions.brake    = 0;   % [0..1]	Parking Brake, 1 = max.
    actions.flaps    = 0;   % [0..1]    Flap positions
    
    writeXPLANE(xp_ip,xp_port_in, actions);
    pause(0.1);
    
    while (brake==0)
        t0=tic;
        % Read parameters into Xplane
        [data]=readXPLANE(xp_port_out);
        brake=data.brake;
        
        switch PHASE
            case 1
                [actions,PHASE]=rollout(data);
            case 2
                [actions,PHASE]=rotate(data);
            case 3
                [actions,PHASE]=climb(data);
            case 4
                [actions,PHASE]=cruise(data);
        end
        
        
        clc;
        fprintf('PHASE: %g\n',PHASE);
        fprintf('Ailerons: %g, Rudder: %g, Elevators: %g, Throttle: %g, Brake: %g\n',actions.ailerons,actions.rudder,actions.elevators,actions.throttle,brake);
        
        % Write parameters into Xplane
        writeXPLANE(xp_ip,xp_port_in, actions);
        delay=0.2-toc(t0);
        pause(delay);
        %fprintf('delay: %g\n',delay);
    end
    
catch err
    rethrow(err);
end
end

%--------------------------------------------------------------------------
function [actions,PHASE]=rollout(data)
DTK=119;

error_h=DTK-data.eulers.heading;

actions.elevators=0;
actions.ailerons=0;
actions.rudder=controlP(error_h, 0.03, -1, 1);
actions.throttle=1;
actions.flaps=0.0;

%if data.rpm > 2000
actions.brake=0;
%end

if data.ias>80
    PHASE=2;
else
    PHASE=1;
end
end

%--------------------------------------------------------------------------
function [actions,PHASE]=rotate(data)
DTK=120;

%TODO########################
actions=create_actionsXPLANE();
end

%--------------------------------------------------------------------------
function [actions,PHASE]=climb(data)
DTK=140;
Vtarget=90;

%TODO########################
actions=create_actionsXPLANE();
end

%--------------------------------------------------------------------------
function [actions,PHASE]=cruise(data)
DTK=90;
Vtarget=100;

%TODO########################
actions=create_actionsXPLANE();
end

%--------------------------------------------------------------------------
%--------------------------------------------------------------------------

function action=controlP(err, Kp, minv, maxv)
action=Kp*err;
action=min(maxv,action);
action=max(minv,action);
end

function roll=computeRoll(delta_h,Kp,tas, minv, maxv)
KTS2MS=0.514444;
omega=3*pi/180;
roll=atan2d(tas*KTS2MS*omega,9.8);
roll=roll*delta_h*Kp;
roll=min(maxv,roll);
roll=max(minv,roll);
end