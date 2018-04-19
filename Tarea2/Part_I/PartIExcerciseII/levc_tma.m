function levc_tma
addpath('lib/geo','lib/kml');
ft2m=0.3048;
fl2m=ft2m*100;
nm2m=1852;
nm2km=1.852;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%VALENCIA TMA
%400000N 0000000E/W; 
%391500N 0002900E; 
%383000N 0002900E; 
%380000N 0001000E; 
%380000N 0002000W; 
%380700N 0002800W; 
%380700N 0005200W; 
%385000N 0012000W; 
%390900N 0011500W; 
%393400N 0013900W; 
%400000N 0012200W; 
%400000N 0000000E/W.
%- FL 245 / MAX ALT Sector VFR-Límite superior / Upper limit Area 1 y/and Area 2
%- FL 245 / FL 195 .......................................... C
%- FL 195 / MAX ALT Sector VFR - Límite superior/Upper limit Area 1 y/and Area 2...... E
%- Área 1: FL 195 / MAX ALT Sectores VFR/VFR sectors-Límite superior/Upper limit CTR .. D

levctma(1).lat= sex2dec('400000N');
levctma(1).lon= sex2dec('0000000E');
levctma(1).alt=195*fl2m;

levctma(2).lat= sex2dec('391500N');
levctma(2).lon= sex2dec('0002900E');
levctma(2).alt=195*fl2m;

levctma(3).lat= sex2dec('383000N');
levctma(3).lon= sex2dec('0002900E');
levctma(3).alt=195*fl2m;

levctma(4).lat= sex2dec('380000N');
levctma(4).lon= sex2dec('0001000E');
levctma(4).alt=195*fl2m;

levctma(5).lat= sex2dec('380000N');
levctma(5).lon= sex2dec('0002000W');
levctma(5).alt=195*fl2m;

levctma(6).lat= sex2dec('380700N');
levctma(6).lon= sex2dec('0002800W');
levctma(6).alt=195*fl2m;

levctma(7).lat= sex2dec('380700N');
levctma(7).lon= sex2dec('0005200W');
levctma(7).alt=195*fl2m;

levctma(8).lat= sex2dec('385000N');
levctma(8).lon= sex2dec('0012000W');
levctma(8).alt=245*fl2m;

levctma(9).lat= sex2dec('390900N');
levctma(9).lon= sex2dec('0011500W');
levctma(9).alt=195*fl2m;

levctma(10).lat= sex2dec('393400N');
levctma(10).lon= sex2dec('0013900W');
levctma(10).alt=195*fl2m;

levctma(11).lat= sex2dec('400000N');
levctma(11).lon= sex2dec('0012200W');
levctma(11).alt=195*fl2m;

levctma(12).lat= sex2dec('400000N');
levctma(12).lon= sex2dec('0000000E');
levctma(12).alt=195*fl2m;

%--------------------------------------------------------------------------
attr.label='TMA';
attr.labelscale=1.5;
attr.labelcolor='ffffeeee';
attr.iconurl='http://maps.google.com/mapfiles/kml/paddle/wht-circle.png';
attr.iconscale=1.5;
attr.extrude=true;

% Upper surface
attr.color='AAff0000';
attr.fill=false;
attr.altmode='absolute';

% Edges
attr.edgewidth=3;
attr.edgecolor='ffff0055';

kmlwrite_polygon(levctma,'levctma.kml',attr);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Área 1:
% 395132N 0004853W;
% 394604N 0004247W; 
% arco de 20 NM de radio centrado en / 20 NM radius arc centred on VOR/DME VLC; 
% 393238N 0005426W; 
% 393448N 0010305W;
% arco de 27 NM de radio centrado en / 27 NM radius arc centred on VOR/DME VLC; 
% 395132N 0004853W. *Ver/See AD 2-LEVC VAC 1.1 y/and 2.1
% 392908.3N 0002859.0W

levctma1(1).lat= sex2dec('395132N');
levctma1(1).lon= sex2dec('0004853W');

levctma1(2).lat= sex2dec('394604N');
levctma1(2).lon= sex2dec('0004247W');

vor.lat=sex2dec('392908.3N');
vor.lon=sex2dec('0002859.0W');

R=6367.445;     % Radius of Earth
r=20*nm2km;     % An arch of 20 NM
phi1=-32.2;     % Starting angle of arch
phi2=279.95;     % Ending angle of arch
NP=25;          % Number of points of arch

[x,y]=circle(vor.lon,vor.lat,r/R,phi1,phi2,NP);

for i=1:NP
    levctma1(i+2).lon=x(i);
    levctma1(i+2).lat=y(i);
end

levctma1(NP+3).lat= sex2dec('393238N');
levctma1(NP+3).lon= sex2dec('0005426W');

levctma1(NP+4).lat= sex2dec('393448N');
levctma1(NP+4).lon= sex2dec('0010305W');


r=27*nm2km;   % An arch of 6 NM
phi1=281.96;  % Starting angle of arch
phi2=325.5;   % Ending angle of arch
NP2=10;       % Number of points of a

[x,y]=circle(vor.lon,vor.lat,r/R,phi1,phi2,NP2);

for i=1:NP2
    levctma1(i+NP+4).lon=x(i);
    levctma1(i+NP+4).lat=y(i);
end

for i=1:length(levctma1)
    levctma1(i).alt=195*fl2m;
end

%--------------------------------------------------------------------------
attr.label='TMA - area 1';
attr.labelscale=1;
attr.labelcolor='ffffeeee';
attr.iconurl='http://maps.google.com/mapfiles/kml/paddle/wht-circle.png';
attr.iconscale=1.5;
attr.extrude=true;

% Upper surface
attr.color='AAff0000';
attr.fill=false;
attr.altmode='relativeToGround';

% Edges
attr.edgewidth=3;
attr.edgecolor='ffff00ff';

kmlwrite_polygon(levctma1,'levctma1.kml',attr);

end