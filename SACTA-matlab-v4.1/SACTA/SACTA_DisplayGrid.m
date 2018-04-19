function status = SACTA_DisplayGrid(pLon, pLat)
% It sets a grid of meridians and parallels on the SACTA monitor.
%
% INPUT PARAMETERES
% pLon: array with the longitudes of each meridian
% pLat: array with the longitudes of each parallel
%
% RETURN VALUE
%  0 IF OK
%
% EXAMPLE
%   LonGrid = [-2.0 -1.0 0 1.0 2.0];
%   LatGrid = [37.0 38.0 39.0 40.0 41.0];
%   SACTA_DisplayGrid(LonGrid, LatGrid);
datos = '';
for i = 1:length(pLon)
    datos = [ datos ' ' num2str(pLon(i)) ];
end
datos = [ datos ' ; '];
for i = 1:length(pLat)
    datos = [ datos ' ' num2str(pLat(i)) ];
end
status = SACTA_SendCmd('SetGrid', datos);
