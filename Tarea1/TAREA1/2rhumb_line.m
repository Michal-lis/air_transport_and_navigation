clc; clear all; close all;
addpath('lib/kml','lib/geo');
lat(1) = sex2dec('N040°28''20.00"');
lon(1) = sex2dec('W003°33''39.00"');
lat(2) = sex2dec('S033°23''77.00"');
lon(2) = sex2dec('W070°47''36.00"');

%Distancia loxodromica s
[s,a12,a21]=loxo_distazi(lat(1),lon(1),lat(2),lon(2))

%Numero de waypoints N
N=12;

%Distancia entre waypoints
dis=s/N

%Primero waypoint
wp(1).name= 'LEMD';
wp(1).lat = sex2dec('N040°28''20.00"');
wp(1).lon= sex2dec('W003°33''39.00"');
wp(1).alt=0;
wp(1).desc='Airport';

%buckle para obtener los mas waypoints
for i=1:N
[lat(i+1),lon(i+1),a21]=loxo_reckon(lat(i),lon(i),dis,a12);
wp(1+i).lon=lon(i+1);
wp(1+i).lat=lat(i+1);
wp(1+i).alt=38000;%I add the altitude of 38000feet everywhere
end;


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
attr.edgecolor='ffff0000';

% Waypoints
attr.wplabelscale=1.2;
attr.wplabelcolor='fffffffff';
attr.wpiconurl='http://maps.google.com/mapfiles/kml/shapes/triangle.png';
attr.wpiconscale=1.0;

kmlwrite_polyline(wp,'LEVC-LEMD_rhumbline.kml',attr);