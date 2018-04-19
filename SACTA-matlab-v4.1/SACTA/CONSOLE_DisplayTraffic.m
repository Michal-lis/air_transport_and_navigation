function CONSOLE_DisplayTraffic(t,traf)
% It prints a table in the console with the data of a traffic array
% and the associated time.
% Called from MONITOR_DisplayTraffic when MONITOR = 3.
%
% INPUT PARAMETERS:
% t: simulation time
% traf: an array of traffic structs with at least the following fields
%       The following fields of traffics are required to this display option:
% Field                  Type    Description
% =========================================================================
% traffics(j).hexId      string  Aircraft Mode S hexadecimal code.
% traffics(j).callsign   string  An eight digit flight ID. It can be a
%                                flight number or regist. (or even nothing)
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
% traffics(j).time       string  Time when message was generated.

clc;
fprintf('\nt=%g\n',t);
      
fprintf('n CALLSIG HEXID  LON      LAT      ALT   GS  TR  TIME\n');
for i=1:length(traf)
 fprintf('%d %7s %6s %+2.6g %+2.6g %5.5g %3.3g %3.3g %s\n',i,traf(i).callsign,traf(i).hexId,...
          traf(i).lon, traf(i).lat, traf(i).alt, traf(i).gspeed, traf(i).track , traf(i).time);
end
end


