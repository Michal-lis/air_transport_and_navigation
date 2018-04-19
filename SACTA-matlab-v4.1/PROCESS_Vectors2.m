function [linelist,traffics] = PROCESS_Vectors2(traffics,t,t_future)


persistent prev_traffics prev_time;
linelist={};

if isempty(prev_traffics)
    prev_traffics=traffics;
    prev_time=t;
    traffics=[];
else
    for i= 1:length(traffics)
        traffics(i).color = 'red';
        olt=TRAFFIC_find(prev_traffics,traffics(i).hexId);
        if olt>0
            p1=prev_traffics(olt);
            p1.t=prev_time;
            p2=traffics(i);
            p2.t=t;
            if (p1.lon~=p2.lon)
                %p3=extrapolation2(p1, p2, t+t_future);
                p3=extrapolation(p2,t+t_future);
                line = [ p2.lon, p2.lat; p3.lon, p3.lat];
                linelist(i) = {line};
                i=i+1;
            end;
        end;
    end;
    prev_traffics=traffics;
    prev_time=t;
end
end
%##########################################################################

function [p_estimated] = extrapolation(p,t)
kt2dps=1.852/(3600*111);

p_estimated.lon = p.lon + p.gspeed*t*kt2dps*sind(p.track);
p_estimated.lat = p.lat + p.gspeed*t*kt2dps*cosd(p.track);
p_estimated.alt = p.alt + p.vertRate*t/60;
end


%##########################################################################

function [p_estimated] = extrapolation1(p1, p2,t)
% It performs a linear interpolation to find out the position of an
% aircraft after a time interval t.
% INPUT PARAMETERS:
% p1: point 1 defined by the following struct:
%     p1.lon: longitude
%     p1.lat: latitude
%     p1.alt: altitude
%     p1.t:   time
%
% p2: point 1 defined by a similar struct.
%
% OUTPUT PARAMETERS:
% p_estimated: Estimated final point.
%              Defined by a similar struct to p1.
%
% Example:
%   p1.lon=1; p1.lat=2; p1.alt=3; p1.t=1;
%   p2.lon=1; p2.lat=2; p2.alt=3; p2.t=1;
%   p3 = pos_interpolation(p1,p2,3)
%


% FUNCION LOCAL
function at = Parametrica(a1,a2,t1,t2,t) 
    at = (a2-a1)/(t2-t1)*(t-t1)+a1;
end
        
p_estimated.lon = Parametrica(p1.lon, p2.lon, p1.t, p2.t, t);
p_estimated.lat  = Parametrica(p1.lat, p2.lat, p1.t, p2.t, t);
p_estimated.alt  = Parametrica(p1.alt, p2.alt, p1.t, p2.t, t);

end

%##########################################################################

function [p_estimated] = extrapolation2(p1, p2,t)
% It performs a interpolation to find out the position of an
% aircraft after a time interval t BASED ON ITS AIRSPEED.
% INPUT PARAMETERS:
% p1: point 1 defined by the following struct:
%     p1.lon: longitude
%     p1.lat: latitude
%     p1.alt: altitude
%     p1.t:   time
%
% p2: point 1 defined by a similar struct.
%
% OUTPUT PARAMETERS:
% p_estimated: Estimated final point.
%              Defined by a similar struct to p1.
%
% Example:
%   p1.lon=1; p1.lat=2; p1.alt=3; p1.t=1;
%   p2.lon=1; p2.lat=2; p2.alt=3; p2.t=1;
%   p3 = pos_interpolation(p1,p2,3)
%

kt2dps=1.852/(3600*111);

% local function

function at = parametric(a1,a2,t1,t2,t) 
    at = (a2-a1)/(t2-t1)*(t-t1)+a1;
end

u=[(p2.lon-p1.lon),(p2.lat-p1.lat)];
u=u*t*p2.gspeed*kt2dps/norm(u);

p_estimated.lon=p1.lon+u(1);
p_estimated.lat=p1.lat+u(2);
p_estimated.alt = parametric(p1.alt, p2.alt, p1.t, p2.t, t);

end