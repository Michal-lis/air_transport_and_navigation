function [attr2,WPaprox]=waypoint()
attr2=create_attr();
%Function for creating waypoints in Google Earth
% Upper surface
attr2.altmode='relativeToGround';

% Edges
attr2.edgewidth=4;
attr2.edgecolor='00000033';

% Waypoints
attr2.wplabelscale=0.8;
attr2.wplabelcolor='ff00ffff';
%attr.wpiconurl='http://maps.google.com/mapfiles/kml/shapes/triangle.png';
attr2.wpiconscale=1.0;

%% IF
WPaprox(4).name='IF';
WPaprox(4).lat=sex2dec('N039º24''28.00"');
WPaprox(4).lon=sex2dec('W000º16''05.00"');
WPaprox(4).alt=0;
WPaprox(4).desc='Intermiediate Fix';
%% FAP PINEDO
WPaprox(5).name='FAP=PINEDO';
WPaprox(5).lat=sex2dec('N039º26''15.00"');
WPaprox(5).lon=sex2dec('W000º20''47.00"');
WPaprox(5).alt=0;
WPaprox(5).desc='FAP';
%% MULAT
WPaprox(6).name='IAF MULAT';
WPaprox(6).lat=sex2dec('N039º24''00.00"');
WPaprox(6).lon=sex2dec('W000º10''48.00"');
WPaprox(6).alt=0;
WPaprox(6).desc='Comienza STAR';
end