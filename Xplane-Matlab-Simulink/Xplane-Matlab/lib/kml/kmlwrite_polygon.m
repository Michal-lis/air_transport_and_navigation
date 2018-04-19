function kmlwrite_polygon(wp,filename,attr)

fid1=fopen(filename,'w');
%Cabecera del archivo .kml.
fprintf(fid1,'<?xml version="1.0" encoding="UTF-8"?>\n<kml xmlns="http://www.opengis.net/kml/2.2">\n<Document>\n<name>%s</name>', filename);
fprintf(fid1,'\n<Style id="inline0">');
fprintf(fid1,'\n\t<PolyStyle>\n\t\t<fill>%s</fill>\n\t\t<color>%s</color>\n\t</PolyStyle>',num2str(attr.fill),attr.color);
fprintf(fid1,'\n\t<LineStyle>\n\t\t<color>%s</color>\n\t\t<width>%s</width>\n\t</LineStyle>',attr.edgecolor,num2str(attr.edgewidth));
fprintf(fid1,'\n\t<IconStyle>\n\t\t<scale>%s</scale>\n\t\t<Icon><href>%s</href></Icon>\n\t</IconStyle>',num2str(attr.iconscale),attr.iconurl);
fprintf(fid1,'\n\t<LabelStyle>\n\t\t<color>%s</color>\n\t\t<scale>%s</scale>\n\t</LabelStyle>',attr.labelcolor,num2str(attr.labelscale));
fprintf(fid1,'\n</Style>');

fprintf(fid1,'\n<Placemark>\n\t<name>%s</name>\n\t<styleUrl>#inline0</styleUrl>',attr.label);
fprintf(fid1,'\n\t<MultiGeometry>');

%Etiqueta
fprintf(fid1,'\n\t\t<Point>\n\t\t\t<altitudeMode>%s</altitudeMode>\n\t\t\t<coordinates>%3.6f,%3.6f,%3.6f</coordinates>\n\t\t</Point>',attr.altmode,wp(1).lon,wp(1).lat,wp(1).alt);

% Poligono
fprintf(fid1,'\n\t\t<Polygon>\n\t\t\t<extrude>%s</extrude>\n\t\t\t<tessellate>1</tessellate>\n\t\t\t<altitudeMode>%s</altitudeMode>\n\t\t\t<outerBoundaryIs>\n\t\t\t\t<LinearRing>',num2str(attr.extrude),attr.altmode);
fprintf(fid1,'\n\t\t\t\t\t<coordinates>');
    %Bucle que recorre los puntos del poligono.
	for j=1:length(wp)
		fprintf(fid1,'\n\t\t\t\t\t\t%3.6f,%3.6f,%3.6f ',wp(j).lon,wp(j).lat,wp(j).alt);
        %fprintf('\n%3.6f,%3.6f,%3.6f ',wp(j).lon,wp(j).lat,wp(j).alt);
    end
%Cierra la marca del poligono.
fprintf(fid1,'\n\t\t\t\t\t</coordinates>\n\t\t\t\t</LinearRing>\n\t\t\t</outerBoundaryIs>\n\t\t</Polygon>');

fprintf(fid1,'\n\t</MultiGeometry>\n</Placemark>');
%Cierra el archivo .kml.
fprintf(fid1,'\n</Document>\n</kml>');
fclose(fid1);

%Abre el archivo .kml.
if(ispc)
    winopen(filename);
elseif(exist('ismac'))
    if(ismac)
        system(['open ', filename]);
    else
        system(['google-earth ', filename,' &']);
    end
else
    fprintf('\n**************************\n\tNo se lanzar el GoogleEarth automaticamente\n\tDebes abrir el archivo %s manualmente\n**************************\n', launcher_complet);
    input('Pulsa Intro para continuar');
end