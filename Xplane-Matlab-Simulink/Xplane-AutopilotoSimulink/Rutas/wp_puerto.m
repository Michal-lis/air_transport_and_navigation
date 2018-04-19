% CIRCUITO ACROBATICO
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Waypoint definition
%  wp(n).name      strg  Waypoint name
%  wp(n).long      deg   Longitude
%  wp(n).lat       deg   Latitude
%  wp(n).alt       ft    Altitude (wrt Sea level)
%  wp(n).airspeed  ft/s  True Airspeed
%  wp(n).fase      -     Phase of flight: 1=CLIMB / 2=CRUISE / 3=APPROACH


% waypoint 1
%
wp(1).name = '1';
wp(1).long = -0.30822;
wp(1).lat = 39.46245;
wp(1).alt = 2000;
wp(1).airspeed = 130;
wp(1).fase = 2;
%
% waypoint 2
%
wp(2).name = '2';
wp(2).long = -0.32892;
wp(2).lat = 39.46329;
wp(2).alt = 2200;
wp(2).airspeed = 130;
wp(2).fase = 2;
%
% waypoint 3
%
wp(3).name = '3';
wp(3).long = -0.33296;
wp(3).lat = 39.46002;
wp(3).alt = 2300;
wp(3).airspeed = 90;
wp(3).fase = 2;
%
% waypoint 4
%
wp(4).name = '4';
wp(4).long = -0.32796;
wp(4).lat = 39.45521;
wp(4).alt = 2300;
wp(4).airspeed = 90;
wp(4).fase = 2;
%
% waypoint 5
%
wp(5).name = '5';
wp(5).long = -0.31981;
wp(5).lat = 39.46197;
wp(5).alt = 2300;
wp(5).airspeed = 130;
wp(5).fase = 2;
%
% waypoint 6
%
wp(6).name = '6';
wp(6).long = -0.31189;
wp(6).lat = 39.45083;
wp(6).alt = 2250;
wp(6).airspeed = 130;
wp(6).fase = 2;
%
% waypoint 7
%
wp(7).name = '7';
wp(7).long = -0.32626;
wp(7).lat = 39.42253;
wp(7).alt = 2000;
wp(7).airspeed = 130;
wp(7).fase = 2;

NUM_WP=length(wp);
wp_next=1;
wp_prev=length(wp);