function status = SACTA_DisplayTraffic(t, traf, beam, accFactor)
% Function for displaying traffic on SACTA monitor.
% It displays the traffic specified in the traffic array "traf"
% and the simulation time.
% It also represents the radar beam on the monitor if beam=true
%
% INPUT PARAMETERS 
% t:  Time to be displayed.
% traf: an array of structs of the form traffics(i).field 
%       where a number of fields are mandatory for each monitor type.
%       It is recomended to use an array of structs as the one returned
%       by ANTENNA_Read
%
% beam: Boolean indicating whether the radar beam should be represented
%        The Show -> Beam option on SACTA menu bar must be checked.
% accFactor: Factor to accelerate the beam accordingly to the simulation speed.
%
% RETURN VALUES
% It returns an "0" if success

% Traffic fields required: (see ANTENNA_Read)
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


%  Format to send it to SACTA monitor:
%  Beam angle HH:MM:SS\n
%  aicraftId HexIdent flightId Callsign Squawk Lon Lat Alt Vel Track VelVert color alert emergency SPI isOnGround date time\n
%  ....
%  Example
%  -------
% 4.9637 00:00:42
% 1 1631 3C7262 2402429 BER113N 2522 -2.53705 41.1019 35025 463.6 200.6 0 0 0 0 0 2015/01/28 11:22:31.993 1
% 2 17317 44A8AD 2402425 JAF59A 5522 -0.50824 38.6948 19775 325.3 31.3 2048 0 0 0 0 2015/01/28 11:22:32.400 1
% 3 7801 4CA73A 2402391 RYR907N 5572 0.51548 41.3778 36000 382.3 14.5 0 0 0 0 0 2015/01/28 11:22:32.400 1

status=0;
pHora=seg2HHMMSS(t);
nil='-';

if isempty(accFactor)
 accFactor=1;
end

% Calcula angulo -> si beam es false, no se visualiza

if ~beam
  	haz = -1;
else 
    alfa=.01*t*accFactor;
 	haz = 2*pi*(1-(alfa - fix(alfa)));
end

datos = [ num2str(haz) ' ' pHora];
for i = 1:length(traf)
	sO = sprintf('%u %s %s %s %s %s %g %g %g %g %g %g %s %s %s %s %s %s %u',i, ...
                 deblk(traf(i).aicraftId,nil), deblk(traf(i).hexId,nil), deblk(traf(i).flightId,nil), deblk(traf(i).callsign,nil), deblk(traf(i).squawk,nil), ...
                 traf(i).lon, traf(i).lat, traf(i).alt, traf(i).gspeed, traf(i).track, traf(i).vertRate,...
                 deblk(traf(i).alert,nil), deblk(traf(i).emergency,nil), deblk(traf(i).SPI,nil), deblk(traf(i).isOnGround,nil), deblk(traf(i).date,nil), deblk(traf(i).time,nil),...
                 traf(i).color);
    datos = [ datos 10 sO ];
end

status = SACTA_SendCmd('BeamUpdate', datos);
end

function cadena = seg2HHMMSS(s)
% Converts seconds to format hh:mm:ss
segundos = mod(s,60);
s = floor(s / 60);
minutos = mod(s,60);
s = floor(s / 60);
cadena = sprintf('%02u:%02u:%02u', int16(s), int16(minutos), int16(segundos));
end

function rstr=deblk(str,fillwith)
if length(str)==0
    rstr=fillwith;
else
    rstr=str;
end
end