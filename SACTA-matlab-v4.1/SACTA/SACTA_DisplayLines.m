function status = SACTA_DisplayLines(lines,color)
% It draws a set of lines in the SACTA monitor.
% INPUT PARAMETERS
% lines: this parameter is defined by a cell array of lines:
%       lines={line1, line2, line3}
%       Each line is defined by two points:
%       line1 = [ lon1, lat1; lon2, lat2];
%       line2 = [ lon3, lat3; lon4, lat4];
%       line3 = [ lon5, lat5; lon6, lat6];
% color: a numeric value in the range [1..10]. See README.colors.
%
% RETURN VALUES
% It returns an "0" if success
%
datos = '';

% Data format.
% @Color
% #IDEN1
% Longitude Latitude\n
% Longitude Latidude\n
% 			....
% #IDEN2
%
% Example:
% @3
% #1
% -1.00 37.58
% 0.5  39.5
% 2.5  40.5
% #2
% -2.00 39.5
% 0.7  40.5

for i = 1:length(lines)
    datos = [ datos '#' num2str(i)];  
    for j = 1:length(lines{i})
        datos = [ datos 10 num2str(lines{i}(j,1)) ' ' num2str(lines{i}(j,2))]; % el 10 es retorno de línea
    end
    datos = [ datos 10];
end
datos= [ '@' num2str(color) 10 datos];
status = SACTA_SendCmd('DrawPoly', datos);
end
