function enu = ecef2enu(ecef,orgece,orgllh)
% Convert ECEF coordinates to East-North-Up with respect to 
% orgece and orgllh
% (orgece is the same location as orgllh but in LLH).
%
%   Inputs:     orgece [3x1] - ENU origin in ECEF
%               orgllh [3x1] - ENU origin in LLH (in radians)
%               ecef   [3xN] - ECEF coordinates of points ot be converted
%   Outputs:    enu    [3xN] - ENU coordinates
%
%   EE6900 Flight Management Systems
%
%   Maarten Uijt de Haag
%
%   Based on: OU-ECE-AEC   Oct. 1988  FvG

%   Generate new orgece matrix
difece = 0.0*ecef;
difece(1,:) = ecef(1,:) - orgece(1);
difece(2,:) = ecef(2,:) - orgece(2);
difece(3,:) = ecef(3,:) - orgece(3);

sla = sin(orgllh(1,1)); cla = cos(orgllh(1,1));
slo = sin(orgllh(2,1)); clo = cos(orgllh(2,1));

%   earth to navigation frame
C = [  -slo      clo      0 ; ...
    -sla*clo  -sla*slo  cla; ...
    cla*clo   cla*slo  sla];

% Convert the points
enu(1,:)=C(1,1)*difece(1,:)+C(1,2)*difece(2,:)+C(1,3)*difece(3,:);
enu(2,:)=C(2,1)*difece(1,:)+C(2,2)*difece(2,:)+C(2,3)*difece(3,:);
enu(3,:)=C(3,1)*difece(1,:)+C(3,2)*difece(2,:)+C(3,3)*difece(3,:);

end