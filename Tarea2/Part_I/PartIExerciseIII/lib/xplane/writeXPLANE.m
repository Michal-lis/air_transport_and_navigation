function writeXPLANE(ip,port,actions)
% Send to Xplane via UDP the following actions:
%
% actions.ailerons  / sim/joystick/yoke_roll_ratio    float 900+ yes [-1..1] The deflection of the joystick axis controlling roll
% actions.elevators / sim/joystick/yoke_pitch_ratio   float 900+ yes [-1..1] The deflection of the joystick axis controlling pitch. Use override_joystick
% actions.rudder    / sim/joystick/yoke_heading_ratio float 900+	yes	[-1..1]	The deflection of the joystick axis controlling yaw. Use override_artstab
% actions.throttle  / sim/flightmodel/engine/ENGN_thro[0]  float [0..1] Throttle (per engine) as set by user, 0 = idle, 1 = max
% actions.brake     / sim/flightmodel/controls/parkbrake   float [0..1] Parking brake ratio
% actions.flaps     / sim/flightmodel/controls/flaprqst    float [0..1] Flap deflection
% actions.gear      / sim/flightmodel/movingparts/gear1def float [0..1] Landing gear 1 deflection
%
% Out of range values are ignored by writeXPLANE.
% ip   : IP address of Xplane / String / Example: '127.0.0.1' for localhost
% port : port of Xplane / Integer / Example: 9005

% Open the receiving socket
ssock = java.net.DatagramSocket();

value=uint8(true);
dataref='sim/operation/override/override_joystick';
UDPsendDREFchar(ssock,ip,port,dataref,value);
dataref='sim/operation/override/override_artstab';
UDPsendDREFchar(ssock,ip,port,dataref,value);

if abs(actions.ailerons)<=1
    dataref='sim/joystick/yoke_roll_ratio';
    %dataref='sim/joystick/FC_roll';
    value=single(actions.ailerons);
    UDPsendDREFfloat(ssock,ip,port,dataref,value);
end

if abs(actions.elevators)<=1
    dataref='sim/joystick/yoke_pitch_ratio';
    value=single(actions.elevators);
    UDPsendDREFfloat(ssock,ip,port,dataref,value);
end

if abs(actions.rudder)<=1
    dataref='sim/joystick/yoke_heading_ratio';
    value=single(actions.rudder);
    UDPsendDREFfloat(ssock,ip,port,dataref,value);
end

if actions.throttle>=0 && actions.throttle<=1
    dataref='sim/flightmodel/engine/ENGN_thro[0]';
    value=single(actions.throttle);
    UDPsendDREFfloat(ssock,ip,port,dataref,value);
end

if actions.brake>=0 && actions.brake<=1
    dataref='sim/flightmodel/controls/parkbrake';
    value=single(actions.brake);
    UDPsendDREFfloat(ssock,ip,port,dataref,value);
end

if actions.flaps>=0 && actions.flaps<=1
    dataref='sim/flightmodel/controls/flaprqst';
    value=single(actions.flaps);
    UDPsendDREFfloat(ssock,ip,port,dataref,value);
end

if actions.gear>=0 && actions.gear<=1
    value=single(actions.gear);
    dataref='sim/flightmodel/movingparts/gear1def';
    UDPsendDREFfloat(ssock,ip,port,dataref,value);
end

ssock.close();

end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function UDPsendDREFfloat(ssock,ip,port,dataref,value)
send_msg=uint8(zeros(1,509));
send_msg(1:4)=uint8('DREF');
send_msg(5)=uint8(0);

value=single(value);
value_bytes=typecast(value,'uint8');
len=6;
for j=1:4
    send_msg(len)=value_bytes(j);
    len=len+1;
end
dataref_bytes=uint8(dataref);
for j=1:length(dataref)
    send_msg(len)=dataref_bytes(j);
    len=len+1;
end
send_pkt = java.net.DatagramPacket(send_msg, size(send_msg,2),java.net.InetAddress.getByName(ip),port);
ssock.send(send_pkt);
clear send_pkt;
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function UDPsendDREFchar(ssock,ip,port,dataref,char)
send_msg=uint8(zeros(1,509));
send_msg(1:4)=uint8('DREF');
send_msg(5)=uint8(0);

value_bytes=typecast(char,'uint8');

send_msg(9)=value_bytes;
len=10;
dataref_bytes=uint8(dataref);
for j=1:length(dataref)
    send_msg(len)=dataref_bytes(j);
    len=len+1;
end
send_pkt = java.net.DatagramPacket(send_msg, size(send_msg,2),java.net.InetAddress.getByName(ip),port);
ssock.send(send_pkt);
clear send_pkt;
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Other useful functions
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function send_msg=UDPsendDATA(ip,port,index,data)
% Send DATA
% Log.txt: We are now receiving UDP data into index #
% index=uint32(32);
% data(1)=single(1);
% for j=2:8
%   data(j)=single(-999);
% end
%send_msg=UDPsendDATA(ss,xp_ip,xp_port_in,index,data);
%fprintf('Enviado:\n');
%dispDATA(index,data);

ssock = java.net.DatagramSocket();  
n=length(index);
send_msg=uint8(zeros(1,41));
send_msg(1:4)=uint8('DATA');
send_msg(5)=uint8(0);

index=uint32(index);
data=single(data);

for j=1:n
    index_bytes=typecast(index(j),'uint8');
    len=6;
    for k=1:4
        send_msg(len)=index_bytes(k);
        len=len+1;
    end
    for h=1:8
        data_bytes=typecast(data((j-1)*8+h),'uint8');
        for k=1:4
            send_msg(len)=data_bytes(k);
            len=len+1;
        end
    end
    send_pkt = java.net.DatagramPacket(send_msg, 41, java.net.InetAddress.getByName(ip),port);
    ssock.send(send_pkt);
end
close(ssock);
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function UDPsendCHAR(ip,port,char)
ssock = java.net.DatagramSocket();  
send_msg=uint8(zeros(1,6));
send_msg(1:4)=uint8('CHAR');
send_msg(5)=uint8(0);
send_msg(6)=uint8(char);
send_pkt = java.net.DatagramPacket(send_msg, size(send_msg,2), java.net.InetAddress.getByName(ip),port);
ssock.send(send_pkt);
close(ssock);
end