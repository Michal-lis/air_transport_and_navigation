function MAIN_1
% 1) READ ANTENNA TRAFFIC
% 2) PROCESS IT (optional) AND
% 3) DISPLAY IT ON:
%    1.- SACTA, 2.- GOOGLE EARTH OR 3.-CONSOLE

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
% ANTENNA='file';    % SELECT FILE
% IP_FILE = 'scenario3.mat';                     %SYNTHETIC TRACE
% %IP_FILE = 'SSRtracks_2015_enero_29-05-44.txt'; %RECORDED SCENARIO
% PORT ='';
% PROTOCOL=0;

SIM_SPEED = 100;      % Factor used to accelerate simulation traces
%
%% MONITOR PARAMETERS
MONITOR= 1;    % SACTA=1 Google_Earth = 2  Console=3;
BEAM= true;    % Paint the rotating beam on the screen. Just for fun.
               % It does not affect real-time transponder antenna
t=0;           % Time elapsed since the beginning of the program
TMAX=2000;     % Max (real or simulated) time executing the program

%---------------------------------------------------------
%% ANTENNA configuration
% Set traffic_data_source = ANTENNA_IP or TRACE_FILE  .mat
%------------------------------------------------------------------     
ANTENNA_Configure(ANTENNA,SIM_SPEED,IP_FILE,PROTOCOL,PORT); 

%---------------------------------------------------------
%% MONITOR configuration
% MONITOR = SACTA, GOOGLE EARTH, or CONSOLE
%---------------------------------------------------------
if MONITOR_Configure(MONITOR,BEAM) ~= 0
    fprintf(2,'\n Monitor not started\n');
    return;
end

%---------------------------------------------------------
%% PERIODIC LOOP
%-------------------------------------------------------------------
while t<TMAX
    %------------------------------------------------------------------
    % READ the ANTENNA
    %------------------------------------------------------------------
    [traffics, t, real_time] = ANTENNA_Read();
    fprintf('t=%s\n',real_time);
    
    %------------------------------------------------------------------
    % PROCESS the information from the ANTENNA
    %------------------------------------------------------------------    
    % Process traffic array (a separated function is recommended to do that)
    % Uncomment the desired processing action
    %[traffics]=PROCESS_UpperLower(traffics);
    %[traffics]=PROCESS_ClimbDescend2(traffics);
    %[traffics]=PROCESS_Collision(traffics);
       
    %------------------------------------------------------------------
    % Display Traffic in MONITOR
    %------------------------------------------------------------------
    MONITOR_DisplayTraffic(traffics, t);
    
end

end