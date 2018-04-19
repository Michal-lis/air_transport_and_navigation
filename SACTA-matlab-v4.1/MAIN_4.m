function MAIN_4
% DETECT AND LOG MANISES DEPARTURES AND APPROACHES

clc; clear all; close all;
addpath('SACTA','../lib/kml','../lib/geo');

%------------------------------------------------------------------
% Variables and constants
%------------------------------------------------------------------
% ANTENNA PARAMETERS
ANTENNA='ip';       % SELECT ANTENNA
IP_FILE='158.42.40.150'; % Host with antenna
PORT=2220;          % Port of the antenna
PROTOCOL= 3;        % TCP(char)=3 UDP(char)=4 
                    % Multicast=2 IP_FILE='226.1.1.1' PORT=2221

% MONITOR PARAMETERS
MONITOR= 1;    % SACTA=1 Google_Earth = 2  Console=3;
BEAM= true;    % Paint the rotating beam on the screen. Just for fun.
SIM_SPEED = 1; % Factor used to accelerate simulation traces
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


Manises.lat = sex2dec('N039º29''22.00"');
Manises.lon= sex2dec('W000º28''54.00"');
%------------------------------------------------------------------
% PERIODIC LOOP
%------------------------------------------------------------------
while t<TMAX
    %------------------------------------------------------------------
    % READ the ANTENNA
    %------------------------------------------------------------------
    [traffics, t] = ANTENNA_Read();
    
    % PROCESS traffic arrays
    [DepTraffic,ArrTraffic,traffics] = PROCESS_DepArr(traffics,Manises);

    % WRITE departure traces
    for j=1:length(DepTraffic)      
        file=[date,'_Departure_',DepTraffic(j).hexId,'.txt'];
        TRACK_write(file,DepTraffic(j));
    end
    
    % WRITE arrival traces
    for j=1:length(ArrTraffic)
        file=[date,'_Arrival_',ArrTraffic(j).hexId,'.txt'];
        TRACK_write(file,ArrTraffic(j));
    end

    %------------------------------------------------------------------
    % Display Traffics in MONITOR
    %------------------------------------------------------------------
    MONITOR_DisplayTraffic(traffics, t);
    
end

end