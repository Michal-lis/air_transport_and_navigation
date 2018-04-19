function lla=ecef2lla_2(ecef)
% Converts cartesian (x,y,z) coordinates of a reference
% point in ECEF to lat, lon, height coordinates in the WGS 84 system
%
%  INPUT/OUPUT PARAMETERS:
%     lla  - 3 by 1 array containing position lat, lon, height
%            (rad, rad, m)
%     ecef - 3 by 1 array containing position as x,y,z
%            (m, m, m)

a = 6378137; % m
b = 6356752.314; % m
e2 = 1 - b^2/a^2; % m^2
R = 6378e3; % m
m2ft=3.28084;

x=ecef(1); y=ecef(2); z=ecef(3);

lon = atan2(y,x)*180/pi;

p = sqrt(x^2+y^2);
lat = atan2(z,p*(1-e2))*180/pi;
improvement = 1;
alt = 0;
while improvement > 1e-5
    Ni = a/sqrt(1-e2*sin(lat)^2);
    hi = p/cos(lat) - Ni;
    lat = atan2(z,(p*(1-e2*Ni/(Ni+hi))));
    improvement = abs(hi-alt);
    alt = hi;
end
lat = lat*180/pi;
alt = alt*m2ft;
lla=[lat,lon,alt];

end