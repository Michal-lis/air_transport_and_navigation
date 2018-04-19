function[traffics]=PROCESS_ClimbDescend2(traffics)
% This function analyzes the vertical rate of the different traffics 
% and represents them in different colors: 
% Climbing:   magenta 
% Descending: green 
% Leveled:    blue


for i=1:length(traffics)
  if traffics(i).vertRate>10
      traffics(i).color=5;
  elseif traffics(i).vertRate<-10
      traffics(i).color=3;
  else
      traffics(i).color=2;
  end
end