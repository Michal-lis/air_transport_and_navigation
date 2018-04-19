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
wp(1).long = -0.3433479640955461;
wp(1).lat = 39.47617517913698;
wp(1).alt = 2000;
wp(1).airspeed = 110;
wp(1).fase = 2;
%
% waypoint 2
%
wp(2).name = '2';
wp(2).long = -0.393371992798961;
wp(2).lat = 39.49441314693721;
wp(2).alt = 2200;
wp(2).airspeed = 110;
wp(2).fase = 2;
%
% waypoint 3
%
wp(3).name = '3';
wp(3).long = -0.4247864995548334;
wp(3).lat = 39.46697617181595;
wp(3).alt = 1900;
wp(3).airspeed = 90;
wp(3).fase = 2;
%
% waypoint 4
%
wp(4).name = '4';
wp(4).long = -0.3765799123323199;
wp(4).lat = 39.47371278967555;
wp(4).alt = 1900;
wp(4).airspeed = 90;
wp(4).fase = 2;
%
% waypoint 5
%
wp(5).name = '5';
wp(5).long = -0.3255460333491567;
wp(5).lat = 39.43830818087397;
wp(5).alt = 2300;
wp(5).airspeed = 110;
wp(5).fase = 2;
%
% waypoint 6
%
wp(6).name = '5';
wp(6).long = -0.3839894986742187;
wp(6).lat = 39.46462328398225;
wp(6).alt = 2300;
wp(6).airspeed = 110;
wp(6).fase = 2;

NUM_WP=length(wp);
wp_next=1;
wp_prev=length(wp);