function actions=create_actionsXPLANE()
% Create an actions structure for sending controlling actions to Xplane. 
% The initial values are -10, which are intentionally out of range.
% Out of range values are ignored by writeXPLANE.
actions.ailerons = -10;
actions.elevators = -10;
actions.rudder = -10;
actions.throttle = -10;  
actions.brake = -10;    
actions.flaps = -10;
actions.gear = -10;
end