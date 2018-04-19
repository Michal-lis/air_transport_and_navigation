function wgs = ecef2lla(xyz)
% Converts cartesian (x,y,z) coordinates of a reference
% point in ECEF to lat, lon, height coordinates in the WGS 84 system
%
%  INPUT/OUPUT PARAMETERS:
%     wgs - 3 by 1 array containing position lat, lon, height
%           (rad, rad, m)
%     xyz - 3 by 1 array containing position as x,y,z
%           (m, m, m)
%
%     a   - semi-major axis
%     f   - spheroidal flattening
%     esq - eccentricity squared
%     sp  - sine of lattitude
%     cp  - cosine of latitude
%     sl  - sine of longitude
%     cl  - cosine of longitude
%     gsq - intermediate temp variable
%     x   - cartesian coordinte in feet
%     r   - intermediate temp variable
%
%  This function is based on one developed by the
%  National Geodetic Survey, Rockville, Maryland.
%
%  WJP2010: Vectorized. Now accepts xyz as a 3x1, a 3xM, 3xMxN, or a 3xMxNxO matrix

wgs=zeros(size(xyz));
f=1/298.257223563;
esq=f*(2-f);
a=6378137;

x = xyz(1,:,:,:);
y = xyz(2,:,:,:);
z = xyz(3,:,:,:);
rsq = (x.*x) + (y.*y);
h = esq.*z;
for i = 1:6;
  zp = z + h;
  r = sqrt(rsq + (zp.*zp));
  sp = zp./r;
  gsq = 1.0 - (esq.*sp.*sp);
  en = a./sqrt(gsq);
  p = en.*esq.*sp;
  %if abs(h-p) < 0.0005,break,end
  h = p;
end;
p = atan2(zp,sqrt(rsq));
h = r - en;
wgs(2,:,:,:) = atan2(y, x);%*180/pi;
wgs(1,:,:,:) = p;%*180/pi;
wgs(3,:,:,:) = h;


% wgs=zeros(3,1);
% f=1/298.257223563;
% esq=f*(2-f);
% a=6378137;
% x = xyz(1);
% y = xyz(2);
% z = xyz(3);
% rsq = (x*x) + (y*y);
% h = esq*z;
% for i = 1:6;
%   zp = z + h;
%   r = sqrt(rsq + (zp*zp));
%   sp = zp/r;
%   gsq = 1.0 - (esq*sp*sp);
%   en = a/sqrt(gsq);
%   p = en*esq*sp;
%   if abs(h-p) < 0.0005,break,end
%   h = p;
% end;
% p = atan2(zp,sqrt(rsq));
% h = r - en;
% wgs(2) = atan2(y, x);%*180/pi;
% wgs(1) = p;%*180/pi;
% wgs(3) = h;
