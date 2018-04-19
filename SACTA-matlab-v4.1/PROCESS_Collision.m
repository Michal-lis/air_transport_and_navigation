function[traffics]=PROCESS_Collision(traffics)
% This function detects potential collisions and colors the traffics properly.
% Red color means collision alert.
%
% Security cylinder:
% Horizontal Radio: 5NM 
% Height: 1000 ft

hor_separation= 5*1.8*1000; % 5NM
ver_separation= 1000;  % 1000 ft.

for i=1:length(traffics)
	P1.lat=traffics(i).lat;
	P1.lon=traffics(i).lon;
	P1.alt=traffics(i).alt;
	for j=1:length(traffics)
		P2.lat=traffics(j).lat;
		P2.lon=traffics(j).lon;
		P2.alt=traffics(j).alt;
		dh=vincenty_distazi(P1.lat,P1.lon,P2.lat,P2.lon);
        dv=abs(P2.alt-P1.alt);
        %fprintf('%d, %d, %g, %g\n',i,j,dh,dv);
		if dh < hor_separation && i~=j && dv < ver_separation
			traffics(i).color=10;
			traffics(j).color=10;
		end
	end
end
