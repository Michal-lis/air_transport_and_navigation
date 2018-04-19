function MONITOR_DisplayTraffic(traffics, t)
% Primary function for displaying traffic on any of the following devices:
% 1: SACTA, 
% 2: GOOGLE EARTH
% 3: CONSOLE, 
% The corresponding displaying device is set by MONITOR_Configure.
% It displays the traffic specified in the traffic array "traffics"
% and the simulation time.
% The representation is monitor depending.
%
% INPUT PARAMETERS 
% t:  Time to be displayed.
% traffics: an array of structs of the form traffics(i).field 
%           where a number of fields are mandatory for each monitor type.
%           It is recomended to use an array of structs as the one returned
%           by ANTENNA_Read.
% The parameters which are strcitly mandatory for each representation are
% convieniently marked with an *,#, or a @ in the following table:
% R   Field                  Type    Description
% =========================================================================
% *   traffics(j).hexId      string  Aircraft Mode S hexadecimal code.
% *   traffics(j).callsign   string  An eight digit flight ID. It can be a
%                                flight number or regist. (or even nothing)
% *   traffics(j).squawk     string  Assigned Mode A squawk code.
%
% *   traffics(j).lon        double  Longitude in degrees
%                                East positive, West negative.
% *   traffics(j).lat        double  Latitude in degrees
%                                North positive, South negative.
% *   traffics(j).alt        double  Mode C altitude in feet.
%                                Height relative to 1013.2mb in feet.
%                                (Flight Level). Not height AMSL..
% *   traffics(j).gspeed     double  GS Speed over ground in NM 
%                                (not indicated airspeed)
% *   traffics(j).track      double  Track of aircraft in degrees (not heading). 
%                                Derived from the velocity E/W and N/S.
% #   traffics(j).vertRate   double  Vertical rate in fpm. 64ft resolution.
% #   traffics(j).color      double  An integer in range [1..9] to set the color 
%                                for radar presentation. 
%                                See README.colors. Change it to set the color.
% *   traffics(j).time       string  Time when message was generated.
% @   traffics(j).icon = 'avion.png' Icon file for Google Earth representation
% @   traffics(j).comments ='string' Comments for Google Earth representation
% 
% * : All representations
% # : SACTA and Google Earth
% @ : Google Earth

global modo_monitor gBeam gVelocidad

if isempty(modo_monitor)
    fprintf(2,'Monitor not set.\n Use MONITOR_Configure to set the monitor\n');
end

if(modo_monitor == 1)
    ret = SACTA_DisplayTraffic(t, traffics, gBeam, gVelocidad);
elseif (modo_monitor == 2)
    GEARTH_DisplayTraffic(traffics,'SACTA.kml');
else
    CONSOLE_DisplayTraffic(t, traffics);
end
end
