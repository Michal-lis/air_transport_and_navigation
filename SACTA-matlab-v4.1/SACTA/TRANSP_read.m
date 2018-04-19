function [traffics]=TRANSP_read(isFreeMat,sactaRadar,radarip,radarport)
% It reads the information from the transponder and returns 
% the traffic information.
% 
% This function is called by ANTENNA_Read.
% Values sactaRadar,radarip,radarport are set by ANTENNA_Configure.
%
% INPUT PARAMETERS
% isFreeMat:  boolean indicating if the FreeMat environment is beig used.
% sactaRadar: value returned by radar.client(radarip, radarport, protocol)
% radarip:    ip of the antenna server.
% radarport:  port of the antenna server.
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
%   Data returned by Java program from the transponder 
%   public String AircraftID = null;
%   public String HexIdent = null;
%   public String FlightID = null;
%   public String DateMessageGenerated = null;
%   public String TimeMessageGenerated = null;
%   public String Callsign = null;
%   public String lon = null;
%   public String lat = null;
%   public String alt = null;
%   public String vel = null;
%   public String Track = null;
%   public String VerticalRate = null;
%   public String Squawk = null;
%   public String Alert = null;
%   public String Emergency = null;
%   public String SPI = null;
%   public String IsOnGround = null;
%   public int color = (int)0;
%   public long timestamp = (long)0;
traffics = [];
j = 1;
if(isFreeMat == 0)
    try
        sactaRadar.getFromServer();
        nTraffics = sactaRadar.getNAeronau();
        for i=0:nTraffics-1
            nave = sactaRadar.getAeronau(i);
            traffics(j).aicraftId = nave.AircraftID.toCharArray';
            traffics(j).flightId = nave.FlightID.toCharArray';
            traffics(j).hexId = nave.HexIdent.toCharArray';
            traffics(j).callsign = nave.Callsign.toCharArray';
            traffics(j).squawk = nave.Squawk.toCharArray';
            traffics(j).lon = str2num(nave.lon.toCharArray');
            traffics(j).lat = str2num(nave.lat.toCharArray');
            traffics(j).alt = str2num(nave.alt.toCharArray');
            traffics(j).gspeed = str2num(nave.vel.toCharArray');
            traffics(j).track = str2num(nave.Track.toCharArray');
            traffics(j).vertRate = str2num(nave.VerticalRate.toCharArray');
            traffics(j).alert = nave.Alert.toCharArray';
            traffics(j).emergency = nave.Emergency.toCharArray';
            traffics(j).SPI = nave.SPI.toCharArray';
            traffics(j).isOnGround = nave.IsOnGround.toCharArray';
            traffics(j).color = nave.color;
            traffics(j).date = nave.DateMessageGenerated.toCharArray';
            traffics(j).time = nave.TimeMessageGenerated.toCharArray';            
            traffics(j).icon = 'avion.png';
            traffics(j).comments = '';
            j = j + 1;
        end
    catch e
            e.message
    end  
else
    fd = tcp_connect(radarip, radarport);
    if(fd == -1)
        ntraf = 1;
        disp('Error connecting to Radar');
    else
        buff = blanks(60);
        bytes = tcp_readline(fd, buff, size(buff, 2));
        while(bytes > 0)
            buff2 = strsplit(buff);
            %disp(buff2);
            if(size(buff2,2)>16)
                traffics(j).lon = str2num(buff2{2});
                traffics(j).lat = str2num(buff2{3});
                traffics(j).alt = str2num(buff2{4});
                traffics(j).gspeed = str2num(buff2{5});              
                traffics(j).aicraftId = buff2{1};
                traffics(j).flightId = buff2{3};
                traffics(j).hexId = buff2{2};
                traffics(j).callsign = buff2{6};
                traffics(j).squawk = buff2{3};
                traffics(j).lon = str2num(buff2{7});
                traffics(j).lat = str2num(buff2{8});
                traffics(j).alt = str2num(buff2{9});
                traffics(j).gspeed = str2num(buff2{10});
                traffics(j).track = str2num(buff2{11});
                traffics(j).vertRate = str2num(buff2{12});
                traffics(j).alert = buff2{14};
                traffics(j).emergency = buff2{15};
                traffics(j).SPI = buff2{16};
                traffics(j).isOnGround = buff2{17};
                traffics(j).color = nave.color;
                traffics(j).date = buff2{4};
                traffics(j).time = buff2{5};
                traffics(j).icon = 'avion.png';
                traffics(j).comments = '';
                j = j + 1;
            end
            buff = blanks(60);
            bytes = tcp_readline(fd, buff, size(buff, 2));
        end
        tcp_disconnect(fd);
    end
end
end
