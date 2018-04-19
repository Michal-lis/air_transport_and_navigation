function status = SACTA_DisplayWaypoints(wpts)
% It displays a set of waypoints in the SACTA monitor.
% INPUT PARAMETERS
% wpts: an array of waypoints. 
%       A waypoint is an struct with the following fields:
% wpts(i).name  String
% wpts(i).lon   double
% wpts(i).lat   double
% wpts(i).color integer in range [1..10]. See README.colors
% wpts(i).icon  String 
%
% RETURN VALUES
% It returns an "0" if success
%
datos = '';

% Format to send it to SACTA.
% #IDEN1 Longitud Latitud color icon\n
% #IDEN2 Longitud Latitud color icon\n
% Example
% #MULAT -1.00 37.58 4 ?\n
% #OPERA -1.10 37.57 8 ?\n

for i = 1:length(wpts)
    datos = [ datos '#' wpts(i).name];  % el 10 es retorno de línea
    icon=strrep(wpts(i).icon, ' ', '_');
    if isempty(icon)
        icon='X';
    end        
    datos = [ datos ' ' num2str(wpts(i).lon) ' ' num2str(wpts(i).lat) ' ' num2str(wpts(i).color) ' ' icon  10];
end
status = SACTA_SendCmd('DrawWayPt', datos);
end