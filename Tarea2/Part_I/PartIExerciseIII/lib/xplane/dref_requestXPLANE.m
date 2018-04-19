function sock=dref_requestXPLANE(ip,port_Xplane,port_Matlab,freq,dataref)
% Send in the 5 chars RREF (null-terminated!) plus this struct:
% 
% struct dref_struct_in
% {
% 	xint dref_freq		;
% 	xint dref_en		;
% 	xchr dref_string[400]	;
% };
% 
% Where dref_freq IS ACTUALLY THE NUMBER OF TIMES PER SECOND YOU WANT X-PLANE TO SEND THIS DATA!
% Where dref_en is the integer code you want X-Plane to send back with the dataref value so you can tell WHICH dataref X-Plane is giving you! (since you are likely to ask for MANY different datarefs!)
% Where dref_string is the dataref string that you want X-Plane to send to you!
% 
% And, if the dataref is to an ARRAY of values (like engine thrust, since there can be 8 engines), just add [xxx] to the end, where ?xxx? is the array index you want X-Plane to send!
% The [ and ] should simply surround the number to indicate that the number is the index you want.
% So, send in ?sim/flightmodel/engine/POINT_thrust[1] ?to have X-Plane send the second engine, for example (since we start at 0!)
% 
% X-Plane will send the message right back to the IP address and port number you sent the RREF command from.
% You will get:
% 
% struct dref_struct_out
% {
% 	xint dref_en	;
% 	xflt dref_flt	;
% };
% 
% Where dref_en is the integer code you sent in for this dataref in the struct above.
% Where dref_flt is the dataref value, in machine-native floating-point value, even for ints!
% 
% So, of course, you can send in all the RREF messages you want, to get all the dataref values back that you want!

global n_dref myport

myport=port_Matlab;

n_dref= length(dataref);

sock = java.net.DatagramSocket(port_Matlab);

for i=1:n_dref
    dataref{i}(end+1:400)=zeros(1,400-length(dataref{i}));
 
    send_msg=uint8(zeros(1,6));
    send_msg(1:4)=uint8('RREF');
    send_msg(5)=uint8(0);
    
    
    freq=uint32(freq);
    freq_bytes=typecast(freq,'uint8');
    for k=1:4
        send_msg(k+5)=freq_bytes(k);
    end
    m=length(send_msg);
    
    index=uint32(i);
    index_bytes=typecast(index,'uint8');
    for k=1:4
        send_msg(k+m)=index_bytes(k);
    end
    m=length(send_msg);
    
    for k=1:length(dataref{i})
        send_msg(k+m)=dataref{i}(k);
    end
    
    send_pkt = java.net.DatagramPacket(send_msg, size(send_msg,2), java.net.InetAddress.getByName(ip),port_Xplane);
    sock.send(send_pkt);
end
sock.close();

end

