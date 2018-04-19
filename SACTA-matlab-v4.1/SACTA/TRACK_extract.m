function TRACK_extract(scenario_file,trace_file,hexcode)
% It extracts the track of the flight identified by the hexcode from 
% a .txt file containing tracks of several planes,
% to a file that only contains this single track.
%
% INPUT PARAMETERES
% scenario_file: existing file with recorded set of tracks
% hexcode:       Hex identifier of the selected plane
% trace_file:    new file containing the track of plane hexcode

close all;
tsim=0;
k=1;
while tsim<intmax
    [traffics, tsim, real_time]=TRACE_read(scenario_file);
    
    i=TRAFFIC_find(traffics,hexcode);
    
    if i>0
        TRACK_write(trace_file,traffics(i),real_time);
    end
    k=k+1;
end