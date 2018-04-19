function MAIN_6
% DRAW ROUTES AND FIXES IN SACTA MONITOR 

clc; clear all; close all;
addpath('SACTA','../lib/kml','../lib/geo');

%------------------------------------------------------------------
% Variables and constants
%------------------------------------------------------------------
% MONITOR PARAMETERS
MONITOR= 1;     % SACTA=1 Google_Earth = 2  Console=3;
BEAM= false;    % Paint the rorating beam on the screen. Just for fun.

%-------------------------------------------------------
% MONITOR configuration
% MONITOR = SACTA, GOOGLE EARTH, or CONSOLE
%-------------------------------------------------------
if MONITOR_Configure(MONITOR,BEAM) ~= 0
    fprintf(2,'\n Monitor not started\n');
    return;
end
fprintf(2,'------------------------------------------------\n');

% Clear routes and waypoints
lines={};
wpts=[];
status = SACTA_DisplayWaypoints(wpts);
status = SACTA_DisplayRoutes(lines);

% Draw routes and waypoints close to Valencia
[lines,wpts]=Routes();

status = SACTA_DisplayWaypoints(wpts);
status = SACTA_DisplayRoutes(lines);

end