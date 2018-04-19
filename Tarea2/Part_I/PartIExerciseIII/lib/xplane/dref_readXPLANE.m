function data=dref_readXPLANE() 
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
persistent pindex pdata

if isempty(pindex)
    pindex=zeros(n_dref);
    pdata=zeros(n_dref);
end

sock = java.net.DatagramSocket(myport);

recv_pkt = java.net.DatagramPacket(uint8(zeros(1,256)), 256);
sock.receive(recv_pkt);

sock.close();

recv_data=recv_pkt.getData();
n=recv_pkt.getLength()-5;
recv_data=recv_data(6:end);
n=n/8;

for i=1:n
    pindex(i)=typecast(recv_data((i-1)*8+1:(i-1)*8+4),'uint32');
    pdata(pindex(i)) =typecast(recv_data((i-1)*8+5:(i-1)*8+8),'single');
end
data=pdata;
index=pindex;

end
