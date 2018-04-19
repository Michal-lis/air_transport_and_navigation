function [xp,yp]=circle(x,y,r,phi1,phi2,n)
% Crea un circulo (o sector circular) sobre la superficie de la tierra 
% definido por n puntos
% Retorna un array [xp, yp] con las coordenadas de los puntos. 
% Tiene en cuenta la deformación por la latitud. 
% Util para dibujar arcos DME en Google Earth.
% Parámetros:
%   x,y: coordenadas del centro del circulo.
%        Pueden ser longitudes y latitudes en radianes
%   r: radio del circulo.
%      Puede ser una distancia angular D/R, siendo R el radio de la tierra
%   phi1: angulo de comienzo del sector circular
%   phi2: angulo final del sector circular
%   n: numero de puntos
% Existe un fichero circle_example con un ejemplo de uso con Google Earth.

%ang=phi1:0.01:phi2;

ang=linspace(phi1,phi2,n);
xp=x+(r*cosd(ang)/cosd(y))*180/pi;
yp=y+r*sind(ang)*180/pi;

% ang=linspace(phi1,phi2,n);
% xp=x+(r*cos(ang)/cos(y));
% %xp=x+r*cos(ang);
% yp=y+r*sin(ang);

end