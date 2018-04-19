function dref_writeXPLANE(ip,port,datarefs,values)
% Send to Xplane via UDP the indicated datarefs

% Open the receiving socket
ssock = java.net.DatagramSocket();

value=uint8(true);
dref='sim/operation/override/override_joystick';
UDPsendDREFchar(ssock,ip,port,dref,value);
dref='sim/operation/override/override_artstab';
UDPsendDREFchar(ssock,ip,port,dref,value);

if ~strcmp(class(datarefs),'cell')
   dataref{1}=datarefs;
else
   dataref=datarefs;
end

for i=1:length(dataref)
    send_msg=uint8(zeros(1,509));
    send_msg(1:4)=uint8('DREF');
    send_msg(5)=uint8(0);
    
    value=single(values(i));
    value_bytes=typecast(value,'uint8');
    len=6;
    for j=1:4
        send_msg(len)=value_bytes(j);
        len=len+1;
    end
    
    dataref_bytes=uint8(dataref{i});
    for j=1:length(dataref{i})
        send_msg(len)=dataref_bytes(j);
        len=len+1;
    end
    send_pkt = java.net.DatagramPacket(send_msg, size(send_msg,2),java.net.InetAddress.getByName(ip),port);
    ssock.send(send_pkt);
    clear send_pkt;
end

ssock.close();

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