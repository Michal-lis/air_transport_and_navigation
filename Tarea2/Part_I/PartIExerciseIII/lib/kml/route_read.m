function wp=route_read(file)
% It reads a text file produced by Route Finder defining a route
% like the one provided in LEVC-UEEE.txt
% It produces a list waypoints contained in the Route Finder file 
% with the following attributes:
% wp(n).lon
% wp(n).lat
% wp(n).alt
% wp(n).gspeed
% wp(n).desc

%This function provides backward compatibility.
% UPGRADE to routefinder_read!

wp=routefinder_read(file);
end