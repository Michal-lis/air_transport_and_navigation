clc; clear all;
ip='localhost';
port=49000;
freq=5;

sock=rpos_requestXPLANE(ip, port, freq);

for i=1:10
    clc;
    data=rpos_recvXPLANE(sock)
end

sock.close();