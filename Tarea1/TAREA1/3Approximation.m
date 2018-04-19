clc; clear all; close all;
addpath('lib/kml','lib/geo');
lat(1) = sex2dec('N040°28''20.00"');
lon(1) = sex2dec('W003°33''39.00"');
lat(42) = sex2dec('S033°23''77.00"');
lon(42) = sex2dec('W070°47''36.00"');

%Compute the orthodromic course Phi=a12 and orthodromic distance D=s between ORG and DST.
[s,a12,a21] = orto_distazi(lat(1),lon(1),lat(42),lon(42))

%Numero de waypoints N (tambien el numero de itaerations)-Firstly I chose
%20 iterations but my error was 20 so I decided to take 40 iterations
%instead and my error came down to 1,54 NM. I also firstly iterated from
%i=1:N-1 and then changed it to iterating i=1:N and gave our destination
%the number 42 to calculate the distance between end of our route 41 and
%the destination 42.
N=40;

%Distancia entre waypoints, it is all the times the same = the loxo
%distance between the begging and destination devided into the number of
%iterations
d=s/N

%ORG
wp(1).name= 'LEMD';
wp(1).lat = sex2dec('N040°28''20.00"');
wp(1).lon= sex2dec('W003°33''39.00"');
wp(1).alt=0;
wp(1).desc='Airport';

%buckle para obtener los mas waypoints(we change the course Phi in each
%iteration)
for i=1:N
[lat(i+1),lon(i+1),a21]=loxo_reckon(lat(i),lon(i),d,a12);
wp(1+i).lon=lon(i+1)
wp(1+i).lat=lat(i+1)
[s,a12,a21] = orto_distazi(wp(1+i).lat,wp(1+i).lon,lat(42),lon(42))
wp(1+i).alt=38000;
end;

%Specifying the error in distance:
[error,a12,a21] = orto_distazi(wp(41).lat,wp(41).lon,lat(42),lon(42))
%Transferring the error to NM
errorNM=error/1000/1.82%The error is smaller the the desired one

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
attr.edgecolor='ffff69b4';

% Waypoints
attr.wplabelscale=1.2;
attr.wplabelcolor='fffffffff';
attr.wpiconurl='http://maps.google.com/mapfiles/kml/shapes/triangle.png';
attr.wpiconscale=1.0;

kmlwrite_polyline(wp,'LEVC-LEMD_approximation.kml',attr);