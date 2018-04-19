function [ Trayecto ] = create_simulated_trajectory(start_time, speed, wp )
% Create_simulated_trajectory Creates an array with 4D coordinates for a set of waypoints given speed and start time. 
% Speed in Knots, time in seconds
% The array created can be used as a Synthetic trace for SACTA

addpath('../geo');
[a number_of_wp]=size(wp);
Trayecto=zeros(number_of_wp,4);

Trayecto(1,:)=[wp(1).lon, wp(1).lat,wp(1).alt,start_time];
for i=2:number_of_wp
    distance=dist_haversine(wp(i-1).lon,wp(i-1).lat,wp(i).lon,wp(i).lat)/1.852; %distance in NM
    nextTime=(distance/speed)*3600; %In seconds
    Trayecto(i,:)=[wp(i).lon,wp(i).lat,wp(i).alt,nextTime+Trayecto(i-1,4)];
end

