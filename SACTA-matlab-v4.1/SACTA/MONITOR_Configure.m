function iRet = MONITOR_Configure(mode, beam)
% It establishes the monitor that will be used for the radar presentation.
% The refreshing period of the information is 1 second.
% It also tries to launch the monitor automatically.
% If the monitor is not automatically launched, please execute:
% SACTA/monitor.jar.
%
% INPUT PARAMETERS
% mode: it is double specifying the monitor:
%       1: SACTA monitor
%       2: GOOGLE EARTH representation
%       3: CONSOLE table 
% beam: it simulates a rotating radar beam on SACTA if this is enabled
%       in Show->Beam. Just for fun... This is not really a primary radar...
%
% OUTPUT PARAMETERS
% iRet indicates if the corresponding monitor was successfully launched:
% !=-1: success
% -1  : failed
%

global isFreeMat

isFreeMat_int = 0;
if isempty(isFreeMat)
    try
        echo;
        echo;
        javaclasspath('./SACTA/antena.jar', './SACTA/monitor.jar');
        isFreeMat_int = 0;
    catch
        freemat_net_init;
        isFreeMat_int = 1;
    end
end

global isFreeMat
global modo_monitor
global gBeam
global monitorip
global monitorport
global sactaMonitor

isFreeMat = isFreeMat_int;
gBeam=beam;
modo_monitor=mode;

if mode == 2
    launcher='launcher.kml';
    fid3=fopen(launcher, 'w');
    dt=1;
    fprintf(fid3,'<Document>\n\t<visibility>1</visibility>\n\t<NetworkLink>\n\t\t<name>Sacta - Earth Launcher</name>\n\t\t<refreshVisibility>0</refreshVisibility>\n\t\t<flyToView>0</flyToView>\n\t\t<Link>\n\t\t\t<href>%s</href>\n\t\t\t<refreshMode>onInterval</refreshMode>\n\t\t\t<refreshInterval>%d</refreshInterval>\n\t\t</Link>\n\t</NetworkLink>\n</Document>\n',fullfile(pwd,'SACTA.kml'), dt);
    fclose(fid3);
    if(isFreeMat == 0)
        ejecuta(launcher);
    else
        fprintf(2,'Could not launch GoogleEarth automatically\n\t Please open file: %s\n',fullfile(pwd,fichero));
        input('Pulsa Intro para continuar');
    end
    iRet = 0;
    
elseif mode== 1
    monitorip = '127.0.0.1';
    monitorport = 4000;
    
    if(isFreeMat == 0)
        sactaMonitor = interficie.SactaTcpLibs(monitorip,monitorport);
    else
        %Nothing to do in FreeMat
    end
    
    iRet = SACTA_Ping();
    if iRet == 0
        fprintf('Monitor SACTA already in execution\n');
    else
        fprintf('Trying to start monitor SACTA\n');
        ejecuta('SACTA/monitor.jar');
        pause(5);
    end
    
    iRet = SACTA_Ping();
    if iRet ~= 0
        fprintf(2,'Could not launch monitor SACTA automatically\n');
        fprintf(2,'Please run manually file: %s\n', fullfile(pwd,'SACTA/monitor.jar'));
        input('Type Intro to continue');
    else
        fprintf('Monitor SACTA succesfully started\n');
    end
else
    iRet = 0;
end
end

function ejecuta(fichero)
if(exist('ispc') && ispc )
    winopen(fichero);
elseif(exist('ismac') && ismac)
    system(['open ', fichero]);
    %else
    %	system(['google-earth ', FICHERO]);
else
    fprintf(2, '\n**************************\n\tCould not launch %s automatically\n\tOpen it manually\n**************************\n', fullfile(pwd,fichero));
    input(2,'Type Intro to continue');
end
end
