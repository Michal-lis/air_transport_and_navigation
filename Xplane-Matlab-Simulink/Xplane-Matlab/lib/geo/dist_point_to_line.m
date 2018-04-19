function dist = dist_point_to_line(Lonp1, Latp1, Lonr1, Latr1, Lonr2, Latr2)
% It returns the distance (ft) between a point and a line defined by two points.
% It returns the distance in feet
% Parameters:
% Lonp1, Latp1: Longitude and latitude of the point.
% Lonr1, Latr1, Lonr2, Latr2: Longitude and latitude of the points r1 and r2
%                             that they define the line.

% First, calculate the slope
m = (Lonr2-Lonr1)/(Latr2-Latr1);

% Second,compute parameters A,B,C of the general equation of a line:
A = m;
B = -1;
C = (Lonr1-m*Latr1);

% Third, aplly the distance formula
% d = Ax1+By1+C/aqrt(A^2+B^2)
d = (A*Latp1+B*Lonp1+C)/sqrt(A^2+B^2);

dist = 36481*d; % convert from degrees to feet