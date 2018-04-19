clc; clear all; close all;
addpath('lib/kml','lib/geo');

fp=xml2struct('LEMDSCEL_XML_1474620942');

for i=1:73%I read out in a buckle all the waypoints and the data from the file
    wp(i).name = fp.OFP.navlog.fix{1, i}.ident.Text
    wp(i).lat = str2num(fp.OFP.navlog.fix{1, i}.pos_lat.Text)
    wp(i).lon = str2num(fp.OFP.navlog.fix{1, i}.pos_long.Text)
    wp(i).alt = str2num(fp.OFP.navlog.fix{1, i}.altitude_feet.Text)
    wp(i).desc = fp.OFP.navlog.fix{1, i}.name.Text
end;

%--------------------------------------------------------------------------
attr=create_attr();

attr.label='LEVC-LEMD';
attr.labelscale=1.8;
attr.labelcolor='ff00ff00';
attr.iconurl='http://maps.google.com/mapfiles/kml/paddle/wht-circle.png';
attr.iconscale=1.5;
attr.extrude=false;
% Upper surface
attr.altmode='clampToGround';

% Edges
attr.edgewidth=2;
attr.edgecolor='ffffff00';

% Waypoints
attr.wplabelscale=1.2;
attr.wplabelcolor='fffffffff';
attr.wpiconurl='http://maps.google.com/mapfiles/kml/shapes/triangle.png';
attr.wpiconscale=1.0;

kmlwrite_polyline(wp,'LEVC-LEMD_LIDO.kml',attr);