function [xp,yp]=circle(x,y,r,phi1,phi2,n)
% It creates a circle (or circular sector) on the surface of the earth 
% defined by N points. 
% It returns an array [xp, yp] with the coordinates of the points. 
% It takes into account the strain of the arch with the latitude. 
% Used for example to draw DME arcs in Google Earth. 
% Parameters: 
%     x, y: coordinates of the center of the circle. 
%           Can be longitudes and latitudes in radians 
%     r: radius of the circle. 
%        May be an angular distance D / R, where R is the radius of the earth 
%     phi1: Start angle circular sector
%           0 degrees is NORTH. 
%     phi2: Final angle of the circular sector
%           Anles measured clockwise
%     n: number of points 
% There is a function with an example circle_example 
% In the examples-kml_write file.
%
%
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
% Existe una funcion circle_example con un ejemplo 
% en el fichero examples-kml_write.

%ang=phi1:0.01:phi2;


ang=linspace(phi1,phi2,n);
xp=x+(r*sind(ang)/cosd(y))*180/pi;
yp=y+r*cosd(ang)*180/pi;

end