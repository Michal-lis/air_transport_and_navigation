function [traffics]=SYNTRACE_read(scenario,tsim)
% It reads a scenario from a .mat file with a synthetic scenario 
% with planes flying routes sepcified as 4D trajectories.
% and returns the traffic information, i.e., a set of
% planes detected by the radar.
%
% INPUT PARAMETERS
% tsim: simulation time for which the traffic read has to be performed.
% scenario: Name (string) of the .mat file of the scenario
%           with the synthetic trace.
%           It is created from a Matlab program that generates it 
%           and saves it in a .mat file.
%           It must contain a data structure as follows for each plane:
%
% Field               Type    Description
% =========================================================================
% plane(j).aicraftId  string  Database Aircraft record number.
% plane(j).flightId   string  Database Flight record number.
% plane(j).hexId      string  Aircraft Mode S hexadecimal code.
% plane(j).callsign   string  An eight digit flight ID. It can be a
%                             flight number or regist. (or even nothing)
% plane(j).squawk     string  Assigned Mode A squawk code.
% plane(j).color      double  An integer in range [1..9] to set the color 
%                             for radar presentation.
% plane(j).trace      array of doubles
%                     Each raw of the array represents a waypoint of the
%                     route given by the following 4D parameters:
%                     [lon1, lat1, alt1, time1;
%                      lon2, lat2, alt2, time2;
%                     ...];
%                     lon and lat are specified in degrees
%                     alt is specified in feet
%                     time is specified in seconds
%
% Example:
% -------------------------------------------------------------------------
% plane(1).aicraftId = 'B757';
% plane(1).flightId = '9191';
% plane(1).hexId    = 'A00001';
% plane(1).callsign = 'IB001';     
% plane(1).squawk = '6001';
% plane(1).color = 1;
% plane(1).trace = [-0.042, 38, 5000, 0 ;
%                  -0.08, 40.13, 6000, 1200;
%                  0.059, 42.46, 4000, 3000];

load(scenario);

traffics = [];
j = 1;
for i = 1:length(plane)
    [lon lat alt gspeed vrate track] = SYNTRACE_simulator(tsim, plane(i).trace);
    if alt>0
        traffics(j).lon = lon;
        traffics(j).lat = lat;
        traffics(j).alt = alt;
        traffics(j).gspeed = gspeed;
        traffics(j).aicraftId = plane(i).aicraftId;
        traffics(j).flightId = plane(i).flightId;
        traffics(j).hexId = plane(i).hexId;
        traffics(j).callsign = plane(i).callsign;
        traffics(j).squawk = plane(i).squawk;
        traffics(j).track = track;
        traffics(j).vertRate = vrate;
        traffics(j).alert = '0';
        traffics(j).emergency = '0';
        traffics(j).SPI = '0';
        traffics(j).isOnGround = '0';
        traffics(j).color = plane(i).color;
        traffics(j).date = datestr(clock,'yyyy/mm/dd');
        traffics(j).time = strrep(datestr(clock,'HH:MM:SS FFF'),' ','.');
        traffics(j).icon = 'avion.png';
        traffics(j).comments = '';
        j = j + 1;
    end
end

end

function [lon lat alt gspeed vrate track] = SYNTRACE_simulator(t, traj)
% It performs the simulation or interpolation of data of the route
% specified ia .mat file with a synthetic trace
% It returns -1 if the traffic dissapears or crashes
%
[fil col] = size(traj);
iPos = 0;
for i = 1:fil-1
	if traj(i,4) <= t && t <= traj(i+1,4)
		iPos = i;
		break;
    end
end

lat = 0;
lon = 0;
alt = -1;
gspeed = 0;
vrate = 0;
track=0;

if (iPos > 0) && (traj(iPos,3) >= 0)
	% lat = ((lat2-lat1)/(t2-t1))*(t-t1)
	t21 = traj(iPos+1,4) - traj(iPos,4);
	t1 = traj(iPos,4);
	lon = traj(iPos,1)+((traj(iPos+1,1) - traj(iPos,1))/t21)*(t-t1);
	lat = traj(iPos,2)+((traj(iPos+1,2) - traj(iPos,2))/t21)*(t-t1);
	alt = traj(iPos,3)+((traj(iPos+1,3) - traj(iPos,3))/t21)*(t-t1);
	gspeed = (distance(traj(iPos,1), traj(iPos,2), traj(iPos+1,1), traj(iPos+1,2))/1.8520)/(t21/3600);
    vrate = (traj(iPos+1,3) - traj(iPos,3))/t21*60;
    track=atan2d(traj(iPos+1,1) - traj(iPos,1),traj(iPos+1,2) - traj(iPos,2));
end
end

function dist = distance(Lon1, Lat1, Lon2, Lat2)
% It returns the distance in kms between two points of coordinates 
% (Lon1,Lat1) y (Lon2, Lat2).
% Ita assumes flat earth simplification
% Aproximately...
% 1 latitude degree = 110 km 
% 1 longitude degree = 111 km
GRADO_LAT = 110;
GRADO_LON = 111;

dist = sqrt(((Lon2-Lon1)*GRADO_LON)^2 + ((Lat2-Lat1)*GRADO_LON)^2);
end

function res_array = strsplit(cadena)
	cadena = strtrim(cadena);
	res_array = {};
	i = 1;
	i_array = 1;
	while (i<=size(cadena,2))
		%search for a new string:
		while(i<=size(cadena,2))
			if(isspace(cadena(1,i)))
				i = i + 1;
			else
				break;
			end
		end
		i_cad = 1;
		while(i<=size(cadena,2))
			if(isspace(cadena(1,i)))
				i_array = i_array + 1;
				break;
			%elseif(isalpha(cadena(1,i)))
			else
				res_array{i_array}(i_cad) = cadena(1,i);
				i_cad = i_cad + 1;
			end
			i = i + 1;
		end
    end
end

