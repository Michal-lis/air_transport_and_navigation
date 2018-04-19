function status = SACTA_DisplayMap(pMap)
% It draws a map in the SACTA monitor.
%
% INPUT PARAMETERS
%   pMap a two column array (longitude, latitude) of points.
%   An Inf value denotes that the previous coordinate is not linked to the
%   next one. In other words, lifting the pencil from the paper.
%
%   Example
%   Inf Inf
%	-1.000045	37.584565
%	-1.002392	37.584565
%	-1.003272	37.585445
%	-1.006792	37.585445
%   Inf Inf
%	-1.007672	37.586325
%	-1.007966	37.585738
%	-1.007966	37.584858
%
% RETURN VALUES
% It returns an "0" if success
%

datos = '';
% Format to send it to SACTA:
%  # -b
%	-1.000045	37.584565
%	-1.002392	37.584565
%	-1.003272	37.585445
%	-1.006792	37.585445
%  # -b
%	-1.007672	37.586325
%	-1.007966	37.585738
%	-1.007966	37.584858
[filas col] = size(pMap);
for i = 1:filas
    if pMap(i,1) == Inf
        datos = [ datos '# -b' 10];
    else 
        datos = [ datos num2str(pMap(i,1)) ' ' num2str(pMap(i,2)) 10 ];
    end
end
status = SACTA_SendCmd('SetMap', datos);
