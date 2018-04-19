clc; clear all;
addpath('SACTA-matlab-v4.1/SACTA','lib/kml','lib/geo','SACTA-matlab-v4.1/tracks');
%file='05-Jan-2017_Arrival_4CA4EE'; %Flight from Brussels
file='05-Jan-2017_Arrival_4CABC2'; %Flight from Cologne
tsim=0;
k=1;
while tsim<intmax
    [traffics, tsim, real_time]=TRACK_read([file,'.txt']);
    if length(traffics)==1
        wp(k).name=num2str(k);
        wp(k).lon=traffics.lon;
        wp(k).lat=traffics.lat;
        if traffics.alt<0
            wp(k).alt=0;
        else 
            wp(k).alt=traffics.alt;
        end
        wp(k).desc=[' cs: ',traffics.callsign,', hex: ',traffics.hexId,', sq: ',traffics.squawk...
                     ', gs: ',num2str(traffics.gspeed),',tk: ',num2str(traffics.track),...
                     ', vr: ',num2str(traffics.vertRate)];
    end
    k=k+1;
end

%% --------------------------------------------------------------------------
attr=create_attr();

attr.label='Cologne';
%attr.labelscale=1.8;
%attr.labelcolor='ffffeeee';
%attr.iconurl='http://maps.google.com/mapfiles/kml/paddle/wht-circle.png';
%attr.iconscale=1.5;
attr.extrude=false;

% Upper surface
attr.altmode='relativeToGround';

% Edges
attr.edgewidth=4;
attr.edgecolor='ff0099ff';

% Waypoints
attr.wplabelscale=0.0;
attr.wplabelcolor='ff0099ff';
%attr.wpiconurl='http://maps.google.com/mapfiles/kml/shapes/triangle.png';
attr.wpiconscale=0.0;

%% CTR and TMA
levc_ctr
levc_tma
%% Tracks
kmlwrite_polyline(wp,['SACTA-matlab-v4.1',file,'.kml'],attr);
%% Marking the IAF, IF and other important files
[attr2,WPaprox]=waypoint();
kmlwrite_polyline(WPaprox,'waypoints.kml',attr2);

