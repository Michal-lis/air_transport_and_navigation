function ecef = lla2ecef(llh)
%  Converts lat/lon/height coordinates to Earth-Centered
%  Earth-Fixed (ECEF) coordinates (WGS72).
%
%  INPUT/OUPUT PARAMETERS:
%       llh  = lat,long,height location (rad,rad,user units)
%       ecef = x,y,z (user units)
%
%  OU-ECE-AEC  Oct. 1988  FvG
%  WJP2010: Vectorized. Now accepts llh as a 3x1, a 3xM, 3xMxN, or a 3xMxNxO matrix


%A = 6378135.0;        % Earth's radius (m), old number from 1997
A = 6378137.0;		   % Earth's radius (m) per WGS84, CB
%E = 8.181881066e-02;  % Eccentricity, old number from 1997
E = 8.18191908e-2;	   % Eccentricity per WGS84, CB
ESQ = E * E;

% ecef=zeros(3,1);
% 
% SP = sin(llh(1));
% CP = cos(llh(1));
% SL = sin(llh(2));
% CL = cos(llh(2));
% GSQ = 1.0 - (ESQ*SP*SP);
% EN = A / sqrt(GSQ);
% Z = (EN + llh(3)) * CP;
% ecef(1) = Z * CL;
% ecef(2) = Z * SL;
% EN = EN - (ESQ * EN);
% ecef(3) = (EN + llh(3)) * SP;

ecef=zeros(size(llh));

SP = sin(llh(1,:,:,:));
CP = cos(llh(1,:,:,:));
SL = sin(llh(2,:,:,:));
CL = cos(llh(2,:,:,:));
GSQ = 1.0 - (ESQ.*SP.*SP);
EN = A ./ sqrt(GSQ);
Z = (EN + llh(3,:,:,:)) .* CP;
ecef(1,:,:,:) = Z .* CL;
ecef(2,:,:,:) = Z .* SL;
EN = EN - (ESQ .* EN);
ecef(3,:,:,:) = (EN + llh(3,:,:,:)) .* SP;
