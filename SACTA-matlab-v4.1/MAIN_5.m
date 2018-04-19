function MAIN_5
% DRAW FLIGHT VECTORS IN SACTA MONITOR 
% TO PREDICT FUTURE ESTIMATED POSITION

clc; clear all; close all;
addpath('SACTA','../lib/kml','../lib/geo');

%------------------------------------------------------------------
% Variables and constants
%------------------------------------------------------------------
% ANTENNA PARAMETERS
% ANTENNA='ip';       % SELECT ANTENNA
% IP_FILE='158.42.40.150'; % Host with antenna
% PORT=2220;          % Port of the antenna
% PROTOCOL= 3;        % TCP(char)=3 UDP(char)=4 
%                     % Multicast=2 IP_FILE='226.1.1.1' PORT=2221
                    
% SIMULATION FILES
ANTENNA='file';    % SELECT FILE
%IP_FILE = 'scenario3.mat';                     %SYNTHETIC TRACE
IP_FILE = 'SSRtracks_2015_enero_29-05-44.txt'; %RECORDED SCENARIO
PROTOCOL=0;
PORT ='';

% MONITOR PARAMETERS
MONITOR= 1;    % SACTA=1 Google_Earth = 2  Console=3;
BEAM= true;    % Paint the rotating beam on the screen. Just for fun.
SIM_SPEED = 5; % Factor used to accelerate simulation traces
               % It does not affect real-time transponder antenna
t=0;           % Time elapsed since the beginning of the program
TMAX=2000;     % Max (real or simulated) time executing the program
t_future=100;

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
% PERIODIC LOOP
%------------------------------------------------------------------
while t<TMAX
    %------------------------------------------------------------------
    % READ the ANTENNA
    %------------------------------------------------------------------
    pause(1);
    [traffics, t] = ANTENNA_Read();
    
    %[linelist,traffics] = PROCESS_TimeExtrapolation(traffics,t,t_future);
    [linelist] = PROCESS_Vectors(traffics,t,t_future);
  
    SACTA_DisplayLines(linelist,4);
    MONITOR_DisplayTraffic(traffics, t);
        
end
    
end
