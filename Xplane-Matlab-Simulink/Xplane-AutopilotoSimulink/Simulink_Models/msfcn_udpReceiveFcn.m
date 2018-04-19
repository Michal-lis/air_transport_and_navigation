function msfcn_udpReceiveFcn(block)
% Copyright 2012 Borja Fons Albert, Hèctor Usach Molina, Joan Vila Carbó.
% All rights reserved.
% 
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are
% met:
% 
%  1. Redistributions of source code must retain the above copyright
%     notice, this list of conditions and the following disclaimer.
% 
%  2. Redistributions in binary form must reproduce the above copyright
%     notice, this list of conditions and the following disclaimer in the
%     documentation and/or other materials provided with the distribution.
% 
% THIS SOFTWARE IS PROVIDED BY BORJA FONS ALBERT, HÈCTOR USACH MOLINA AND
% JOAN VILA CARBÓ ''AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
% INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
% AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
% BORJA FONS ALBERT, HÈCTOR USACH MOLINA AND JOAN VILA CARBÓ OR
% CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
% EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
% PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
% PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
% LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
% NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
% SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
% 
% The views and conclusions contained in the software and documentation are
% those of the authors and should not be interpreted as representing
% official policies, either expressed or implied, of Borja Fons Albert,
% Hèctor Usach Molina and Joan Vila Carbó.


setup(block);

%endfunction

%*****************************************************************************************
% SETUP
%*****************************************************************************************
function setup(block)

% Registrar metodos ----------
block.RegBlockMethod('SetInputPortSamplingMode',@SetInputPortSamplingMode);
block.RegBlockMethod('Terminate',@Terminate);
block.RegBlockMethod('Outputs', @Output);

% Registrar entradas ---------
block.NumInputPorts  = 0;


% Setup functional port properties to dynamically inherited.
block.SetPreCompInpPortInfoToDynamic;
block.SetPreCompOutPortInfoToDynamic;

% Registrar salidas ---------
Noutput = 13;
block.NumOutputPorts = Noutput;
for i=1:Noutput
    block.OutputPort(i).DataTypeID = 0; %double
    block.OutputPort(i).Dimensions = 1;
    block.OutputPort(i).SamplingMode = 0; % frame
end


% Registrar parametros ----------
block.NumDialogPrms = 1; % Puerto
block.DialogPrmsTunable = {'Nontunable'};

% Registrar sampling times
block.SampleTimes = [-1 0];

% Set the block simStateCompliance to default (i.e., same as a built-in block)
block.SimStateCompliance = 'DefaultSimState';

% Run accelerator on TLC
block.SetAccelRunOnTLC(true);


% Crear socket ----------
global rsock
port = block.DialogPrm(1).Data;
rsock = java.net.DatagramSocket(port);

%endfunction


function SetInputPortSamplingMode(block, idx, fd)

%endfunction


%*****************************************************************************************
% OUTPUT
%*****************************************************************************************
function Output(block)

global rsock
% port = block.DialogPrm(1).Data;
% rsock = java.net.DatagramSocket(port);


import java.io.*;
import java.net.*;

persistent recv_pkt;
if (isempty(recv_pkt))
    recv_pkt = java.net.DatagramPacket(uint8(zeros(1,1085)), 1085);
end

rsock.receive(recv_pkt);
recv_data = recv_pkt.getData();
numbytes = recv_pkt.getLength();

% Salida de datos
[index,data,n] = extractDATA(recv_data, numbytes);

for j = 1:n
    switch index(j)
        case 3
            block.OutputPort(1).Data = (data((j-1)*8+7)); %Speed
        case 16
            block.OutputPort(2).Data = (data((j-1)*8+1)); %Pitch rate
            block.OutputPort(3).Data  = (data((j-1)*8+2)); %Roll rate
            block.OutputPort(4).Data   = (data((j-1)*8+3)); %Yaw rate
        case 17
            block.OutputPort(5).Data   = (data((j-1)*8+1)); %Pitch
            block.OutputPort(6).Data    = (data((j-1)*8+2)); %Roll
            block.OutputPort(7).Data = (data((j-1)*8+3)); %Heading
        case 18
            block.OutputPort(8).Data = (data((j-1)*8+1)); %alpha
            block.OutputPort(9).Data  = -(data((j-1)*8+2)); %beta
            block.OutputPort(10).Data = (data((j-1)*8+4)); %vpath
        case 22
            block.OutputPort(11).Data = (data((j-1)*8+1)); %lat
        case 23
            block.OutputPort(12).Data = (data((j-1)*8+1)); %lon
        case 24
            block.OutputPort(13).Data = data((j-1)*8+1); %alt
    end
end
% close(rsock)

%endfunction


%*****************************************************************************************
% TERMINATE
%*****************************************************************************************
function Terminate(block)

% Al acabar se cierra el socket
global rsock
close(rsock)
%endfunction


%*****************************************************************************************
% EXTRACT DATA
%*****************************************************************************************
function [index,data,n] = extractDATA(recv_data, numbytes)

i=0;
index = uint32(zeros(1, 20));
data  = single(zeros(1, 200));
for j = 6:36:numbytes
    i=i+1;
    index_bytes=recv_data(j:j+3);
    index_aux=typecast(index_bytes,'uint32');
    index(i) = index_aux(1);
    for k=1:8
        data_bytes=recv_data(j+4*k:j+4*k+3);
        data_aux = typecast(data_bytes,'single');
        data((i-1)*8+k) = data_aux(1);
    end
end
data = double(data);
n = i;
%endfunction