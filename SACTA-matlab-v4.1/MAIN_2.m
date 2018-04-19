function MAIN_2
% SAVE FLIGHT TRACKS IN A FILE

clc; clear all; close all;
addpath('SACTA','../lib/kml','../lib/geo');

%------------------------------------------------------------------
% Variables and constants
%------------------------------------------------------------------
%% ANTENNA PARAMETERS
ANTENNA='ip';       % SELECT ANTENNA
IP_FILE='158.42.40.150'; % IP of the host with the antenna
PORT=2220;          % Port of the antenna host
PROTOCOL= 3;        % TCP(char)=3 UDP(char)=4 
%                   % Multicast=2 IP_FILE='226.1.1.1' PORT=2221

%% SIMULATION FILES
%ANTENNA='file';    % SELECT FILE
%IP_FILE = 'scenario3.mat';                     %SYNTHETIC TRACE
%IP_FILE = 'SSRtracks_2015_enero_29-05-44.txt'; %RECORDED SCENARIO
%PORT ='';
%PROTOCOL=0;
%
SIM_SPEED = 1;      % Factor used to accelerate simulation traces
%
%% MONITOR PARAMETERS
MONITOR= 1;    % SACTA=1 Google_Earth = 2  Console=3;
BEAM= true;    % Paint the rotating beam on the screen. Just for fun.
               % It does not affect real-time transponder antenna
t=0;           % Time elapsed since the beginning of the program
TMAX=2000;     % Max (real or simulated) time executing the program

%------------------------------------------------------------------
% ANTENNA configuration
% Set traffic_data_source = ANTENNA_IP or TRACE_FILE  .mat
%------------------------------------------------------------------     
ANTENNA_Configure(ANTENNA,SIM_SPEED,IP_FILE,PROTOCOL,PORT); 

%-------------------------------------------------------
% MONITOR configuration
% MONITOR = SACTA, GOOGLE EARTH, or CONSOLE
%-------------------------------------------------------
if MONITOR_Configure(MONITOR,BEAM) ~= 0
    fprintf(2,'\n Monitor not started\n');
    return;
end

%------------------------------------------------------------------
% READ the ANTENNA (first time) AND SELECT A TRAFFIC
%------------------------------------------------------------------
[traffics, t] = ANTENNA_Read();
% Select any traffic, i.e. the first one
hex=traffics(1).hexId;

file=['SSRtracks-',date,'.txt'];  %track file for all traffics
file2=[hex,'-',date,'.txt'];      %track file for one traffic

[file, file2]=check_exist(file,file2); %Avoid writing existing files
fprintf('Track files: \n%s\n%s\n', file, file2);

%------------------------------------------------------------------
% PERIODIC LOOP
%------------------------------------------------------------------
while t<TMAX
    %------------------------------------------------------------------
    % READ the ANTENNA
    %------------------------------------------------------------------
    [traffics,t,real_time] = ANTENNA_Read();

    %------------------------------------------------------------------
    % WRITE ALL radar information in a file
    %------------------------------------------------------------------
    TRACK_write(file,traffics,real_time);
    
    %------------------------------------------------------------------
    % WRITE the track of the selected traffic in a file
    %------------------------------------------------------------------
    i=TRAFFIC_find(traffics,hex);
    
    if i>0
        traffic=traffics(i);
        traffics(i).color = 0;
        TRACK_write(file2,traffic,real_time);
    end
    
    %------------------------------------------------------------------
    % Display Selected Traffic in red
    %------------------------------------------------------------------
    
    MONITOR_DisplayTraffic(traffics, t);
end

end

%---------------------------------------------------------------------

function [file, file2]=check_exist(file,file2);
k=1;
while exist(['tracks/',file])
 file=['RADAR-',date,'-',num2str(k),'.txt'];
 k=k+1;
end

k=1;
while exist(['tracks/',file])
 file2=[date,'_',hex,'-',num2str(k),'.txt'];
 k=k+1;
end
end


