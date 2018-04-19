function levc_ctr
addpath('lib/geo','lib/kml');
ft2m=0.3048;
fl2m=ft2m*100;
nm2m=1852;
nm2km=1.852;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% VALENCIA CTR
% 394033N 0004701W;
% 393806N 0004142W;
% 394234N 0003227W; 
% arco de 6 NM de radio 393728N 0002821W (Bétera ARP);
% 393453N 0002120W; 
% 392932N 0001559W; 
% 391650N 0001629W; 
% 392238N 0003500W; 
% 393551N 0005038W; 
% 394033N 0004701W.
 
levcctr(1).lat= sex2dec('394033N');
levcctr(1).lon= sex2dec('0004701W');
levcctr(1).alt=6000*ft2m;
 
levcctr(2).lat= sex2dec('393806N');
levcctr(2).lon= sex2dec('0004142W');
levcctr(2).alt=6000*ft2m;
 
levcctr(3).lat= sex2dec('394234N');
levcctr(3).lon= sex2dec('0003227W');
levcctr(3).alt=6000*ft2m;
 
 
ctr.lat=sex2dec('393728N');
ctr.lon=sex2dec('0002821W');
 
R=6367.445;     % Radius of Earth
r=6*nm2km;      % An arch of 6 NM
phi1=-26;       % Starting angle of arch
phi2=121.1;     % Ending angle of arch
NP=25;          % Number of points of arch
 
[x,y]=circle(ctr.lon,ctr.lat,r/R,phi1,phi2,NP);
 
for i=1:NP
    levcctr(i+3).lon=x(i);
    levcctr(i+3).lat=y(i);
    levcctr(i+3).alt=6000*ft2m;
end
 
levcctr(NP+4).lat= sex2dec('393453N');
levcctr(NP+4).lon= sex2dec('0002120W');
levcctr(NP+4).alt=6000*ft2m;
 
levcctr(NP+5).lat= sex2dec('392932N');
levcctr(NP+5).lon= sex2dec('0001559W');
levcctr(NP+5).alt=6000*ft2m;
 
levcctr(NP+6).lat= sex2dec('391650N');
levcctr(NP+6).lon= sex2dec('0001629W');
levcctr(NP+6).alt=6000*ft2m;
 
levcctr(NP+7).lat= sex2dec('392238N');
levcctr(NP+7).lon= sex2dec('0003500W');
levcctr(NP+7).alt=6000*ft2m;
 
levcctr(NP+8).lat= sex2dec('393551N');
levcctr(NP+8).lon= sex2dec('0005038W');
levcctr(NP+8).alt=6000*ft2m;
 
levcctr(NP+9).lat= sex2dec('394033N');
levcctr(NP+9).lon= sex2dec('0004701W');
levcctr(NP+9).alt=6000*ft2m;

%--------------------------------------------------------------------------
attr.label='CTR';
attr.labelscale=1.5;
attr.labelcolor='ffffeeee';
attr.iconurl='http://maps.google.com/mapfiles/kml/paddle/wht-circle.png';
attr.iconscale=1.5;
attr.extrude=true;

% Upper surface
attr.color='AAff0000';
attr.fill=false;
attr.altmode='relativeToGround';

% Edges
attr.edgewidth=5;
attr.edgecolor='ffff0055';

kmlwrite_polygon(levcctr,'levcctr.kml',attr);
 
%plot(x,y);
%kmlwrite_polygon(wp,filename,color,width,fill,extrude,altmode)
%kmlwrite_polygon(levcctr,'levcctr.kml','ffff0055','3','0','1','absolute');
%kmlwrite_volume(wp,filename,height,color,width,fill,extrude,altmode)
%kmlwrite_volume(levctma,'levctma1.kml',180*fl2m,'11f00ff','1','1','0','absolute');
end