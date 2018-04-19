function [ rm,d,tau ] = cpa3d( r,c )
% Closest Point of Approach (3D version) computed from:
% r relative position of AC2 (ft)
% c relative airspeed of AC2 (ft/s)
% It returns:
% rm: relative position vector of the PCA in ft
% d: distance to PCA in ft
% tau: time to PCA in sec
cunid=c/norm(c);
rc=cross(r,cunid);
rm=cross(cunid,rc);
d=norm(rm);
cc=dot(c,c);
rc2=dot(r,c);
tau=-(rc2/cc);
end

