function [lat2,lon2,a21] = orto_reckon(lat1,lon1,s,a12)
% Travel a given distance along a given azimuth starting at 
% a given initial point, using the WGS-84 Earth ellipsoid.
% Return the endpoint and final azimut.
% 
% USAGE:
% [lat2,lon2] = orto_reckon(lat1, lon1, s, a12)
%
% VARIABLES:
% lat1 = inital latitude (degrees)
% lon1 = initial longitude (degrees)
% s    = distance (meters)
% a12  = intial azimuth (degrees)
% lat2, lon2 = second point (degrees)
% a21  = reverse azimuth (degrees), at final point facing back toward the
%        initial point
%
% Spherical formula:
% lat2= asin(sin(lat1)*cos(s/R) + cos(lat1)*sin(s/R)*cos(a12))
% lon2 = lon1+ atan2(sin(a12)*sin(s/R)*cos(lat1), cos(s/R)-sin(lat1)*sin(lat2))

R = 6371000;

lat2 = asind(sind(lat1)*cos(s/R) + cosd(lat1)*sin(s/R)*cosd(a12));
lon2 = lon1 + atan2(sind(a12)*sin(s/R)*cos(lat1), cos(s/R)-sind(lat1)*sind(lat2))*180/pi;

lat2 = mod(lat2,360);
lon2 = mod(lon2,360);
    
if nargout > 2
    dlon = lon1 - lon2;
    y = sind(dlon) * cosd(lat1);
    x = cosd(lat2) * sind(lat1) - sind(lat2)* cosd(lat1)* cosd(dlon);
    a21=atan2(y, x)*180/pi;
    a21 = mod(a21,360);
    
end