function dist = dist_flat(lon1, lat1, lon2, lat2)
% It returns the distance between two points.
% It returns the distance in km.
% The points are defined by their coordinates 
% (lon1,lat1) y (lon2, lat2).
% It assume 'flat earth' simplification 
% Aprox...
% 1  latitude degree = 110 km 
% 1  longitud degrees= 111 km
DEG_LAT = 110;
DEG_LON = 111;

dist = sqrt(((lon2-lon1)*DEG_LON)^2 + ((lat2-lat1)*DEG_LON)^2);
end
