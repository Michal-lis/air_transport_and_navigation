function i=TRAFFIC_find(traffics,hexcode)
% It searches for a traffic with a specified hexcode in an array 
% of traffic structs and returns the index of the array.
%
% INPUT PARAMETERES
% traffics: array of traffic structs
% hexcode: hexcode to look for.
%
% RETURN VALUE
% i: index of the traffic we are looking for. 
% i=0 if not found

i=0;
found= false;

for i=1:length(traffics)
    if strcmp(traffics(i).hexId,hexcode)
        found=true;
        break;
    end
end
if ~found
    i=0;
end
end