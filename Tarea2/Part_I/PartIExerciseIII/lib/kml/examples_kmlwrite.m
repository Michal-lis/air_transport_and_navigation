function examples_kmlwrite
clc; clear all; close all;
addpath('../kml','../geo');

circle_example;
polygon_example;
volume_example

end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function circle_example
% The DMA arch of STARs in LEVC

R=6367.445;      % Radius of Earth
r=15*1.852;      % A DME arch of 15 NM
phi1=-176;       % Starting angle of DME arch
phi2=47;         % Ending angle of DME arch
NP=25;           % Number of points of arch

Manises.lat=39.489444444444445;
Manises.lon=-0.481666666666667;

[x,y]=circle(Manises.lon, Manises.lat,r/R,phi1,phi2,NP);
%plot(x,y)

for i=1:NP
    wp(i).name='';
    wp(i).desc='';
    wp(i).lon=x(i);
    wp(i).lat=y(i);
    wp(i).alt=0;
end

%--------------------------------------------------------------------------
attr=create_attr();

attr.label='ARCO DME';
attr.labelscale=1.8;
attr.labelcolor='ffffeeee';
attr.iconurl='http://maps.google.com/mapfiles/kml/paddle/wht-circle.png';
attr.iconscale=1.5;
attr.extrude=false;
% Upper surface
attr.altmode='clampToGround';

% Edges
attr.edgewidth=6;
attr.edgecolor='ff00ffff';

% Waypoints
attr.wplabelscale=.8;
attr.wplabelcolor='fffffffff';
attr.wpiconurl='http://maps.google.com/mapfiles/kml/shapes/triangle.png';
attr.wpiconscale=0.5;

kmlwrite_polyline(wp,'DME-LEVC.kml',attr);

end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function volume_example

ft2m=0.3048;
fl2m=ft2m*100;
nm2m=1852;
nm2km=1.852;

R=6367.445;      % Radius of Earth
r=6*nm2km;       % A DME arch of 6 NM
phi1=0;;         % Starting angle of DME arch
phi2=359;        % Ending angle of DME arch
NP=60;           % Number of points of arch

Manises.lat=39.489444444444445;
Manises.lon=-0.481666666666667;

[x,y]=circle(Manises.lon, Manises.lat,r/R,phi1,phi2,NP);
%plot(x,y);

for i=1:NP
    wpl(i).lon=x(i);
    wpl(i).lat=y(i);
    wpl(i).alt=1000;
end
wpl(NP+1)=wpl(1);

r=10*nm2km;       % A DME arch of 20 NM
[x,y]=circle(Manises.lon, Manises.lat,r/R,phi1,phi2,NP);
%hold on;
%plot(x,y);

for i=1:NP
    wpu(i).lon=x(i);
    wpu(i).lat=y(i);
    wpu(i).alt=6000;
end
wpu(NP+1)=wpu(1);

%--------------------------------------------------------------------------
vol_attr=create_attr();

vol_attr.label='CONO';
vol_attr.labelscale=1.8;
vol_attr.labelcolor='ffffeeee';
vol_attr.iconurl='http://maps.google.com/mapfiles/kml/paddle/wht-circle.png';
vol_attr.iconscale=1.5;
vol_attr.extrude=false;

% Upper surface
vol_attr.color='55ff0000';
vol_attr.fill=true;
vol_attr.altmode='absolute';

% Lower surface
vol_attr.color2='ff0000ff';
vol_attr.fill2=true;
vol_attr.altmode2='relativeToGround';

% Lateral surfaces
vol_attr.latcolor='ff999999';
vol_attr.latfill=true;

% Edges
vol_attr.edgewidth=1;
vol_attr.edgecolor='88ffffff';

kmlwrite_volume(wpu,wpl,'volume-ex.kml',vol_attr);
%--------------------------------------------------------------------------
end

function polygon_example

ft2m=0.3048;
fl2m=ft2m*100;
nm2m=1852;
nm2km=1.852;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% LED65 MARINES (Sagunto)
% 394700N 0003600W;
% 394700N 0003100W; 
% 394100N 0003100W; 
% 394100N 0003600W;
% 394700N 0003600W.


led65(1).lat = sex2dec('394700N');
led65(1).lon= sex2dec('0003600W');

led65(2).lat = sex2dec('394700N');
led65(2).lon= sex2dec('0003100W');

led65(3).lat = sex2dec('394100N');
led65(3).lon= sex2dec('0003100W');

led65(4).lat = sex2dec('394100N');
led65(4).lon= sex2dec('0003600W');

led65(5).lat = sex2dec('394700N');
led65(5).lon= sex2dec('0003600W');

for i=1:length(led65)
    led65(i).alt=12500*ft2m;
end

%--------------------------------------------------------------------------
attr.label='LED65';
attr.labelscale=1;
attr.labelcolor='ffffeeee';
attr.iconurl='http://maps.google.com/mapfiles/kml/paddle/wht-circle.png';
attr.iconscale=1.0;
attr.extrude=true;

% Upper surface
attr.color='225500ff';
attr.fill=true;
attr.altmode='relativeToGround'; %'clampToGround', 'relativeToGround'

% Edges
attr.edgewidth=1;
attr.edgecolor='ffffffff';

kmlwrite_polygon(led65,'led65.kml',attr);

end