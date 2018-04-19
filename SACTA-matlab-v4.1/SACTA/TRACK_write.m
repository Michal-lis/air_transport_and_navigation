function TRACK_write(file,traffic,time)
% It appends a line to a trace file with the data at time t 
% of a traffic array that is passed as an argument.
%
% INPUT PARAMETERS
% file: an output .txt file located in the SACTA/tracks directory
% time: simulation time
% traffic: traffic structure
%          It must have at least the following fields per traffic:
%
% Field                  Type    Description
% =========================================================================
% traffics(j).aicraftId  string  Database Aircraft record number.
% traffics(j).flightId   string  Database Flight record number.
% traffics(j).hexId      string  Aircraft Mode S hexadecimal code.
% traffics(j).callsign   string  An eight digit flight ID. It can be a
%                                flight number or regist. (or even nothing)
% traffics(j).squawk     string  Assigned Mode A squawk code.
%
% traffics(j).lon        double  Longitude in degrees
%                                East positive, West negative.
% traffics(j).lat        double  Latitude in degrees
%                                North positive, South negative.
% traffics(j).alt        double  Mode C altitude in feet.
%                                Height relative to 1013.2mb in feet.
%                                (Flight Level). Not height AMSL..
% traffics(j).gspeed     double  GS Speed over ground in NM 
%                                (not indicated airspeed)
% traffics(j).track      double  Track of aircraft in degrees (not heading). 
%                                Derived from the velocity E/W and N/S.
% traffics(j).vertRate   double  Vertical rate in fpm. 64ft resolution.
%
% traffics(j).alert      string  Flag to indicate squawk has changed.
% traffics(j).emergency  string  Flag to indicate emergency code has been set.
% traffics(j).SPI        string  Flag to indicate transponder Ident has been activated.
% traffics(j).isOnGround string  Flag to indicate ground squat switch is active.
%
% traffics(j).date       string  Date when message was generated.
% traffics(j).time       string  Time when message was generated.
% traffics(j).color      double  An integer in range [1..9] to set the color 


% The format of the track file is:
%------------------------------------------------------------------------
% Date
% Time # of traffics
% traffic1
% traffic2
% traffic3
% ...
% Time # of traffics
% traffic1
% traffic2
% traffic3
% ...
%
% Example:
%--------
% 05-mar-2015
% 10:34:49.766 3
% 20844 2448976 344548 VLG8461 4774 -2.63703 40.97286 38000.0 406.2 75.9 192.0 0 0 0 0 2015/03/05 10:34:42.958
% 63 2448949 4B1A5E EZS98GE 5531 2.35773 39.17422 38000.0 434.2 70.8 -64.0 0 0 0 0 2015/03/05 10:34:43.973
% 486 2448934 0A001B 0A001B 5543 1.26299 40.48034 36000.0 338.9 353.9 64.0 0 0 0 0 2015/03/05 10:34:42.598
% 10:34:50.771 4
% 20844 2448976 344548 VLG8461 4774 -2.63703 40.97286 38000.0 406.2 75.9 192.0 0 0 0 0 2015/03/05 10:34:42.958
% 63 2448949 4B1A5E EZS98GE 5531 2.35991 39.17487 38000.0 434.2 70.8 -64.0 0 0 0 0 2015/03/05 10:34:43.973
% 486 2448934 0A001B 0A001B 5543 1.26287 40.48127 36000.0 338.9 353.9 64.0 0 0 0 0 2015/03/05 10:34:42.598
% 16064 2448970 344297 AEA2662 3722 -1.03343 38.68726 36000.0 368.6 28.2 0.0 0 0 0 0 2015/03/05 10:34:42.598
%-----------------------------------------------------------------------------------------------------------
% The fields for each traffic line are:
% aicraftId
% flightId
% hexId
% callsign
% squawk 
% lon
% lat
% alt
% gspeed
% track
% vertRate
% alert
% emergency
% SPI
% isOnGround
% date
% time
%
% See ANTENNA_Read help for a description of these fields

nil='-';
file=['tracks/',file];
if nargin==3
    real_time=num2str(time); 
else
    real_time=strrep(datestr(clock,'HH:MM:SS FFF'),' ','.');
end

if ~exist(file)
    fid=fopen(file,'w');
    fprintf(fid,'%s\n',datestr(clock,'dd-mmm-yyyy'));
else
    fid=fopen(file,'a');
end

fprintf(fid,'%s %d\n',real_time,length(traffic));
for k=1:length(traffic)
    fprintf(fid,'%s %s %s %s %s %3.7f %3.7f %5.2f %3.2f %3.2f %3.2f %c %c %c %c %s %s\n',...
    deblk(traffic(k).aicraftId,nil), deblk(traffic(k).flightId,nil), deblk(traffic(k).hexId,nil),...
    deblk(traffic(k).callsign,nil), deblk(traffic(k).squawk,nil),...
    traffic(k).lon, traffic(k).lat, traffic(k).alt, traffic(k).gspeed,...
    traffic(k).track, traffic(k).vertRate,...
    deblk(traffic(k).alert,nil), deblk(traffic(k).emergency,nil), deblk(traffic(k).SPI,nil), deblk(traffic(k).isOnGround,nil),...
    deblk(traffic(k).date,nil), deblk(traffic(k).time,nil));
end
fclose(fid);
end

function rstr=deblk(str,fillwith)
if length(str)==0
    rstr=fillwith;
else
    rstr=str;
end
end