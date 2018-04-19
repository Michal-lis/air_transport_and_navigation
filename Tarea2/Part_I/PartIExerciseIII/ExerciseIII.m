clc; clear all;close all;
addpath('SACTA-matlab-v4.1/SACTA','lib/kml','lib/geo','SACTA-matlab-v4.1/tracks');
%Both tracks
%file='05-Jan-2017_Arrival_4CA4EE'; % Flight from Brussels
file='05-Jan-2017_Arrival_4CABC2'; % Flight from Cologne
tsim=0;
k=1;
WPaprox=[sex2dec('N039º24''00.00"') sex2dec('W000º10''48.00"');sex2dec('N039º24''28.00"') sex2dec('W000º16''05.00"');sex2dec('N039º26''24.00"') sex2dec('W000º20''47.00"')];
while tsim<intmax
    [traffics, tsim, real_time]=TRACK_read([file,'.txt']);
    if length(traffics)==1
        wp(k).name=num2str(k);
        wp(k).lon=traffics.lon;
        wp(k).lat=traffics.lat;
        wp(k).alt=traffics.alt;
        wp(k).desc=[' cs: ',traffics.callsign,', hex: ',traffics.hexId,', sq: ',traffics.squawk...
                     ', gs: ',num2str(traffics.gspeed),',tk: ',num2str(traffics.track),...
                     ', vr: ',num2str(traffics.vertRate)];
    end
    k=k+1;
end
d=0;
[pos,IAF,IF,FAP]=Fixes(wp,WPaprox);
for i=1:length(wp)
   latitude(i)=wp(i).lat;
   longitude(i)=wp(i).lon;
   altitude(i)=wp(i).alt;
   if i==1;
       d=0;
       s=0;
   elseif i<length(wp)
   [s,a12,a21]=orto_distazi(wp(i-1).lat,wp(i-1).lon,wp(i).lat,wp(i).lon);
   end
   d=d+s;
   distance(i)=d/1852;
   if pos(1)==i
       IAFaltitude=wp(i).alt;
       IAFd=distance(i);
   end
   if pos(2)==i
       IFaltitude=wp(i).alt;
       IFd=distance(i);
   end
   if pos(3)==i
       FAPaltitude=wp(i).alt;
       FAPd=distance(i);
   end
end


% Measuring the distances using lib/geo library
disttot=distance(end);
distance=abs(distance-disttot);
IAFdistance=abs(IAFd-disttot);
IFdistance=abs(IFd-disttot);
FAPdistance=abs(FAPd-disttot);


%Teoretical Aproximation
wp_t(1).name= 'MULAT';
wp_t(1).lat=sex2dec('N039°24''00.00"');
wp_t(1).lon=sex2dec('W000°10''48.00"');
wp_t(1).alt=3500; 
wp_t(1).desc= '';

wp_t(2).name= 'IF';
wp_t(2).lat=sex2dec('N039°24''28.00"');
wp_t(2).lon=sex2dec('W000°16''05.00"');
wp_t(2).alt=2500;
wp_t(2).desc= '';

wp_t(3).name= 'NDB 340';
wp_t(3).lat=sex2dec('N039°26''15.00"');
wp_t(3).lon=sex2dec('W000°20''47.00"');
wp_t(3).alt=2200;
wp_t(3).desc= '';

wp_t(4).name= 'FAP';
wp_t(4).lat=sex2dec('N039°26''24.00"');
wp_t(4).lon=sex2dec('W000°21''08.00"');
wp_t(4).alt=2200;
wp_t(4).desc= '';

wp_t(5).name= 'LEVC';
wp_t(5).lat=sex2dec('N039°29''03.00"');
wp_t(5).lon=sex2dec('W000°28''04.00"');
wp_t(5).alt=239.5;
wp_t(5).desc= '';

tam_t=length(wp_t);
dist_t=zeros(1,tam_t);
alt_t=zeros(1,tam_t);

for i=tam_t-1:-1:1
    dist_t(tam_t-i+1)=orto_distazi(wp_t(i+1).lat,wp_t(i+1).lon,wp_t(i).lat,wp_t(i).lon)+dist_t(tam_t-i);
    alt_t(tam_t-i)=wp_t(i+1).alt;
    lon_t(tam_t-i)=wp_t(i+1).lon;
    lat_t(tam_t-i)=wp_t(i+1).lat;
end
alt_t(end)=wp_t(1).alt;
lon_t(end)=wp_t(1).lon;
lat_t(end)=wp_t(1).lat;

% Using Matlab plots to present the profiles: 
% Cian - IAF, red - IF, blue - FAP,
% Plane view
subplot(1,2,1)
plot(longitude,latitude)
title('Plan view with key waypoints')
xlabel('longitude')
ylabel('latitude')
%THE FLIGHT DOES NOT USE IAF, although it is MULAT
hold on
%Drawing IAF as cian star
plot(sex2dec('W000º10''48.00"'),sex2dec('N039º24''00.00"'),'c*')
hold on
%Drawing IF as red star
plot(sex2dec('W000º16''05.00"'),sex2dec('N039º24''28.00"'),'r*')
hold on
%Drawing FAP as blue star
plot(FAP(2),FAP(1),'b*')

% Vertical Profile
subplot(1,2,2)
plot(distance,altitude)
title('Vertical Profile with Key Waypoints')
xlabel('distance (NM)')
ylabel('altitude (ft)')
% hold on
% %THE FLIGHT DOES NOT USE IAF
% %Drawing IAF as cian star
% plot(IAFdistance,IAFaltitude,'c*')
%Typically IAF is 1000 ft above the Runway, Valencia Airport AMSL is 240ft 
hold on 
%Drawing IF as red star
plot(IFdistance,IFaltitude,'r*')
hold on
%Drawing FAP as blue star
plot(FAPdistance,FAPaltitude,'b*')
hold on
%Drawing runway threshold as a balck star 
plot(0,0,'k*')

hold on

plot(dist_t./1852,alt_t,'LineWidth',3)
legend('Real','IF','FAP','RunwayThreshold','Teórica');
xlabel('Distancia (NM)');
ylabel('Altura (pies)');

%typically FAF is 90 feet above the runway, FAF can be determined by the
%distance to the runway threshld and the Glide Slope which is around 3
%degrees

