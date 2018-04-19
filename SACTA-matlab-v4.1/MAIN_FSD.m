function MAIN_FSD
% READ ANTENNA AND DISPLAY TRAFFIC IN EUROSCOPE / SERVER FSD

clc; clear all; close all;
addpath('SACTA','lib/kml','lib/geo');

%------------------------------------------------------------------
% FSD server
%------------------------------------------------------------------
server_adr='158.42.243.100';
output_socket=0;

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
%IP_FILE = 'SSRtracks_2015_enero_29-05-44.txt'; %RECORDED SCENARIO
IP_FILE = 'SSRtracks_2015_marzo_05-10-34.txt'; %RECORDED SCENARIO
PROTOCOL=0;
PORT ='';

SIM_SPEED = 1; % Factor used to accelerate simulation traces

%---------------------------------------------------------
% ANTENNA configuration
% Set traffic_data_source = ANTENNA_IP or TRACE_FILE  .mat
%------------------------------------------------------------------     
ANTENNA_Configure(ANTENNA,SIM_SPEED,IP_FILE,PROTOCOL,PORT); 

try
    fprintf('\n Trying to connect to FSD\n');
    output_socket = Socket(server_adr, 6809);
    fprintf('\n Server connected\n');
    output_stream   = output_socket.getOutputStream;
    d_output_stream= DataOutputStream(output_stream);
    
    %---------------------------------------------------------
    % PERIODIC LOOP
    %-------------------------------------------------------------------
    while t<TMAX
        %------------------------------------------------------------------
        % READ the ANTENNA
        %------------------------------------------------------------------
        [traffics, t, real_time] = ANTENNA_Read();
        fprintf('t=%s\n',real_time);
        
        %------------------------------------------------------------------
        % Send it o FSD
        %------------------------------------------------------------------
        
        for i=1:length(traffic)
            str=sprintf('@N:%s:%o:1:%2.6f:%3.6f:%u:%3.0f:0:0\n',traffic(i).Hexcode,(3072+i),traffic(i).Latitud,traffic(i).Longitud,traffic(i).Altitud,traffic(i).Velocidad)
            d_output_stream.writeBytes(char(str));
            d_output_stream.flush;
        end;
    end
    
catch
    output_socket.close;
end