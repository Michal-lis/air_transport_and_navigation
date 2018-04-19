function[traffics]=PROCESS_ClimbDescend(traffics,t)
% This function compares the altitudes of the different traffics in two 
% instants of time T=20 seconds apart and represents them in different colors: 
% Climbing:   magenta 
% Descending: green 
% Leveled:    blue

period=1;
T=10;
persistent prev_traffics;
histeresis=10;

if isempty(prev_traffics)
    prev_traffics=traffics;
end

for i=1:length(traffics)
    j=TRAFFIC_find(prev_traffics,traffics(i).hexId);
    if j>0
        dif=traffics(i).alt-prev_traffics(j).alt;
        if abs(mod(t/period,20))<1
            if dif>0 && dif>histeresis
                traffics(i).color=5;
            elseif dif<0 && dif<-histeresis
                traffics(i).color=3;
            else
                traffics(i).color=2;
            end
            prev_traffics(j).color=traffics(i).color;
        else
            traffics(i).color=prev_traffics(j).color;
        end
        
    end
end

if abs(mod(t/period,T))<1
    prev_traffics=traffics;
    %fprintf(' %g \n',mod(t/period,10));
end

end


