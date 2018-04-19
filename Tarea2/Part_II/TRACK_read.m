function [traffics, tsim, real_time]=TRACK_read(file)
% It reads an instant of time of recorded set of tracks from a .txt file.
% and returns the traffic information, i.e., a set of
% planes detected by the antenna.
% The first call opens the file, reads the information for the first instant
% of time and leaves the file open.
% Subsequent calls read the following instants of time, until the eof is
% reached. The the file is closed and tsim returns intmax.
%
% This function is called by ANTENNA_Read.
%
% INPUT PARAMETERS
% 
% file: Name (string) of the .txt file of the recorded track
%
% OUTPUT PARAMETERS
%  traffics  : array of  traffics for the instant of time real_time.
%              See ANTENNA_Read for a description of such array.
%  real_time : time when the trace was recorded.
%  tsim      : simulation time for which the traffic read has to be performed.

persistent fid opened t_sim rt_prev;
eof_found=false;

traffics=[];
real_time=0;
%tsim=1;

file=['tracks/',file];

if isempty(opened) || ~opened   
    fid=fopen(file,'r');
    if fid>0
        opened=true;
        date=fscanf(fid,'%s',1);
    else
        fprintf(2,'Could not open file: %s\n',file);
    end
end


if ~feof(fid);
    real_time=fscanf(fid,'%s',1);
    nd=length(real_time);
    if nd>=10
        % 10:34:49.766 3
        sec=[real_time(7:8),'.',real_time(10:nd)];
        rt=str2num(real_time(1:2))*3600+str2num(real_time(4:5))*60+str2num(sec);
        n=fscanf(fid,'%d',1);

        if isempty(t_sim)
             t_sim=1;
             rt_prev=rt;
        end
        t_sim=t_sim+round(rt-rt_prev);
        tsim=t_sim;
        
        %fprintf('%s %d\n',real_time,n);
        for i=1:n
            traffics(i).aicraftId = fscanf(fid,'%s',1);
            traffics(i).flightId = fscanf(fid,'%s',1);
            traffics(i).hexId = fscanf(fid,'%s',1);
            traffics(i).callsign = fscanf(fid,'%s',1);
            traffics(i).squawk = fscanf(fid,'%s',1);
            traffics(i).lon = fscanf(fid,'%f',1);
            traffics(i).lat = fscanf(fid,'%f',1);
            traffics(i).alt = fscanf(fid,'%f',1);
            traffics(i).gspeed = fscanf(fid,'%f',1);
            traffics(i).track = fscanf(fid,'%f',1);
            traffics(i).vertRate = fscanf(fid,'%f',1);
            traffics(i).alert = fscanf(fid,'%s',1);
            traffics(i).emergency = fscanf(fid,'%s',1);
            traffics(i).SPI = fscanf(fid,'%s',1);
            traffics(i).isOnGround = fscanf(fid,'%s',1);           
            traffics(i).date = fscanf(fid,'%s',1);
            traffics(i).time = fscanf(fid,'%s',1);
            traffics(i).color = 1;
            traffics(i).icon = 'avion.png';
            traffics(i).comments = '';
        end
        rt_prev=rt;
%        ntraf=length(traffics);
    else
        eof_found=true;
    end
else
    eof_found=true;
end
    
if eof_found
    tsim=intmax;
    real_time=0;
    traffics=[];
    ntraf=0;
    fclose(fid);
    opened=false;
end
