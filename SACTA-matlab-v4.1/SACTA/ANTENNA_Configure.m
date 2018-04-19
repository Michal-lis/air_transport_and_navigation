function ANTENNA_Configure(source, simspeed, ip_file, protocol, port)
% It configures the radar to get data from the following sources:
%  a) The transponder antenna which is connected via TCP/IP
%  b) .mat files: synthetic traces generated using Matlab
%  c) .txt files: previously recorded tracks from the transponder 
%
% INPUT PARAMETERS
% source: string that specifies the kind of source for traffic data. 
% The two following strings are possible
%        'file' for simulating a track recorded in a .txt or .mat file
%        'ip'   for a transponder antenna via TCP/IP
% simspeed: Factor used to accelerate simulation traces
%           It does not affect real-time transponder antenna
% ip_file: string that specifies the specific file or ip address 
%          for the traffic source. Examples:
%          if source==ip'    -> ip_file= '158.42.40.150'
%                               ip_file= '226.1.1.1' for multicast
%          if source==file'  -> ip_file= 'e1.mat' or 
%                               ip_file= 'SSRtracks_2015_enero_29-05-44.txt'
% protocol: TCP/UDP protocol used to connect to the transponder antenna.
%           It is not necessary for simulating file recorded tracks.
%           Usual is 3 which corresponds to TCP raw
%           Possible values:
%           3 - TCP (char) (server compatible Freemat)
%           4 - UDP (char) (server compatible Freemat)
%           0 - TCP (Java Objects) (incompatible Freemat)
%           1 - UDP (Java Objects)(incompatible Freemat)
%           2 - Multicast
% port : integer to specify the antenna port. 
%        It is not necessary for simulating file recorded tracks.
%        The usual port is 2220 for TCP and 2221 for multicast.
%
% RETURN VALUES
% none

global isFreeMat

isFreeMat_int = 0;
if isempty(isFreeMat)
    try
        echo;
        echo;
        javaclasspath('./SACTA/antena.jar', './SACTA/monitor.jar');
        %javaaddpath('./SACTA/antena.jar');
        %javaaddpath('./SACTA/monitor.jar');
    catch
        freemat_net_init;
        isFreeMat_int = 1;
    end
end

global isFreeMat
global gVelocidad
global gTraza
global gFuenteDatos
global sactaRadar
global radarip
global radarport

isFreeMat=isFreeMat_int;
gVelocidad = simspeed;

if (strcmp(source,'file'))
    [pathstr,name,ext] = fileparts(ip_file);
    gTraza=ip_file;
    if strcmp(ext,'.mat')
        gFuenteDatos = 1;
    else
        gFuenteDatos = 2;
    end
else
    gFuenteDatos = 0;
    radarip = ip_file;
    radarport = port;
    if(isFreeMat == 0)
        sactaRadar = interficies.client(radarip, radarport, protocol);
    else
        %Connexio al radar amb Freemat, nothing to do
    end
end


if gFuenteDatos==0
    fprintf('TRAFFIC source: TRANSPONDER antenna\n');
else
    fprintf('TRAFFIC source: TRACK %s at sim. speed %d\n', ip_file, gVelocidad);
end
end
