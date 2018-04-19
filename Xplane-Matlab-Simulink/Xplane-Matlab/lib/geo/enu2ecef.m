function ecef = enu2ecef(enu,orgece,orgllh)
% Convert ENU coordinates to ECEF with respect to the origin 
% (orgece is the same location as orgllh).
%
%   Inputs:     orgece [3x1] - ENU origin in ECEF
%               orgllh [3x1] - ENU origin in LLH (radians)
%               enu    [3xN] - ENU coordinates of points ot be converted
%   Outputs:    ecef   [3xN] - ECEF coordinates
%
%   EE6900 Flight Management Systems
%
%   Maarten Uijt de Haag
%
%   Based on: OU-ECE-AEC   Oct. 1988  FvG

sla = sin(orgllh(1,1)); cla = cos(orgllh(1,1));
slo = sin(orgllh(2,1)); clo = cos(orgllh(2,1));

C = [   -slo clo 0; ...
    -sla*clo -sla*slo cla; ...
    cla*clo cla*slo sla];

C = inv(C);

% Convert the points
difece(1,:)=C(1,1)*enu(1,:)+C(1,2)*enu(2,:)+C(1,3)*enu(3,:);
difece(2,:)=C(2,1)*enu(1,:)+C(2,2)*enu(2,:)+C(2,3)*enu(3,:);
difece(3,:)=C(3,1)*enu(1,:)+C(3,2)*enu(2,:)+C(3,3)*enu(3,:);

% Add the difference between the enu and ecef origins
ecef(1,:) = difece(1,:) + orgece(1);
ecef(2,:) = difece(2,:) + orgece(2);
ecef(3,:) = difece(3,:) + orgece(3);