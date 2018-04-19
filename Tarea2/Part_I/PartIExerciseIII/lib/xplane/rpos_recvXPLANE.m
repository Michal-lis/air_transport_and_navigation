function data=rpos_recvXPLANE(sock) 
% Receive an RPOS message from XPlane
% sock: socket returned by rpos_requestXPLANE
% It returns:

%
% Now, each frame, X-Plane will send the minimum data needed to drive an external visual or moving map to the same IP address and port number you sent this message from! Easy!
% This will simply be the 5 chars ?RPOS? (plus a NULL at the end!) followed by a struct as follows: (machine-native floats and doubles, 4-byte struct alignment)
% 
% struct position_struct
% {
% 	double longitude,latitude;				// double is needed for smooth data here. this is good for simple 2-d maps
% 	float elevation_MSL,elevation_AGL;		// we have AGL so you can correct the heigh above ground for your visuals to match X-Plane, if desired
% 	float pitch,heading,roll;				// this is for making your own visuals
% 	float Vx,Vy,Vz;						// Vxyz are the speeds in the east, up, and south directions, in meters per second. you can use these to predict longitude, latitude, and elevation smoothly.
% 	float Pdeg,Qdeg,Rdeg;				// P Q R are the roll, pitch, and yaw rates, in aircraft axis, in degrees per second. you can use these to predict pitch, heading, and roll smoothly.
% }

recv_pkt = java.net.DatagramPacket(uint8(zeros(1,69)), 69);
sock.receive(recv_pkt);

recv_data=recv_pkt.getData();
%n=recv_pkt.getLength()

lon=recv_data(6:13);
lat=recv_data(14:21);

ele_msl=recv_data(22:25);
ele_agl=recv_data(26:29);

pitch=recv_data(30:33);
heading=recv_data(34:37);
roll=recv_data(38:41);

vx=recv_data(42:45);
vy=recv_data(46:49);
vz=recv_data(50:53);

roll_r=recv_data(54:57);
pitch_r=recv_data(58:61);
yaw_r=recv_data(62:65);

data.lon=typecast(lon,'double');
data.lat=typecast(lat,'double');
data.ele_msl=typecast(ele_msl,'single');
data.ele_agl=typecast(ele_agl,'single');
data.pitch=typecast(pitch,'single');
data.heading=typecast(heading,'single');
data.roll=typecast(roll,'single');
data.vx=typecast(vx,'single');
data.vy=typecast(vy,'single');
data.vz=typecast(vz,'single');
data.pitch_r=typecast(pitch_r,'single');
data.yaw_r=typecast(yaw_r,'single');
data.roll_r=typecast(roll_r,'single');

% DO NOT close(sock) if you do not want to stop the reception...
end