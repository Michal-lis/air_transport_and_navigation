function[]=GEARTH_DisplayTraffic(traffics,filename)
% It generates a kml file with traffics and opens it in Google Earth 
% Called from MONITOR_DisplayTraffic when MONITOR = 2.
% The following fields of traffics are required to this display option:

% Field                  Type    Description
% =========================================================================
% traffics(j).hexId      string  Aircraft Mode S hexadecimal code.
% traffics(j).callsign   string  An eight digit flight ID. It can be a
%                                flight number or regist. (or even nothing)
% traffics(j).squawk     string  Assigned Mode A squawk code.
%
% traffics(j).lon        double  Longitude in degrees
%                                East positive, West negative.
% traffics(j).lat        double  Latitude in degrees
%                                North positive, South negative.
% traffics(j).alt        double  Mode C altitude in feet.
%                                Height relative to 1013.2mb in feet.
%                                (Flight Level). Not height AMSL..
% traffics(j).gspeed     double  GS Speed over ground in NM 
%                                (not indicated airspeed)
% traffics(j).track      double  Track of aircraft in degrees (not heading). 
%                                Derived from the velocity E/W and N/S.
% traffics(j).vertRate   double  Vertical rate in fpm. 64ft resolution.
% traffics(j).color      double  An integer in range [1..9] to set the color 
%                                for radar presentation. 
%                                See README.colors. Change it to set the color.
% traffics(j).icon = 'avion.png' Icon file for Google Earth representation
% traffics(j).comments ='string' Comments for Google Earth representation

% Lookat format
% By default the spot view is focused on Valencia
% lookat.Estado (booleano, 1=encendido, 0=apagado)
% lookat.Heading (AÅngulo que forma con el N geografico la Camara 0-360)
% lookat.Tilt (Inclinacion con la vertical que forma la Camara  0-90)
% lookat.Range (Distancia al punto observado (Rango aconsejado de
% 100000-300000 m).

lookat.Estado=1;
lookat.Heading=0;
lookat.Tilt=25;
lookat.Range=750000;


%if isempty(traffics)
	%Linea de control para que no escriba un archivo vacio.
	%MAL: si no hay aviones hay que crear un kml sin aviones.
%else
	%Borra el archivo anterior y abre la sesion de nuevo.
	fid2=fopen(filename,'w');

	%Cabecera kml
	fprintf(fid2,'<?xml version="1.0" encoding="UTF-8"?>\n<kml xmlns="http://www.opengis.net/kml/2.2">');
	fprintf(fid2,'\n\t<Document>\n\t\t<Folder>');
	fprintf(fid2,'\n\t\t\t<open>1</open>');
	fprintf(fid2,'\n\t\t\t<name>trafico aereo SACTA</name>');%  ,datestr(clock));
	fprintf(fid2,'\n\t\t\t<Style>');
	fprintf(fid2,'\n\t\t\t\t<ListStyle>');
	fprintf(fid2,'\n\t\t\t\t\t<listItemType>check</listItemType>');
	fprintf(fid2,'\n\t\t\t\t\t<bgColor>00ffffff</bgColor>');
	fprintf(fid2,'\n\t\t\t\t\t<maxSnippetLines>2</maxSnippetLines>');
	fprintf(fid2,'\n\t\t\t\t</ListStyle>\n\t\t\t</Style>\n');


	%Control de camara
	if lookat.Estado
	        fprintf(fid2,'\n\t\t\t<LookAt>');
	        fprintf(fid2,'\n\t\t\t\t<longitude>0.37666666666666</longitude>');
	        fprintf(fid2,'\n\t\t\t\t<latitude>39.47</latitude>');
	        fprintf(fid2,'\n\t\t\t\t<altitude>0</altitude>');
	        fprintf(fid2,'\n\t\t\t\t<heading>%g</heading>',lookat.Heading);
	        fprintf(fid2,'\n\t\t\t\t<tilt>%g</tilt>',lookat.Tilt);
	        fprintf(fid2,'\n\t\t\t\t<range>%g</range>',lookat.Range);
	        fprintf(fid2,'\n\t\t\t\t<altitudeMode>relativeToGround</altitudeMode>');
	        fprintf(fid2,'\n\t\t\t</LookAt>');
	end

	
	%Bucle principal
	for i=1:length(traffics)
		%Icono personalizado
		if (size(traffics(i).icon, 2) == 0)
			aux_icono = 'avion.png';
		else
			aux_icono = traffics(i).icon;
        end

		switch (traffics(i).color)
			case 1
				aux_color = 'ffffffff';
			case 2
				aux_color = 'ff00ffff';
			case 3
				aux_color = 'ff00ff00';
			case 4
				aux_color = 'ffc0c0c0';
			case 5
				aux_color = 'ffff00ff';
			case 6
				aux_color = 'ffffc800';
			case 7
				aux_color = 'ffffafaf';
			case 8
				aux_color = 'ff808080';             
			case 9
				aux_color = 'ffffff00';
			otherwise
				aux_color = 'ffff0000';
		end;
 
		%Estilo generico
		fprintf(fid2,'\n\t\t\t<Style id="%g">',i);
		fprintf(fid2,'\n\t\t\t\t<IconStyle>');
		fprintf(fid2,'\n\t\t\t\t\t<color>%s</color>', aux_color);
		fprintf(fid2,'\n\t\t\t\t\t<colorMode>normal</colorMode>');
		fprintf(fid2,'\n\t\t\t\t\t<scale>1</scale>');
		fprintf(fid2,'\n\t\t\t\t\t<Icon><href>%s/SACTA/iconos/%s</href></Icon>',pwd,aux_icono);
		fprintf(fid2,'\n\t\t\t\t</IconStyle>');
		fprintf(fid2,'\n\t\t\t</Style>\n');
	end
	for i=1:length(traffics)
		%Escritura del objeto en el archivo kml
		fprintf(fid2,'\n\t\t\t<Placemark>');
		fprintf(fid2,'\n\t\t\t<open>1</open>');
		fprintf(fid2,'\n\t\t\t\t<LookAt>');
		fprintf(fid2,'\n\t\t\t\t\t<longitude>%g</longitude>',traffics(i).lon);
		fprintf(fid2,'\n\t\t\t\t\t<latitude>%g</latitude>',traffics(i).lat);
		fprintf(fid2,'\n\t\t\t\t\t<altitude>%g</altitude>',traffics(i).alt*0.3048);
		fprintf(fid2,'\n\t\t\t\t\t<heading>0</heading>');
		fprintf(fid2,'\n\t\t\t\t\t<tilt>35</tilt>');
		fprintf(fid2,'\n\t\t\t\t\t<range>15000</range>');
		fprintf(fid2,'\n\t\t\t\t\t<altitudeMode>relativeToGround</altitudeMode>');
		fprintf(fid2,'\n\t\t\t\t</LookAt>');
		fprintf(fid2,'\n\t\t\t\t<name>%s</name>',traffics(i).callsign);
		fprintf(fid2,'\n\t\t\t\t<description>Desc: %s, Callsign: %s, Hexcode: %s, Squawk: %s, Lon.: %g, Lat.: %g, Alt.: %g, Speed: %g, Vert. rate: %g </description>',traffics(i).comments, traffics(i).callsign, traffics(i).hexId, traffics(i).squawk, traffics(i).lon, traffics(i).lat, traffics(i).alt, traffics(i).gspeed, traffics(i).vertRate);
		fprintf(fid2,'\n\t\t\t\t<styleUrl>#%g</styleUrl>',i);
		fprintf(fid2,'\n\t\t\t\t<Point>\n\t\t\t\t\t<altitudeMode>relativeToGround</altitudeMode>\n\t\t\t\t\t<coordinates>%g,%g,%g</coordinates>\n\t\t\t\t</Point>',traffics(i).lon,traffics(i).lat,traffics(i).alt*0.3048);
		fprintf(fid2,'\n\t\t\t</Placemark>');
	end
	%Cierre del archivo kml
	fprintf(fid2,'\n\t\t</Folder>\n\t</Document>\n</kml>\n');
	fclose(fid2);
end
