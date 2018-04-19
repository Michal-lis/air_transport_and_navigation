clc; clear all; close all;
addpath('lib/kml','lib/geo');
lat1 = sex2dec('N040°28''20.00"');
lon1 = sex2dec('W003°33''39.00"');
lat2 = sex2dec('S033°23''77.00"');
lon2 = sex2dec('W070°47''36.00"');
%Adding LEMD Valencia and the Santiago SCEL as the begging and the end 
wp(1).name= 'LEMD';
wp(1).lat = sex2dec('N040°28''20.00"');
wp(1).lon= sex2dec('W003°33''39.00"');
wp(1).alt=0;
wp(1).desc='Airport';

wp(2).name= 'SCEL';
wp(2).lat = sex2dec('S033°23''77.00"');
wp(2).lon= sex2dec('W070°47''36.00"');
wp(2).alt=0;
wp(2).desc='Airport';

%--------------------------------------------------------------------------
attr=create_attr();

attr.label='LEVC-LEMD';
attr.labelscale=1.8;
attr.labelcolor='ffffeeee';
attr.iconurl='http://maps.google.com/mapfiles/kml/paddle/wht-circle.png';
attr.iconscale=1.5;
attr.extrude=false;
% Upper surface
attr.altmode='clampToGround';

% Edges
attr.edgewidth=2;
attr.edgecolor='ff0000ff';

% Waypoints
attr.wplabelscale=1.2;
attr.wplabelcolor='ff0000ff';
attr.wpiconurl='http://maps.google.com/mapfiles/kml/shapes/triangle.png';
attr.wpiconscale=1.0;

%Distancia
[s,a12,a21] = orto_distazi(lat1,lon1,lat2,lon2)

kmlwrite_polyline(wp,'LEVC-LEMD_greatcircle.kml',attr);
