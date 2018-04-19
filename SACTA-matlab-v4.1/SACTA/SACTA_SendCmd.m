function iRet = SACTA_SendCmd(pCmd, pDatos)
% It sends a command via TCP/IP to the SACTA Monitor.
% RETURN VALUES
%  It returns an "0" if success
%  'ERROR CMD' if failed
%
% Available commands are:
%--------------------------------------------------------------------------
% PING
% 'Ping'
%--------------------------------------------------------------------------
% SETCOORD
% 'SetCoord
%
% Example:
% --------
% pLonO, pLonE, pLatN, pLatS
%--------------------------------------------------------------------------
% SETMAP
% 'SetMap'
%
% Example:
% --------
%  # -b
%	-1.000045	37.584565
%	-1.002392	37.584565
%	-1.003272	37.585445
%	-1.006792	37.585445
%  # -b
%	-1.007672	37.586325
%	-1.007966	37.585738
%	-1.007966	37.584858
%--------------------------------------------------------------------------
% SETGRID
% 'SetGrid' 
%
% Example:
% --------
% -2.0 -1.0 0 1.0 2.0 ; 37.0 38.0 39.0 40.0 41.0
%--------------------------------------------------------------------------
% SETROUTES
% 'SetRoutes'
%
% Example:
% --------
% #1\n-0.5 41.0\n0.0 39\n
% #2\n2 39.1\n0 39.1\n
% #3\n0 39.1\n-2 39.5
%--------------------------------------------------------------------------
% BEAMUPDATE
% 'BeamUpdate'
%  Beam angle HH:MM:SS\n
%  aicraftId HexIdent flightId Callsign Squawk Lon Lat Alt Vel Track VelVert color alert emergency SPI isOnGround date time\n
%  ....
%  Example
%  -------
% 4.9637 00:00:42
% 1 1631 3C7262 2402429 BER113N 2522 -2.53705 41.1019 35025 463.6 200.6 0 0 0 0 0 2015/01/28 11:22:31.993 1
% 2 17317 44A8AD 2402425 JAF59A 5522 -0.50824 38.6948 19775 325.3 31.3 2048 0 0 0 0 2015/01/28 11:22:32.400 1
% 3 7801 4CA73A 2402391 RYR907N 5572 0.51548 41.3778 36000 382.3 14.5 0 0 0 0 0 2015/01/28 11:22:32.400 1
%--------------------------------------------------------------------------
% DRAWPOLY
% 'DrawPoly'
% @Color
% #IDEN1
% Longitude Latitude\n
% Longitude Latidude\n
% #IDEN2
%
% Example:
% --------
% @3
% #1
% -1.00 37.58
% 0.5  39.5
% 2.5  40.5
% #2
% -2.00 39.5
% 0.7  40.5
%--------------------------------------------------------------------------
% DRAWWAYPT
% 'DrawWayPt'
% #IDEN1 Longitud Latitud color icon\n
% #IDEN2 Longitud Latitud color icon\n
%
% Example:
% --------
% #MULAT -1.00 37.58 4 O\n
% #OPERA -1.10 37.57 8 ^\n


global isFreeMat
global sRetorno
global sError
global sactaMonitor
global monitorip
global monitorport

TAM_OPERACION = 10;
TAM_TAMANYO = 10;
TAM_RESPUESTA = 1024;

iRet = 0;

if(isFreeMat == 0)
	iRet = sactaMonitor.sactaEnviaCmd(pCmd, pDatos);
	if iRet ~= 0
	    sError = sactaMonitor.getError().toCharArray();
	    fprintf('ERROR: %s\n', sError);
	else
	    sRetorno = sactaMonitor.getRet();
	end
else
	fd = tcp_connect(monitorip, monitorport);
	if(fd == -1)
		iRet = 1;
		disp('Error connecting to SACTA Monitor');
	else
		%Send the command
		tcp_send(fd, [pCmd, blanks(TAM_OPERACION)], TAM_OPERACION);
		%Send the size of the data
		tcp_send(fd, [num2str(size(pDatos, 2)), blanks(TAM_TAMANYO)], TAM_TAMANYO);
		%Send the data
		tcp_send(fd, pDatos, size(pDatos,2));
		sRetorno = blanks(TAM_RESPUESTA);
		tcp_recv(fd, sRetorno, size(sRetorno, 2));
	end
end
