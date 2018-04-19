% ATERRIZAJE EN LEVC RWY 30
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Waypoint definition
%  wp(n).name      strg  Waypoint name
%  wp(n).long      deg   Longitude
%  wp(n).lat       deg   Latitude
%  wp(n).alt       ft    Altitude (wrt Sea level)
%  wp(n).fase      -     Phase of flight: 1=CLIMB / 2=CRUISE / 3=APPROACH
% Waypoint optional fields
%  wp(n).airspeed  kt    True Airspeed
%  wp(n).flyby     -     RNAV mode: 0=FLY-OVER (default setting) / 1=FLY-BY


% waypoint 1
k=1;
%
wp(k).name = '1';
wp(k).long = -0.17778;
wp(k).lat = 39.37417;
wp(k).alt = 5000;
wp(k).airspeed = 100;
wp(k).fase = 2;
%
% waypoint 2
k=k+1;
%
wp(k).name = '2';
wp(k).long = -0.26806;
wp(k).lat = 39.40778;
wp(k).alt = 3575;
wp(k).airspeed = 100;
wp(k).fase = 3;
%
% waypoint 3
k=k+1;
%
wp(k).name = '3';
wp(k).long = -0.35222;
wp(k).lat = 39.44000;
wp(k).alt = 2200;
wp(k).airspeed = 100;
wp(k).fase = 3;
%
% waypoint 4
k=k+1;
%
wp(k).name = '4';
wp(k).long = -0.47137;
wp(k).lat = 39.48540;
wp(k).alt = 170;
wp(k).airspeed = 80;
wp(k).fase = 3;
%
% waypoint 5
k=k+1;
%
wp(k).name = '5';
wp(k).long = -0.49842;
wp(k).lat = 39.49570;
wp(k).alt = 170;
wp(k).airspeed = 0;
wp(k).fase = 3;

NUM_WP=length(wp);
wp_next=1;
wp_prev=length(wp);