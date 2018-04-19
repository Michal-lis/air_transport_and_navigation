function MAIN3_dref_readXplane
clc; clear all; close all;
%addpath('lib/xplane','lib/kml');
filename='cessna-172';

ip='localhost';
port_Xplane=49000;
port_Matlab=49010;
freq=5;

% Select datarefs to read--------------------------------------------------
dataref{1}='sim/flightmodel/position/latitude';  % Latitude
dataref{2}='sim/flightmodel/position/longitude'; % Longitude
dataref{3}='sim/flightmodel/position/elevation'; % Altitude: the elevation above MSL of the aircraft

dataref{4}='sim/flightmodel/position/indicated_airspeed'; % IAS
dataref{5}='sim/flightmodel/position/true_airspeed';      % TAS
dataref{6}='sim/flightmodel/position/groundspeed';        % GS
dataref{7}='sim/flightmodel/position/vh_ind_fpm';         % VS

dataref{8}='sim/flightmodel/position/theta'; % Pitch
dataref{9}='sim/flightmodel/position/phi';   % Roll
dataref{10}='sim/flightmodel/position/psi';  % Heading

dataref{11}='sim/flightmodel/position/P';    % Roll rate;
dataref{12}='sim/flightmodel/position/Q';    % Pitch rate;
dataref{13}='sim/flightmodel/position/R';    % Yaw rate

dataref{14}='sim/flightmodel/position/alpha'; % Angle of Attack: pitch relative to the flown path
dataref{15}='sim/flightmodel/position/beta';  % Yaw: heading relative to the flown path
dataref{16}='sim/flightmodel/position/vpath'; % Vpath (vpath+alpha=theta)
dataref{17}='sim/flightmodel/position/hpath'; % Track angle (hpath+beta=psi)

dataref{18}='sim/flightmodel/controls/parkbrake'; % Parking brake

dataref{19}='sim/flightmodel/forces/fside_aero';
dataref{20}='sim/flightmodel/forces/fnrml_aero';
dataref{21}='sim/flightmodel/forces/faxil_aero';
%--------------------------------------------------------------------------

% Request datarefs to read-------------------------------------------------
dref_requestXPLANE(ip,port_Xplane,port_Matlab,freq,dataref);

% Loop: read, display and record for Google Earth -------------------------
n=1;
brake=0;
while brake==0   % Loop until parking break is released
    for i=1:150  % Loop 150 times 
        try
            % Read datarefs from X-Plane
            data=dref_readXPLANE();
            brake=data(18);
            % Display data
            dref_displayXPLANE(data);
        % Catch and handle errors
        catch err
            rethrow(err);
        end
        % Record trajectory
        wp(n).name=num2str(n);
        wp(n).desc='';
        wp(n).lat=data(1);
        wp(n).lon=data(2);
        wp(n).alt=data(3)/3.28;
        n=n+1;
        pause(2);
    end
end

% Display trajectory in Google Earth---------------------------------------
name=['routes/',filename,'.kml'];

attr=create_attr();
% General
attr.label='CESSNA 172';
attr.labelscale=1.0;

% Edges
 attr.edgewidth=6;
 attr.edgecolor='ff00ffff';
 
% Waypoints
 attr.wplabelscale=.1;
 attr.wpiconscale=0.1;

kmlwrite_polyline(wp,name,attr);

end