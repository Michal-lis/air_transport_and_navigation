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
wp(1).name = '01';
wp(1).long = -1.263947;
wp(1).lat = 39.025123;
wp(1).alt = 8000;
wp(1).airspeed = 130;
wp(1).fase = 2;
%
% waypoint 2
%
wp(2).name = '02';
wp(2).long = -0.778388;
wp(2).lat = 39.307241;
wp(2).alt = 8000;
wp(2).airspeed = 130;
wp(2).fase = 2;
%
% waypoint 3
%
wp(3).name = '03';
wp(3).long = -0.693727;
wp(3).lat = 39.296522;
wp(3).alt = 7000;
wp(3).airspeed = 130;
wp(3).fase = 2;
%
% waypoint 4
%
wp(4).name = '04';
wp(4).long = -0.633559;
wp(4).lat = 39.269310;
wp(4).alt = 6000;
wp(4).airspeed = 130;
wp(4).fase = 2;
%
% waypoint 5
%
wp(5).name = '05';
wp(5).long = -0.504508;
wp(5).lat = 39.235085;
wp(5).alt = 5000;
wp(5).airspeed = 130;
wp(5).fase = 2;
%
% waypoint 6
%
wp(6).name = '06';
wp(6).long = -0.297506;
wp(6).lat = 39.280322;
wp(6).alt = 4500;
wp(6).airspeed = 130;
wp(6).fase = 2;
%
% waypoint 7
%
wp(7).name = '07';
wp(7).long = -0.180685;
wp(7).lat = 39.395421;
wp(7).alt = 4000;
wp(7).airspeed = 130;
wp(7).fase = 2;

%
% waypoint 8
%
wp(8).name = '08';
wp(8).long = -0.062112;
wp(8).lat = 39.412050;
wp(8).alt = 3500;
wp(8).airspeed = 130;
wp(8).fase = 2;

%
% waypoint 9
%
wp(9).name = '09';
wp(9).long = -0.180685;
wp(9).lat = 39.39;
wp(9).alt = 3500;
wp(9).airspeed = 130;
wp(9).fase = 3;

%
% waypoint 10
%
wp(10).name = '10';
wp(10).long = -0.215836;
wp(10).lat = 39.378324;
wp(10).alt = 2500;
wp(10).airspeed = 100;
wp(10).fase = 3;

%
% waypoint 11
%
wp(11).name = '11';
wp(11).long = -0.271585;
wp(11).lat = 39.400415;
wp(11).alt = 2500;
wp(11).airspeed = 90;
wp(11).fase = 3;

%
% waypoint 12
%
wp(12).name = '12';
wp(12).long = -0.367121;
wp(12).lat = 39.438312;
wp(12).alt = 2200;
wp(12).airspeed = 90;
wp(12).fase = 3;


%
% waypoint 13
%
wp(13).name = '13';
wp(13).long = -0.470481;
wp(13).lat = 39.485056;
wp(13).alt = 240;
wp(13).airspeed = 60;
wp(13).fase = 3;

NUM_WP=length(wp);
wp_next=1;
wp_prev=length(wp);