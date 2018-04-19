function MAIN1_read_Xplane
clc; clear all; close all;
addpath('lib/xplane','lib/kml');
filename='cessna-172';
xp_port_out=49005;

n=1;
brake=0;

while brake==0   % Loop until parking break is released
    for i=1:150 % Loop 150 times 
        try
            % Read data from X-Plane
            [data]=readXPLANE(xp_port_out);
            brake=data.brake;
            % Display data
            displayXPLANE(data);
        % Catch and handle errors
        catch err
            rethrow(err);
        end
        wp(n).name=num2str(n);
        wp(n).desc='';
        wp(n).lat=data.position.latitude;
        wp(n).lon=data.position.longitude;
        wp(n).alt=(data.position.altitude)/3.28;
        n=n+1;
        %pause(2);
    end
end

%Display trajectory in Google Earth
name=['routes/',filename,'.kml'];

attr=create_attr();
% General
attr.label='CESSNA 172';
attr.labelscale=1.0;

% Edges
 attr.edgewidth=6;
 attr.edgecolor='ff00ffff';
 
% Waypoints
 attr.wplabelscale=.1;
 attr.wpiconscale=0.1;

kmlwrite_polyline(wp,name,attr);
end
