function msfcn_udpSendFcn(block)
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
block.RegBlockMethod('Outputs', @Output);

% Registrar entradas ---------
block.NumInputPorts  = 1;
block.InputPort(1).DataTypeID = 0; %double
block.InputPort(1).Dimensions = 1;


% Setup functional port properties to dynamically inherited.
block.SetPreCompInpPortInfoToDynamic;
block.SetPreCompOutPortInfoToDynamic;

% Registrar salidas ---------
block.NumOutputPorts = 0;

% Registrar parametros ----------
block.NumDialogPrms = 3; % Puerto, IP y dataref
block.DialogPrmsTunable = {'Nontunable', 'Nontunable', 'Nontunable'};

% Registrar sampling times
block.SampleTimes = [-1 0];

% Set the block simStateCompliance to default (i.e., same as a built-in block)
block.SimStateCompliance = 'DefaultSimState';

% Run accelerator on TLC
block.SetAccelRunOnTLC(true);

%endfunction


function SetInputPortSamplingMode(block, idx, fd)
block.InputPort(idx).SamplingMode = fd;

%endfunction


%*****************************************************************************************
% OUTPUT
%*****************************************************************************************
function Output(block)

port = block.DialogPrm(1).Data;
ip = block.DialogPrm(2).Data;
dataref = block.DialogPrm(3).Data;
ssock = java.net.DatagramSocket();


import java.io.*;
import java.net.*;

value = single(block.InputPort(1).Data);
send_msg=uint8(zeros(1,509));
send_msg(1:4)=uint8('DREF');
send_msg(5)=uint8(0);

value=single(value);
value_bytes=typecast(value,'uint8');
len=6;
for j=1:4
    send_msg(len)=value_bytes(j);
    len=len+1;
end
dataref_bytes=uint8(dataref);
for j=1:length(dataref)
    send_msg(len)=dataref_bytes(j);
    len=len+1;
end
send_pkt = java.net.DatagramPacket(send_msg, size(send_msg,2),java.net.InetAddress.getByName(ip),port);
ssock.send(send_pkt);


close(ssock)

%endfunction