function [traffics, tsim, real_time] = ANTENNA_Read()
% It reads the information from the traffic source established
% by ANTENNA_Configure and returns the corresponding traffic information.
% This information consists of an array of planes detected by the radar.
% It delays one second two succesive reads from the traffic source.
%
% INPUT PARAMETERS
% none
%
% RETURN VALUES
% tsim: double specifying the simulation time elapsed from
%       the start of the simulation.
%       If the simulation is accelerated by a factor of A,
%       the returned value is the previous value + A*dt.
%
% real_time: It is current time for the transponder 
%            and matlab sythetic traces. For recorded tracks it returns
%            the time when the traffic was recorded.
%
% traffics: an array of traffics or planes detected by the transponder.
%           Each traffic is represented a struct of the form 
%           traffics(i).field
%           where the following fields are available:
%
% Field                  Type    Description
% =========================================================================
% traffics(i).aicraftId  string  Database Aircraft record number.
% traffics(i).flightId   string  Database Flight record number.
% traffics(i).hexId      string  Aircraft Mode S hexadecimal code.
% traffics(i).callsign   string  An eight digit flight ID. It can be a
%                                flight number or regist. (or even nothing)
% traffics(i).squawk     string  Assigned Mode A squawk code.
%
% traffics(i).lon        double  Longitude in degrees
%                                East positive, West negative.
% traffics(i).lat        double  Latitude in degrees
%                                North positive, South negative.
% traffics(i).alt        double  Mode C altitude in feet.
%                                Height relative to 1013.2mb in feet.
%                                (Flight Level). Not height AMSL..
% traffics(i).gspeed     double  GS Speed over ground in NM 
%                                (not indicated airspeed)
% traffics(i).track      double  Track of aircraft in degrees (not heading). 
%                                Derived from the velocity E/W and N/S.
% traffics(i).vertRate   double  Vertical rate in fpm. 64ft resolution.
%
% traffics(i).alert      string  Flag to indicate squawk has changed.
% traffics(i).emergency  string  Flag to indicate emergency code has been set.
% traffics(i).SPI        string  Flag to indicate transponder Ident has been activated.
% traffics(i).isOnGround string  Flag to indicate ground squat switch is active.
%
% traffics(i).date       string  Date when message was generated.
% traffics(i).time       string  Time when message was generated.
% traffics(i).color      double  An integer in range [1..9] to set the color 
%                                for radar presentation. 
%                                See README.colors. Change it to set the color.
% traffics(i).icon = 'avion.png' Icon file for Google Earth representation
% traffics(i).comments ='string' Comments for Google Earth representation

global isFreeMat
global gVelocidad
global gFuenteDatos
global gTraza
global sactaRadar
global radarip
global radarport


persistent tprev tnow elapsed;
persistent prev_traffics prev_tsim;

PERIOD=1;

if isempty(tnow)
    tnow=0;
    tprev=tic;
    elapsed=2;
    prev_traffics=[];
    prev_tsim=0;
end

if gFuenteDatos == 0
    [traffics]=TRANSP_read(isFreeMat,sactaRadar,radarip,radarport);
    %--------------------
    comp_time=toc(tprev);
    pause(PERIOD-comp_time);
    tprev=tic;
    tnow = tnow + PERIOD;
    tsim=tnow;
    real_time=strrep(datestr(clock,'HH:MM:SS FFF'),' ','.');
    %--------------------
elseif gFuenteDatos == 1
    [traffics]=SYNTRACE_read(gTraza,tnow);
    %--------------------
    comp_time=toc(tprev);
    pause(0.15-comp_time);
    tprev=tic;
    tnow = tnow + 0.5*gVelocidad;
    tsim=tnow;
    real_time=strrep(datestr(clock,'HH:MM:SS FFF'),' ','.');
    %-------------------- 
elseif gFuenteDatos == 2
    [traffics, tsim, real_time]=TRACK_read(gTraza);
    if tsim<intmax
        PERIOD=tsim-prev_tsim;
        prev_tsim=tsim;
        %--------------------
        comp_time=toc(tprev);
        pause((PERIOD-comp_time)/gVelocidad);
        tprev=tic;
        %--------------------
    end
end

end