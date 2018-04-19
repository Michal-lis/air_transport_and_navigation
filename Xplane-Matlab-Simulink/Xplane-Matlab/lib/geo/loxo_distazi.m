function [s,a12,a21]=loxo_distazi(lat1,lon1,lat2,lon2)
% Compute the distance between two points 
% through a loxodromic (rhumb) line in a spher.
% Compute forward azimuth, and compute backward azimuth.
% The azimuth remains constant so forward and backward match.
%
% s = loxo_distazi(lat1,lon1,lat2,lon2)
% [s,a12] = loxo_distazi_distazi(lat1,lon1,lat2,lon2)
% [s,a12,a21] = loxo_distazi_distazi(lat1,lon1,lat2,lon2)
%
% s = distance in meters (inputs may be scalars, vectors, or matrices)
% a12 = azimuth in degrees from first point to second point (forward)
% a21 = azimuth in degrees from second point to first point (backward)
%       (Azimuths are in degrees clockwise from north.)
% lat1 = GEODETIC latitude of first point (degrees)
% lon1 = longitude of first point (degrees)
% lat2, lon2 = second point (degrees)
%
%  Original algorithm source:
% Calculates the loxodromic (rhumb line) distance and bearing between two
% points.

R = 6371000; %Mean Earth radius

% Convert fom degrees to radians
lon1=lon1* (pi/180);
lon2=lon2* (pi/180);
lat1=lat1* (pi/180);
lat2=lat2* (pi/180);

dlat =lat2-lat1;
dlon =lon2-lon1;
dPhi =log(tan(pi/4 + lat2/2)/tan(pi/4 + lat1/2));

if isfinite(dlat/dPhi) % E-W line gives dPhi=0
    q = dlat/dPhi;
else
    q= cos(lat1);
end

if (abs(dlon)>pi)
    if (dlon>0)
        dlon= -(2*pi-dlon);
    else
        dlon=2*pi+dlon;
    end
end
s=sqrt(dlat^2+q^2*dlon^2)*R;
a12=atan2(dlon,dPhi)*180/pi;
a21=mod(a12+180,360);
end


