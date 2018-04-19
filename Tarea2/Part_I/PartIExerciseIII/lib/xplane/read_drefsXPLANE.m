function drefs=read_drefsXPLANE(port)

recv_pkt = java.net.DatagramPacket(uint8(zeros(1,512)), 512);
rsock = java.net.DatagramSocket(port);

token='';
while(~strcmp(token','DREF@'))
    rsock.receive(recv_pkt);
    recv_data=recv_pkt.getData();
    char(recv_data)'
    n=recv_pkt.getLength();    
    buffer=char(recv_data(1:n));
    [token, remain]=strtok(buffer,'$'); 
end
    
remain=remain(2:end);

i=1;
while (~strcmp(remain',','))
    [token, remain]=strtok(remain,',');
    drefs(i)=str2num(token');
    i=i+1;
end
rsock.close();
end
