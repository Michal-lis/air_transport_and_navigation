function status = SACTA_SetCoord(pLonW, pLonE, pLatN, pLatS)
% It sets the coordinates of the limits of the SACTA monitor.
%
% INPUT PARAMETERES
% pLonW: longitude of the WEST limit
% pLonE: longitude of the EAST limit
% pLonN: latitude of the NORTH limit
% pLonS: latitude of the SOUTH limit
%
% RETURN VALUE
%  0 IF OK
%
datos = sprintf('%g %g %g %g', pLonW, pLonE, pLatN, pLatS);
status = SACTA_SendCmd('SetCoord', datos);
