% Generates a collision scenario.

% 1 degree latitude = 110 km
% 1 degree longitude = 111 km
% 1 hour = 3600 s.
%    Some airways:
%    A33 = [ -3.17 40.22; -0.28 39.29; 2.45 39.26 ];
%    A34 = [ 0.33 42.41; -0.1 40.15; -0.19 39.53; -0.28 39.29; -0.34 38.16; 0.012 36.52];
%    B28 = [ 2.06 41.18; -0.28 39.29; -2.13 38.21];
%    G30 = [ -0.28 39.29; 1.28 38.54];
%    N609 = [ -0.012 36.52; -0.08 40.13; 0.059 42.46]; 

clc; clear all;

% Traffic through airway N609
plane(1).callsign = 'IB001';
plane(1).hexId    = 'A00001';
plane(1).aicraftId = 'A350';
plane(1).flightId = '9191';
plane(1).squawk = '6001';
plane(1).color = 1;
plane(1).trace = [-0.042, 38, 5000, 0 ;
                 -0.08, 40.13, 6000, 1200;
                 0.059, 42.46, 4000, 3000];

% Traffic through airway G30             
plane(2).callsign = 'BMI702';
plane(2).hexId    = 'A00002';
plane(2).aicraftId = 'A319';
plane(2).flightId = '8151';
plane(2).squawk = '6002';
plane(2).color = 1;
plane(2).trace = [ -0.28 39.29, -1, 0 ;
                  -0.28 39.29, 0, 600 ;
                  -0.27 39.295 5000, 650 ;
                  1.28 38.54, 5000,1800 ];

% Traffic through airway A33   A33 = [ -3.17 40.22; -0.28 39.29; 2.45 39.26 ];
plane(3).callsign = 'RYR002';
plane(3).hexId    = 'A00003';
plane(3).aicraftId = 'B737';
plane(3).flightId = '6196';
plane(3).squawk = '6003';
plane(3).color = 1;
plane(3).trace = [ -3.17, 40.22, 10000,  0 ;
                  -0.28, 39.29, 10000, 1000;
                   2.45, 39.25, 10000, 2000 ];


plane(4).callsign = 'RYR003';
plane(4).hexId    = 'D00004';
plane(4).aicraftId = 'B737';
plane(4).flightId = '7176';
plane(4).squawk = '6004';
plane(4).color = 1;
plane(4).trace = [0.059, 42.46, 5000, 0
                 -0.08, 40.13, 6000, 1200];
              

% Traffic through airway G30             
plane(5).callsign = 'BA001';
plane(5).hexId    = 'E00005';
plane(5).aicraftId = 'A320';
plane(5).flightId = '6196';
plane(5).squawk = '6005';
plane(5).color = 1;
plane(5).trace = [ -0.28 39.29, -1, 0 ;
                  -0.28 39.29, 0, 580 ;
                  -0.27 39.295 6000, 620 ;
                  1.28 38.54, 6000,1800 ];

save 'scenario3' plane