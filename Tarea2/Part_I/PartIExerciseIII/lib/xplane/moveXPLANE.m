function moveXPLANE(ip, port, plane, position, eulers, controls) 
% Move a plane to agiven position. 
% It uses the VEH1 UDP message.
%
% ip   : IP address of Xplane / String / Example: '127.0.0.1' for localhost
% port : port of Xplane / Integer / Example: 49000
% plane             : uint32 - plane index. Use 0 for main plane
% position.lat      : double - latitude in degrees of desired position
% position.lon      : double - longitude in degrees of desired position
% position.alt      : double - elevation in feet of desired position
% eulers.heading    : single - heading in degrees at desired position
% eulers.pitch      : single - pitch in degrees at desired position
% eulers.roll       : single - roll in degrees at desired position
% controls.gear     : single [0..1] - value of gear at desired position
% controls.flaps    : single [0..1] - value of flaps at desired position
% controls.throttle : single [0..1] - value of thrust at desired position

send_msg=uint8(zeros(1,6));
send_msg(1:4)=uint8('VEH1');
send_msg(5)=uint8(0);

p_index=uint32(plane);
p_index_bytes=typecast(p_index,'uint8');
for k=1:4
   send_msg(k+5)=p_index_bytes(k);
end
m=length(send_msg);

p_index=uint32(plane);
p_index_bytes=typecast(p_index,'uint8');
for k=1:4
   send_msg(k+m)=p_index_bytes(k);
end
m=length(send_msg);

lat_bytes=typecast(position.lat ,'uint8');
for k=1:8
   send_msg(k+m)=lat_bytes(k);
end
m=length(send_msg);

lon_bytes=typecast(position.lon ,'uint8');
for k=1:8
   send_msg(k+m)=lon_bytes(k);
end
m=length(send_msg);

ele_bytes=typecast(position.alt,'uint8');
for k=1:8
   send_msg(k+m)=ele_bytes(k);
end
m=length(send_msg);

heading=single(eulers.heading);
heading_bytes=typecast(heading,'uint8');
for k=1:4
   send_msg(k+m)=heading_bytes(k);
end
m=length(send_msg);

pitch=single(eulers.pitch);
pitch_bytes=typecast(pitch,'uint8');
for k=1:4
   send_msg(k+m)=pitch_bytes(k);
end
m=length(send_msg);

roll=single(eulers.roll);
roll_bytes=typecast(roll,'uint8');
for k=1:4
   send_msg(k+m)=roll_bytes(k);
end
m=length(send_msg);

gear=single(controls.gear);
gear_bytes=typecast(gear,'uint8');
for k=1:4
   send_msg(k+m)=gear_bytes(k);
end
m=length(send_msg);

flap=single(controls.flaps);
flap_bytes=typecast(flap,'uint8');
for k=1:4
   send_msg(k+m)=flap_bytes(k);
end
m=length(send_msg);

throttle=single(controls.throttle);
throttle_bytes=typecast(throttle,'uint8');
for k=1:4
   send_msg(k+m)=throttle_bytes(k);
end

ssock = java.net.DatagramSocket();

send_pkt = java.net.DatagramPacket(send_msg, size(send_msg,2), java.net.InetAddress.getByName(ip),port);
ssock.send(send_pkt);

close(ssock);
end