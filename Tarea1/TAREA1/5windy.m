clc; clear all; close all;
addpath('lib/kml','lib/geo');
fp=xml2struct('LEMDSCEL_XML_1474620942');
%Waypoints
for i=1:73
    wp(i).name = fp.OFP.navlog.fix{1, i}.ident.Text
    wp(i).lat = str2num(fp.OFP.navlog.fix{1, i}.pos_lat.Text)
    wp(i).lon = str2num(fp.OFP.navlog.fix{1, i}.pos_long.Text)
    wp(i).alt = str2num(fp.OFP.navlog.fix{1, i}.altitude_feet.Text)
    wp(i).desc = fp.OFP.navlog.fix{1, i}.name.Text
    wp(i).dist=str2num(fp.OFP.navlog.fix{1,i}.distance.Text);
    wp(i).track=str2num(fp.OFP.navlog.fix{1,i}.track_true.Text);
    wp(i).wind_dir=str2num(fp.OFP.navlog.fix{1,i}.wind_dir.Text);
    wp(i).wind_spd=str2num(fp.OFP.navlog.fix{1,i}.wind_spd.Text);
end;
%%I make another buckle for calculating the Ground speed using the Triangle
%%method
for i=1:73
%Data
wind_dir=wp(i).wind_dir; %deg (TO)
wind_spd=wp(i).wind_spd; %kt
if (1<=i<=6) || (67<=i<=73)
    tas=250; %kt
else 
    tas=450;
end
DesiredCourse=wp(i).track; %deg
wta= DesiredCourse - wind_dir;

%Wind correction angle
wca=asind(wind_spd*sind(wta)/tas); %deg

%Heading angle
heading=DesiredCourse+wca; %deg

%Tail wind
tail_wind=wind_spd*cosd(wta); %knot

%Ground-speed
wp(i).gs=tas*cosd(wca)+tail_wind; %knot 
end

% --------------------------------------------------------------------------
attr=create_attr();

attr.label='LEVC-LEMD';
attr.labelscale=1.8;
attr.labelcolor='ff00ff00';
attr.iconurl='http://maps.google.com/mapfiles/kml/paddle/wht-circle.png';
attr.iconscale=1.5;
attr.extrude=false;
% Upper surface
attr.altmode='clampToGround';

% Edges
attr.edgewidth=2;
attr.edgecolor='ffffff00';

% Waypoints
attr.wplabelscale=1.2;
attr.wplabelcolor='fffffffff';
attr.wpiconurl='http://maps.google.com/mapfiles/kml/shapes/triangle.png';
attr.wpiconscale=1.0;

kmlwrite_polyline(wp,'LEVC-LEMD_LIDO_windy.kml',attr);