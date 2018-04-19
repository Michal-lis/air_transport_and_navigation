% Cpa Time Evolution
clc; clear all;
addpath('SACTA-matlab-v4.1/SACTA','lib/kml','lib/geo','SACTA-matlab-v4.1/tracks');
file1='first';
file2='second2';
tsim=0;
k=1; %initial k value
while tsim<intmax
[traffics, tsim, real]=TRACK_read([file1,'.txt']); % Reading the first track
if length(traffics)==1
   wp1.lon(k)=traffics.lon;%geo data
   wp1.lat(k)=traffics.lat;
   wp1.track(k)=traffics.track;
   wp1.gspeed(k)=traffics.gspeed;
   hours=str2num(real(1:2));%time value conversion
   minuts=str2num(real(4:5));
   sec=str2num(real(7:end));
   realhour1(k)=hours*3600+minuts*60+sec;%real value of time
end
  k=k+1;
end
tsim=0;
k=1;
while tsim<intmax
[traffics, tsim, real]=TRACK_read([file2,'.txt']);% Reading the second track
if length(traffics)==1
   wp2.lon(k)=traffics.lon;
   wp2.lat(k)=traffics.lat;
   wp2.track(k)=traffics.track;    
   wp2.gspeed(k)=traffics.gspeed;
   hours=str2num(real(1:2));
   minuts=str2num(real(4:5));
   sec=str2num(real(7:end));
   realhour2(k)=hours*3600+minuts*60+sec;
 end
  k=k+1;
end

a=length(wp1.lat);
b=length(wp2.lat);
c=min([a b]);
%Geographical data
lat1=wp1.lat(1:c);
lat=wp2.lat(1:c);
lon1=wp1.lon(1:c);
lon=wp2.lon(1:c);

%Tracks
track1=wp1.track(1:c);
track=wp2.track(1:c);

%Groundspeeds
gspeed1=wp1.gspeed(1:c);
gspeed=wp2.gspeed(1:c);
% r - Relative distance
r=[];
% c - Relative speed
c=[];
% speeds
v1=[];
v2=[];
rmtrue=[];
dcpa=[];
tau=[];
for i=1:length(lat1)%main calculating buckle
    
   %Using loxo_distazi to get distance
   [d,a12,a21]=loxo_distazi(lat1(i),lon1(i),lat(i),lon(i));
   %Conversion to feet
   dft(i)=d*3.28084;
   r=[r;d*sind(a12)*3.28084 d*cosd(a12)*3.28084 0];
   
   %Calculating speeds of aircraft 1 and 2
   v1=[v1;wp1.gspeed(i)*sind(wp1.track(i)) wp1.gspeed(i)*cosd(wp1.track(i)) 0];
   v2=[v2;wp2.gspeed(i)*sind(wp2.track(i)) wp2.gspeed(i)*cosd(wp2.track(i)) 0];
   %conversion to knots
   c=(v2-v1)*1.68781;
   
   %Using cpa3d function
   [rm,dcpan,taun]=cpa3d(r(i,:),c(i,:));
   dcpa=[dcpa,dcpan];
   tau=[tau,taun];
   rmtrue=[rmtrue;rm];
end

%Drawing graphics in Matlab
s=1;
while tau(s)>0
    s=s+1;
end

s=s-1;
difference=linspace(0,tau(1),s);
%Time
x=difference(1:s);

%CPA predicted distance
subplot(4,1,1)
y=dcpa(1:s);%RA-2.1NM=12 759,8 ft, TA-3.3NM=20 051,2ft
plot(x,y,'r') 
legend('CPA predicted distance')

%CPA predicted time
tau=tau(1:s);
subplot(4,1,2)%RA-25sec, TA-40sec
plot(x,tau,'r')
legend('CPA predicted time')
hold on


%distance
dft=dft(1:s);
subplot(4,1,3)
plot(x,dft,'r')
legend('distance')

%First aircraft track
track1=track1(1:s);
subplot(4,1,4)
plot(x,track1,'r')
legend('aircraft 1 track')

figure
%CPA predicted time RA-25sec, TA-40sec
tau=tau(1:s);
plot(x,tau,'r')
hold on
plot(x,x*40./x,'b')
hold on
plot(x,x*25./x,'k')
legend('CPA predicted time','Traffic advisory','Resolution advisroy')
hold on

figure
%CPA predicted distance RA-2.1NM=12 759,8 ft, TA-3.3NM=20 051,2ft
y=dcpa(1:s);
plot(x,y,'r') 
hold on
plot(x,x*20051./x,'b')
hold on
plot(x,x*12759./x,'k')
legend('CPA predicted distance','Traffic advisory','Resolution advisroy')
hold on

figure
for i=1:s           %Buckle for calculating the position for each aircraft.
    distance=gspeed1(i)*tau(i)*0.5144;
    [latpla(i),lonpla(i),a21]=loxo_reckon(lat1(i),lon1(i),distance,track1(i));
    distance2=gspeed(i)*tau(i)*0.5144;
    [latcpa(i),loncpa(i),a21]=loxo_reckon(lat(i),lon(i),distance2,track(i));
end
plot(lon1(1:s),lat1(1:s))   
xlabel('Longitude')
ylabel('Latitude')
hold on
plot(lon(1:s),lat(1:s),'c')
hold on
plot(loncpa(1:s),latcpa(1:s),'g')
hold on 
plot(lonpla(1:s),latpla(1:s),'r')
