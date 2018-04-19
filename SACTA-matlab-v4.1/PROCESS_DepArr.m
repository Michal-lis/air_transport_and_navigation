function [DepTraffic,ArrTraffic,traffics] = PROCESS_DepArr(traffics,Airport)
% Identifies Departures and Arrivals to an Airport and represents them in different colors:
%   DEPARTURES: red
%   ARRIVALS: green
% It returns:
%   DepTraffic: array of departure traffics
%   ArrTraffic: array of arrival traffics
%   traffics  : array of all traffics with the color attribute properly set
%----------------------------------------------------------------------------------
% 1st PHASE
%----------------------------------------------------------------------------------
% DEPARTURE candidate
% Altitude < 3000 && 
% abs(Longitude-Airport.lon)<0.06 && abs(Latitude-Airport.lat)<0.06
%----------------------------------------------------------------------------------
% ARRIVAL candidate
% Altitude < 20000 && 
% abs(Longitud-Airport.lon)<1.2 && abs(Latitud-Airport.lat)<1.2
%----------------------------------------------------------------------------------
% 2nd PHASE
%----------------------------------------------------------------------------------
% DEPARTURE
% a) Departure candidate && Altitude increases && Distance increases
% b) Departure && abs(Longitude-Airport.lon)<1.2 && abs(Latitude-Airport.lat)<1.2
%----------------------------------------------------------------------------------
% ARRIVAL
% a) Arrival candidate && Altitude decreases && Distance decreases
% b) Arrival && abs(Longitude-Airport.lon)>0.6 && abs(Latitude -Airport.lat)>0.6
%----------------------------------------------------------------------------------

persistent dep_id arr_id dep_cand_id arr_cand_id arr_cand dep_cand;
if isempty(dep_id)
    dep_id=[];
end
if isempty(arr_id)
    arr_id=[];
end
if isempty(arr_cand_id)
    arr_cand_id=[];
    arr_cand=[];
end
if isempty(dep_cand_id)
    dep_cand_id=[];
    dep_cand=[];
end
departures=[];
arrivals=[];
traffics_id=[];
clc;

for i=1:length(traffics)
    traffics_id=[traffics_id,hex2dec(traffics(i).hexId)];
end

lost_dep=setdiff(dep_id,traffics_id);
dep_id=setdiff(dep_id,lost_dep);
lost_arr=setdiff(arr_id,traffics_id);
arr_id=setdiff(arr_id,lost_arr);

for i=1:length(traffics)
    traffics(i).id=traffics_id(i);
    traffics(i).distance=norm([traffics(i).lon-Airport.lon, traffics(i).lat-Airport.lat]);
    
    k=TRAFFIC_find(traffics,traffics(i).hexId);
 
    if ismember(traffics(i).id, dep_id)
        departures=[departures,traffics(k)];
        traffics(k).color = 10;
    elseif ismember(traffics(i).id, arr_id)
        arrivals=[arrivals,traffics(k)];
        traffics(i).color = 2;
    elseif ismember(traffics(i).id, arr_cand_id)
        m=TRAFFIC_find(arr_cand,traffics(i).hexId);
        if m>0
            if arr_cand(m).alt>=traffics(i).alt && arr_cand(m).distance>traffics(i).distance
                arr_id=[arr_id, traffics(i).id];
                arrivals=[arrivals, traffics(i)];
                traffics(i).color = 2;
                beep;
            end
            arr_cand(m)=[];
        end
        arr_cand_id=setdiff(arr_cand_id,traffics(i).id);
    elseif ismember(traffics(i).id, dep_cand_id)
        m=TRAFFIC_find(dep_cand,traffics(i).hexId);
        if m>0
            if dep_cand(m).alt<traffics(i).alt && dep_cand(m).distance<traffics(i).distance
                dep_id=[dep_id, traffics(i).id];
                departures=[departures, traffics(i)];
                traffics(i).color = 1;
                beep;
            end
            dep_cand(m)=[];
        end
        dep_cand_id=setdiff(dep_cand_id,traffics(i).id);
    else
        if traffics(i).alt < 3000 && abs(traffics(i).lon-Airport.lon)<0.06 && abs(traffics(i).lat-Airport.lat)<0.06
            dep_cand_id=[dep_cand_id, traffics(i).id];
            dep_cand=[dep_cand, traffics(i)];
        elseif traffics(i).alt < 20000 && abs(traffics(i).lon-Airport.lon)<1.2 && abs(traffics(i).lat-Airport.lat)<1.2
            arr_cand_id=[arr_cand_id, traffics(i).id];
            arr_cand=[arr_cand, traffics(i)];
        end
    end
end

print(dep_cand_id, arr_cand_id, dep_id, arr_id);

DepTraffic=departures;
ArrTraffic=arrivals;
end

%--------------------------------------------------------------------------
function print(dep_cand_id, arr_cand_id, dep_id, arr_id)
str='';
z=dep_cand_id;
zq=dec2hex(z);
[m,n]=size(zq);
for i=1:m
    str=[str,' ',zq(i,:)];
end
fprintf('DEPARTURE candidates: %s\n',str);

str='';
z=arr_cand_id;
zq=dec2hex(z);
[m,n]=size(zq);
for i=1:m
    str=[str,' ',zq(i,:)];
end
fprintf('ARRIVAL   candidates: %s\n',str);

str='';
z=dep_id;
zq=dec2hex(z);
[m,n]=size(zq);
for i=1:m
    str=[str,' ',zq(i,:)];
end
fprintf('          DEPARTURES: %s\n',str);

str='';
z=arr_id;
zq=dec2hex(z);
[m,n]=size(zq);
for i=1:m
    str=[str,' ',zq(i,:)];
end
fprintf('            ARRIVALS: %s\n',str);
fprintf('---------------------------------------------');
end
