function [data]=readXPLANE(port)
% Receive from Xplane via UDP the following data:
%
% data.ias                : Indicated Airspeed in mph
% data.tas                : True Airspeed in mph
% data.gs                 : Ground speed in mph
% data.vspeed             : Vertical speed in fpm
% data.brake              : Parking brakes. Boolean.
% data.eulers.pitch       : Pitch angle in degrees
% data.eulers.roll        : Roll angle in degrees
% data.eulers.heading     : Heading angle in degrees
% data.rates.pitch        : Pitch rate in degrees
% data.rates.roll         : Roll rate in degrees
% data.rates.heading      : Heading rate in degrees
% data.angles.alpha       : Angle of attack in degrees
% data.angles.beta        : Sideslip angle in degrees
% data.angles.vpath       : Vertical path angle in degrees
% data.angles.hpath       : Track angle in degrees
% data.position.latitude  : Latitude in decimal degrees
% data.position.longitude : Longitude in decimal degrees
% data.position.altitude  : Altitude in feet
%
% port : port of Xplane / Integer / Example: 49000

% Open the receiving socket
[index,udpdata]=UDPreceiveDATA(port);
%dispDATA(index,data);
n=length(index);
for j = 1:n
    switch index(j)
        case 3
            data.ias=udpdata((j-1)*8+6);
            data.tas=udpdata((j-1)*8+7);
            data.gs=udpdata((j-1)*8+8);
        case 4
            data.vspeed=udpdata((j-1)*8+3);
        case 14
            if udpdata((j-1)*8+2)~=0 
                data.brake=1;
            else data.brake=0;
            end
        case 16
            data.rates.pitch=udpdata((j-1)*8+1);
            data.rates.roll=udpdata((j-1)*8+2);
            data.rates.heading=udpdata((j-1)*8+3);
        case 17
            data.eulers.pitch=udpdata((j-1)*8+1);
            data.eulers.roll=udpdata((j-1)*8+2);
            data.eulers.heading=udpdata((j-1)*8+3);
        case 18
            data.angles.alpha=udpdata((j-1)*8+1);
%             data.angles.beta=udpdata((j-1)*8+2);
            data.angles.vpath=udpdata((j-1)*8+4);
            data.angles.hpath=udpdata((j-1)*8+3);   
        case 22
            data.position.latitude=udpdata((j-1)*8+1);
        case 23
            data.position.longitude=udpdata((j-1)*8+1);
        case 24
            data.position.altitude=udpdata((j-1)*8+1);
    end
end
end

function [index,data]=UDPreceiveDATA(port)
persistent recv_pkt;
if (isempty(recv_pkt))
    recv_pkt = java.net.DatagramPacket(uint8(zeros(1,1085)), 1085);
end
rsock = java.net.DatagramSocket(port);
rsock.receive(recv_pkt);
rsock.close();

recv_data=recv_pkt.getData();

n=recv_pkt.getLength();
i=0;
for j = 6:36:n
    i=i+1;
    index_bytes=recv_data(j:j+3);
    index(i)=typecast(index_bytes,'uint32');
    for k=1:8
        data_bytes=recv_data(j+4*k:j+4*k+3);
        data((i-1)*8+k)=typecast(data_bytes,'single');
        data=double(data);
    end
end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% function dispDATA(index,data)
% n=length(index);
% fprintf('\n');
% for j = 1:n
%         switch index(j)
%         case 3
%             label='airspeed';
%         case 8
%             label='joystick';
%         case 11
%             label='ale/ele/tim';
%         case 17
%             label='rates';
%         case 18
%             label='eulers';
%         case 22
%             label='lat';
%         case 23
%             label='long';
%         case 24
%             label='alt';
%         case 37
%             label='RPM';
%         case 70
%             label='def ale';
%         case 74
%             label='def prof';
%         case 75
%             label='def dir';
%         case 76
%             label='fre gui';
%         otherwise
%             label=num2str(index(j));
%     end
%     %fprintf('%2d>[%2d]):',j,index(j));
%     fprintf('%11s:',label);
%     for k=1:8
%         fprintf('\t(%d) %5.5g',k, data((j-1)*8+k));  
%     end
%     fprintf('\n');
% end
% fprintf('\n');
% end

