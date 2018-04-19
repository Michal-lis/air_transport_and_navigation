function MAIN_3
% READ A TRACK AND REPRESENT IT IN GOOGLE EARTH

clc; clear all;
addpath('SACTA','../lib/kml','../lib/geo');

%file='3420CA-05-Mar-2015';
%file='344548-05-Mar-2015';
file='19-Oct-2015_Arrival_A11AD2';

tsim=0;
k=1;
while tsim<intmax
    [traffics, tsim, real_time]=TRACK_read([file,'.txt']);
    if length(traffics)==1
        wp(k).name=num2str(k);
        wp(k).lon=traffics.lon;
        wp(k).lat=traffics.lat;
        wp(k).alt=traffics.alt;
        wp(k).desc=[' cs: ',traffics.callsign,', hex: ',traffics.hexId,', sq: ',traffics.squawk...
                     ', gs: ',num2str(traffics.gspeed),',tk: ',num2str(traffics.track),...
                     ', vr: ',num2str(traffics.vertRate)];
    end
    k=k+1;
end

%--------------------------------------------------------------------------
attr=create_attr();

attr.label='3C4847';
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
attr.wplabelcolor='ff0000ff';
%attr.wpiconurl='http://maps.google.com/mapfiles/kml/shapes/triangle.png';
attr.wpiconscale=0.0;

kmlwrite_polyline(wp,['tracks/',file,'.kml'],attr);

end