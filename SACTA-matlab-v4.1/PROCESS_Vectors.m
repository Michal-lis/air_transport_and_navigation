function [linelist] = PROCESS_Vectors(traffics,t,t_future)
% This function calculates the flight vectors (sable) of an array 
% of traffics and returns it as cell array of lines.
% The flight vector (sable) is a line that goes from the nose of the plane
% to the calculated future position at a time t_future from current time t. 
% This position is calculated by extrapolation using the ground speed,
% the vertical speed and the track angle.
% INPUT PARAMETERS
%    traffics: an array of traffics as the one returned by ANTENNA_Read.
%    t:        current time
%    t_future: future time. Time elapsed from current time.
% OUTPUT PARAMETERS
%    lines : cell array of line
%       lines={line1, line2, line3}
%       Each line is defined by two points:
%       line1 = [ lon1, lat1; lon2, lat2];
%       line2 = [ lon3, lat3; lon4, lat4];
%       line3 = [ lon5, lat5; lon6, lat6];

linelist={};

for i= 1:length(traffics)
    p1=traffics(i);
    p2=extrapolation(p1,t+t_future);
    line = [ p1.lon, p1.lat; p2.lon, p2.lat];
    linelist(i) = {line};
    i=i+1;
end

end
%##########################################################################

function [p_estimated] = extrapolation(p,t)
kt2dps=1.852/(3600*111);

p_estimated.lon = p.lon + p.gspeed*t*kt2dps*sind(p.track);
p_estimated.lat = p.lat + p.gspeed*t*kt2dps*cosd(p.track);
p_estimated.alt = p.alt + p.vertRate*t/60;
end