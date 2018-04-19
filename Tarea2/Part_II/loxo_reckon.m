function [lat2,lon2,a21]=loxo_reckon(lat1,lon1,s,a12)
%(lat1,lon1,alfa,a12)
% Travel a given distance following a rhumb line, i.e,
% with a constant azimuth.
% Return the endpoint and final azimut.
% 
% USAGE:
% [lat2,lon2,a21] = loxo_reckon(lat1, lon1, s, a12)
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
% Original algorithm source:

R = 6371000;
alfa=s/R;
a12=a12*pi/180;
lat1=lat1*pi/180;
lon1=lon1*pi/180;

dlat =(alfa)*cos(a12);
lat2 = lat1 + dlat;
dPhi = log(tan(lat2/2 + pi/4) / tan(lat1/2 + pi/4));

if isfinite(dlat/dPhi) % E-W line gives dPhi=0
    q = dlat/dPhi;
else
    q= cos(lat1);
end
dlon = (alfa)*sin(a12)/q;

% check for some daft bugger going past the pole, normalise latitude if so
if (abs(lat2) > pi/2)
    if lat2>0
        lat2 = pi -lat2;
    else
        lat2 = -pi-lat2;
    end
end

lon2 = rem((lon1+dlon+pi),2*pi) - pi;

lat2=lat2*180/pi;
lon2=lon2*180/pi;

if nargout > 2
    a21=mod(a12*180/pi+180,360);
end
end

