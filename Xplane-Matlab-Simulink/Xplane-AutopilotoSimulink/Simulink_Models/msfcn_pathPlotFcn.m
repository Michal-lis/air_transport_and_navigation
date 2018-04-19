function msfcn_pathPlotFcn(block)
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
block.NumInputPorts  = 2;

% Registrar salidas ---------
block.NumOutputPorts = 0;

% Setup functional port properties to dynamically inherited.
block.SetPreCompInpPortInfoToDynamic;
block.SetPreCompOutPortInfoToDynamic;


% Registrar parametros ----------
block.NumDialogPrms = 1; % Estruc de wp
block.DialogPrmsTunable = {'Nontunable'};

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

persistent h N

wp_struct = block.DialogPrm(1).Data;
NUM_WP = length(wp_struct);
lat = block.InputPort(1).Data;
lon = block.InputPort(2).Data;

if isempty(h)
    close all
    h = axes;
    axis(h, 'equal');
    
    % Plot ruta
    plot(wp_struct(1).long, wp_struct(1).lat,'b*')
    hold on
    for i=2:NUM_WP
        plot([wp_struct(i).long], [wp_struct(i).lat],'bo')
    end
    for i=2:NUM_WP
        plot([wp_struct(i-1).long wp_struct(i).long], [wp_struct(i-1).lat wp_struct(i).lat])
    end
    
    N = 0;
end

N = N + 1;

% Plot pos
if mod(N, 10) == 0
    plot(h, lon, lat, '.r', 'MarkerSize', 2)
end

%endfunction