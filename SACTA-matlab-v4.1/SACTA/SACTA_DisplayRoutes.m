function status = SACTA_DisplayRoutes(pRoutes)
% It draws a set of airways in the SACTA monitor.
%
% INPUT PARAMETERS
% pRoutes: is a cell array of routes.
%          Each cell consists of an array of size Nx2 
%          where N is the number of waypoints that define the route.
%          Each row of the array defines a waypoint of the route and it
%          consists of two columns: longitude and latitude.
%
% Example:
% ---------
%       route1 = [ -0.5 41.0; 0.0 39; 0.5 38 ];
%       route2 = [ 2 39.1; 0 39.1];
%       route3 = [ 0 39.1; -2 39.5];
%       routes = { route1 route2 route3 };
%
% RETURN VALUES
% It returns an "0" if success

datos = '';
% % Format to send it to SACTA:
% #1\n-0.5 41.0\n0.0 39\n
% #2\n2 39.1\n0 39.1\n
% #3\n0 39.1\n-2 39.5

for i = 1:length(pRoutes)
    datos = [ datos '#' num2str(i)];  
    for j = 1:length(pRoutes{i})
        datos = [ datos 10 num2str(pRoutes{i}(j,1)) ' ' num2str(pRoutes{i}(j,2))]; % el 10 es retorno de línea
    end
    datos = [ datos 10];
end
status = SACTA_SendCmd('SetRoutes', datos);
