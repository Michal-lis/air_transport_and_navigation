function msfcn_TargetFcn(block)
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


% Setup functional port properties to dynamically inherited.
block.SetPreCompInpPortInfoToDynamic;
block.SetPreCompOutPortInfoToDynamic;

% Registrar salidas ---------
Noutput = 4;
block.NumOutputPorts = Noutput;
for i=1:Noutput
    block.OutputPort(i).DataTypeID = 0; %double
    block.OutputPort(i).Dimensions = 1;
    block.OutputPort(i).SamplingMode = 0; % frame
end


% Registrar parametros ----------
block.NumDialogPrms = 5; % Estruc de wp
block.DialogPrmsTunable = {'Nontunable','Nontunable','Nontunable','Nontunable','Nontunable'};

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

wp_struct = block.DialogPrm(1).Data;
hold_alt = block.DialogPrm(2).Data;
hold_speed = block.DialogPrm(3).Data;
alt_t = block.DialogPrm(4).Data;
speed_t = block.DialogPrm(5).Data;
WP = block.InputPort(1).Data;

block.OutputPort(1).Data = wp_struct(WP).lat;
block.OutputPort(2).Data = wp_struct(WP).long;
if hold_alt
    block.OutputPort(3).Data = wp_struct(WP).alt;
else
    block.OutputPort(3).Data = alt_t;
end
if hold_speed
    block.OutputPort(4).Data = wp_struct(WP).airspeed;
else
    block.OutputPort(4).Data = speed_t;
end

%endfunction