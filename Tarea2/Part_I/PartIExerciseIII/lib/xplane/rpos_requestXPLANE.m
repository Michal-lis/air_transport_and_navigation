function sock=rpos_requestXPLANE(ip, port, freq) 
% Send RPOS message XPlane
% It returns:
% sock: Socket to receive the information using rpos_recvXPLANE(sock)
%
% ?RPOS? (null-terminated!), and then this struct:
% 
% struct rpos_struct_in
% {
% 	xint rpos_freq;
% };
% 
% rpos_freq IS ACTUALLY THE NUMBER OF TIMES PER SECOND YOU WANT X-PLANE TO SEND THIS DATA! ENTER 0 TO NOT SEND IT AT ALL!) to X-Plane by UDP, sending to port 49000.

send_msg=uint8(zeros(1,6));
send_msg(1:4)=uint8('RPOS');
send_msg(5)=uint8(0);


freq=uint32(freq);
freq_bytes=typecast(freq,'uint8');
for k=1:4
    send_msg(k+5)=freq_bytes(k);
end
send_msg

sock = java.net.DatagramSocket();  
send_pkt = java.net.DatagramPacket(send_msg, size(send_msg,2), java.net.InetAddress.getByName(ip),port);
sock.send(send_pkt);
end
