function [s,a12,a21] = orto_distazi(lat1,lon1,lat2,lon2)
% Compute the distance between two points assumming 
% a perfectly spherical earth and Haversine approximation.
% Compute also forward azimuth, and backward azimuth.
%
% s = orto_distazi(lat1,lon1,lat2,lon2)
% [s,a12] = orto_distazi(lat1,lon1,lat2,lon2)
% [s,a12,a21] = orto_distazi(lat1,lon1,lat2,lon2)
%
% s = distance in meters (inputs may be scalars, vectors, or matrices)
% a12 = azimuth in degrees from first point to second point (forward)
% a21 = azimuth in degrees from second point to first point (backward)
%       (Azimuths are in degrees clockwise from north.)
% lat1 = GEODETIC latitude of first point (degrees)
% lon1 = longitude of first point (degrees)
% lat2, lon2 = second point (degrees)

% Haversine:
% a = sin²(dlat/2) + cos(lat1).cos(lat2).sin²(dlong/2)
% c = 2.atan2(sqrt(a), sqrt(1-a))
% d = R.c
  
R = 6371000;

% Convert fom degrees to radians
% lon1=lon1* (pi/180);
% lon2=lon2* (pi/180);
% lat1=lat1* (pi/180);
% lat2=lat2* (pi/180);

dlat = (lat2-lat1);
dlon = (lon2-lon1);

a = sind(dlat/2) * sind(dlat/2) + ...
    sind(dlon/2) * sind(dlon/2) * cosd(lat1) * cosd(lat2); 
c = 2 * atan2(sqrt(a),sqrt(1-a)); 
s = R * c;

if nargout > 1
    dlon = lon2 - lon1;
    y = sind(dlon) * cosd(lat2);
    x = cosd(lat1) * sind(lat2) - sind(lat1)* cosd(lat2)* cosd(dlon);
    az=atan2(y, x)*180/pi;
    a12 = mod(az,360);
end
    

if nargout > 2
    dlon = lon1 - lon2;
    y = sind(dlon) * cosd(lat1);
    x = cosd(lat2) * sind(lat1) - sind(lat2)* cosd(lat1)* cosd(dlon);
    az=atan2(y, x)*180/pi;
    a21 = mod(az,360);
end

end