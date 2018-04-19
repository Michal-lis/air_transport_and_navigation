function[traffics]=PROCESS_UpperLower(traffics)
% It classifies and puts proper colors to traffics according
% to their altitude: 
% Upper Airspace >24500 ft - Blue
% Lower Airspace < 24500   - Yellow
limit= 24500;
for i=1:length(traffics);
	if traffics(i).alt >= limit
		traffics(i).color=2;
	else
		traffics(i).color=9;
	end
end
