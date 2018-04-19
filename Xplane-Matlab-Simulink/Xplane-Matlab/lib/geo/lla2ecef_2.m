function ecef=lla2ecef_2(llh)
%  Converts lat/lon/height coordinates to Earth-Centered
%  Earth-Fixed (ECEF) coordinates (WGS72).
%
%  INPUT/OUPUT PARAMETERS:
%       llh  = lat,long,height location (rad,rad,feet)
%       ecef = x,y,z (meters)

% lon, lat: degrees centesimal
% alt: ft
% x, y, z: m

ft2m=0.3048;
a = 6378137;      % m
b = 6356752.314;  % m
e2 = 1 - b^2/a^2; % m^2
R = 6378e3;       % m

lat=llh(1); lon=llh(2); alt=llh(3)*ft2m;

N=a/sqrt(1-e2*sind(lat)^2);
x=(N+alt)*cosd(lat)*cosd(lon);
y=(N+alt)*cosd(lat)*sind(lon);
z=(N*b^2/a^2 + alt)*sind(lat);
ecef=[x,y,z];
end

