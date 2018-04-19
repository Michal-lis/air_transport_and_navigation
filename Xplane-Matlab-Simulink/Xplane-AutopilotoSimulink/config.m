% Copyright 2012 Borja Fons Albert, Hèctor Usach Molina, Joan Vila Carbó.
% All rights reserved.
% 
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are
% met:
% 
%  1. Redistributions of source code must retain the above copyright
%     notice, this list of conditions and the following disclaimer.
% 
%  2. Redistributions in binary form must reproduce the above copyright
%     notice, this list of conditions and the following disclaimer in the
%     documentation and/or other materials provided with the distribution.
% 
% THIS SOFTWARE IS PROVIDED BY BORJA FONS ALBERT, HÈCTOR USACH MOLINA AND
% JOAN VILA CARBÓ ''AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
% INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
% AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
% BORJA FONS ALBERT, HÈCTOR USACH MOLINA AND JOAN VILA CARBÓ OR
% CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
% EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
% PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
% PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
% LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
% NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
% SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
% 
% The views and conclusions contained in the software and documentation are
% those of the authors and should not be interpreted as representing
% official policies, either expressed or implied, of Borja Fons Albert,
% Hèctor Usach Molina and Joan Vila Carbó.


  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                      PARAMETROS DE CONFIGURACION
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  clc; clear all;

% Puertos e IP
  XPLANE_PORT_IN  = 9005;
  XPLANE_PORT_OUT = 49000;
  %XPLANE_IP       = '158.42.40.131';
  XPLANE_IP       = '127.0.0.1';

% Simulacion
  Ts      = 1/10;  %Frecuencia de funcionamiento
  Tfin    = 500.0; %Duracion de la simulacion

% Ruta
  FASE = 2;
  addpath ./Rutas/
%  run wp_valencia
  run wp_SGO_VLC

% Modo de control
  MODE = 1; % 0 -> HOLD || 1 -> RUTA
  heading_value = 180;  %deg
  alt_value     = 2000; %ft
  speed_value   = 115;  %mph

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                    FIN PARAMETROS DE CONFIGURACION
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



% EJECUTAR CONFIGURACION
% Esto no deberia modificarse

disp('*** CONFIGURACION *********************')

addpath ./c172_Model/
addpath ./Control/
addpath ./Resources/
addpath ./Trim
addpath ./Rutas/
addpath ./Simulink_Models/

%==========================================================================
% #define
deg2rad = pi/180;
mph2fps = 1.46667;
ROLL_CONTROL = 0;
HEADING_CONTROL = 1;
VPATH_CONTROL = 0;
ALT_CONTROL = 1;

dref_joystick = 'sim/operation/override/override_joystick';
dref_artstab  = 'sim/operation/override/override_artstab';
dref_elev     = 'sim/joystick/yoke_pitch_ratio';
dref_engn     = 'sim/flightmodel/engine/ENGN_thro[0]';
dref_ailerons = 'sim/joystick/yoke_roll_ratio';
dref_rudder   = 'sim/joystick/yoke_heading_ratio';
dref_flaps    = 'sim/flightmodel/controls/flaprqst';

%==========================================================================
% Ajustes simulacion -----
Ts = round(Ts*1e4)/1e4;
if Tfin/Ts ~= round(Tfin/Ts)
    Tfin = round(Tfin/Ts)*Ts;
end
fprintf('*** %s - Simulacion ajustada con:\n',datestr(now, 'HH:mm:ss'));
fprintf('\t\t- periodo %.2fs\n', Ts);
fprintf('\t\t- duracion %.1fs\n', Tfin);

%==========================================================================
% Ajustes control -----
% Verificar modo
if MODE == 1
    HOLD_HEADING = 0;
    HOLD_ALT     = 0;
    HOLD_SPEED   = 0;
    fprintf('*** %s - Modo en RUTA\n', datestr(now, 'HH:mm:ss'));
else
    HOLD_HEADING = 1;
    HOLD_ALT     = 1;
    HOLD_SPEED   = 1;
    fprintf('*** %s - Modo HOLD\n', datestr(now, 'HH:mm:ss'));
end

% Datos de la aeronave
fprintf('*** %s - Cargando modelo\n', datestr(now, 'HH:mm:ss'))
run c172Model

% Trim aproximado
fprintf('*** %s - Calculando Trim\n', datestr(now, 'HH:mm:ss'))
altitude_trim  = 2000;
airspeed_trim  = 200;
pitch_trim     = 0.0175;
pitchrate_trim = 0;
vpath_trim     = 0;
vspeed_trim    = 0;
rollrate_trim  = 0;
yawrate_trim   = 0;
roll_trim      = 0;
heading_trim   = 0;
beta_trim      = 0;
elevators_trim = 0;
ailerons_trim  = 0;
rudder_trim    = 0;
throttle_trim  = 0;

[xTrim, uTrim, exitflag] = Trim(FASE, airspeed_trim, altitude_trim, vpath_trim);

pitch_trim     = xTrim(2);
pitchRate_trim = xTrim(3);
elevators_trim = uTrim(1);
throttle_trim  = uTrim(2);

%==========================================================================
% Control
fprintf('*** %s - Calculando Control\n', datestr(now, 'HH:mm:ss'))
[K_vpath,~,~,~,~,~,~,~] = ControlVpath(xTrim,FASE,Ts);

[K_alt,~,~,~,~,~,~,~] = ControlAltitude(xTrim,FASE,Ts);

[K_roll,~,~,~,~,~,~,~] = ControlTurn(xTrim,FASE,Ts);

[K_heading,~,~,~,~,~,~,~] = ControlHeading(xTrim,FASE,Ts);

Kp = 0.1; Kd = 0.2;

%==========================================================================
% Ajustes conexion -----
% Buffers
BUFFER_LEN_IN   = 1085;  
BUFFER_LEN_OUT  = 509;

% Prueba comunicacion
rsock = java.net.DatagramSocket(XPLANE_PORT_OUT);
rsock.setSoTimeout(4000);
recv_pkt = java.net.DatagramPacket(uint8(zeros(1,1085)), 1085);
try
    rsock.receive(recv_pkt);
    close(rsock)
catch
    close(rsock)
    warning('*** No se estan recibiendo datos');
    return
end

fprintf('*** %s - Comunicacion ajustada con:\n', datestr(now, 'HH:mm:ss'));
fprintf('\t\t- puerto de entrada %d \n', XPLANE_PORT_OUT);
fprintf('\t\t- puerto de salida %d\n', XPLANE_PORT_IN);
fprintf('\t\t- IP de Xplane %s\n', XPLANE_IP);

% Envio de datarefs de override
dataref1 = 'sim/operation/override/override_joystick';
dataref2 = 'sim/operation/override/override_airstab';

send_msg=uint8(zeros(1,509));
send_msg(1:4)=uint8('DREF');
send_msg(5)=uint8(0);

send_msg(9)=uint8(1);
len=10;
dataref_bytes=uint8(dataref1);
for j=1:length(dataref1)
    send_msg(len)=dataref_bytes(j);
    len=len+1;
end

ssock = java.net.DatagramSocket();
send_pkt = java.net.DatagramPacket(send_msg, size(send_msg,2),java.net.InetAddress.getByName(XPLANE_IP), XPLANE_PORT_IN);
ssock.send(send_pkt);
close(ssock)

send_msg=uint8(zeros(1,509));
send_msg(1:4)=uint8('DREF');
send_msg(5)=uint8(0);

send_msg(9)=uint8(1);
len=10;
dataref_bytes=uint8(dataref2);
for j=1:length(dataref2)
    send_msg(len)=dataref_bytes(j);
    len=len+1;
end

ssock = java.net.DatagramSocket();
send_pkt = java.net.DatagramPacket(send_msg, size(send_msg,2),java.net.InetAddress.getByName(XPLANE_IP), XPLANE_PORT_IN);
ssock.send(send_pkt);
close(ssock)


fprintf('*** %s - Hecho\n', datestr(now, 'HH:mm:ss'))
fprintf('\n')
fprintf('*** %s - Abriendo el modelo de Simulink\n', datestr(now, 'HH:mm:ss'))
open_system('xplane_interface')