function kmlwrite_volume(wpu,wpl,filename,attr)

nmax=min(length(wpl),length(wpu));

fid1=fopen(filename,'w');
%Cabecera del archivo .kml.
fprintf(fid1,'<?xml version="1.0" encoding="UTF-8"?>\n<kml xmlns="http://www.opengis.net/kml/2.2">\n<Document>\n<name>%s</name>', filename);

fprintf(fid1,'\n<Style id="inline0">');
fprintf(fid1,'\n\t<PolyStyle>\n\t\t<fill>%s</fill>\n\t\t<color>%s</color>\n\t</PolyStyle>',num2str(attr.fill),attr.color);
fprintf(fid1,'\n\t<LineStyle>\n\t\t<color>%s</color>\n\t\t<width>%s</width>\n\t</LineStyle>',attr.edgecolor,num2str(attr.edgewidth));
fprintf(fid1,'\n\t<IconStyle>\n\t\t<scale>%s</scale>\n\t\t<Icon><href>%s</href></Icon>\n\t</IconStyle>',num2str(attr.iconscale),attr.iconurl);
fprintf(fid1,'\n\t<LabelStyle>\n\t\t<color>%s</color>\n\t\t<scale>%s</scale>\n\t</LabelStyle>',attr.labelcolor,num2str(attr.labelscale));
fprintf(fid1,'\n</Style>');

fprintf(fid1,'\n<Style id="inline1">');
fprintf(fid1,'\n\t<PolyStyle>\n\t\t<fill>%s</fill>\n\t\t<color>%s</color>\n\t</PolyStyle>',num2str(attr.fill2),attr.color2);
fprintf(fid1,'\n\t<LineStyle>\n\t\t<color>%s</color>\n\t\t<width>%s</width>\n\t</LineStyle>',attr.edgecolor,num2str(attr.edgewidth));
fprintf(fid1,'\n</Style>');

fprintf(fid1,'\n<Style id="inline2">\n\t<PolyStyle>\n\t\t<fill>%s</fill>\n\t\t<color>%s</color>\n\t</PolyStyle>',num2str(attr.latfill),attr.latcolor);
fprintf(fid1,'\n\t<LineStyle>\n\t\t<color>%s</color>\n\t\t<width>%s</width>\n\t</LineStyle>',attr.edgecolor,num2str(attr.edgewidth));
fprintf(fid1,'\n</Style>');

fprintf(fid1,'\n<Placemark>\n\t<name>%s</name>\n\t<styleUrl>#inline0</styleUrl>',attr.label);
fprintf(fid1,'\n\t<MultiGeometry>');

%Etiqueta
fprintf(fid1,'\n\t\t<Point>\n\t\t\t<altitudeMode>%s</altitudeMode>\n\t\t\t<coordinates>%3.6f,%3.6f,%3.6f</coordinates>\n\t\t</Point>',attr.altmode,wpu(1).lon,wpu(1).lat,wpu(1).alt);

% Poligono superior
fprintf(fid1,'\n\t\t<Polygon>\n\t\t\t<extrude>%s</extrude>\n\t\t\t<tessellate>1</tessellate>\n\t\t\t<altitudeMode>%s</altitudeMode>\n\t\t\t<outerBoundaryIs>\n\t\t\t\t<LinearRing>',num2str(attr.extrude),attr.altmode);
fprintf(fid1,'\n\t\t\t\t\t<coordinates>');
    %Bucle que recorre los puntos del poligono.
	for j=1:nmax
		fprintf(fid1,'\n\t\t\t\t\t\t%3.6f,%3.6f,%3.6f ',wpu(j).lon,wpu(j).lat,wpu(j).alt);
        %fprintf('\n%3.6f,%3.6f,%3.6f ',wpu(j).lon,wpu(j).lat,wpu(j).alt);
	end
%Cierra la marca del poligono.
fprintf(fid1,'\n\t\t\t\t\t</coordinates>\n\t\t\t\t</LinearRing>\n\t\t\t</outerBoundaryIs>\n\t\t</Polygon>');
fprintf(fid1,'\n\t</MultiGeometry>\n</Placemark>');

% Poligono inferior
fprintf(fid1,'\n<Placemark>\n\t<name>%s</name>\n\t<styleUrl>#inline1</styleUrl>',attr.label);
fprintf(fid1,'\n\t<MultiGeometry>');
fprintf(fid1,'\n\t\t<Polygon>\n\t\t\t<extrude>%s</extrude>\n\t\t\t<tessellate>1</tessellate>\n\t\t\t<altitudeMode>%s</altitudeMode>\n\t\t\t<outerBoundaryIs>\n\t\t\t\t<LinearRing>',num2str(attr.extrude),attr.altmode2);
fprintf(fid1,'\n\t\t\t\t\t<coordinates>');
    %Bucle que recorre los puntos del poligono.
	for j=1:nmax
		fprintf(fid1,'\n\t\t\t\t\t\t%3.6f,%3.6f,%3.6f ',wpl(j).lon,wpl(j).lat,wpl(j).alt);
        %fprintf('\n%3.6f,%3.6f,%3.6f ',wpl(j).lon,wpl(j).lat,wpl(j).alt);
	end
%Cierra la marca del poligono.
fprintf(fid1,'\n\t\t\t\t\t</coordinates>\n\t\t\t\t</LinearRing>\n\t\t\t</outerBoundaryIs>\n\t\t</Polygon>');
fprintf(fid1,'\n\t</MultiGeometry>\n</Placemark>');

% Tapas laterales
fprintf(fid1,'\n<Placemark>\n\t<name> %s </name>\n\t<styleUrl>#inline2</styleUrl>',attr.label);
fprintf(fid1,'\n\t<MultiGeometry>');

for k=1:nmax-1
    fprintf(fid1,'\n\t\t<Polygon>\n\t\t\t<extrude>%s</extrude>\n\t\t\t<tessellate>%s</tessellate>\n\t\t\t<altitudeMode>%s</altitudeMode>\n\t\t\t<outerBoundaryIs>\n\t\t\t\t<LinearRing>','false','true',attr.altmode);
    fprintf(fid1,'\n\t\t\t\t\t<coordinates>');
    %Bucle que recorre los puntos del poligono.
    fprintf(fid1,'\n\t\t\t\t\t\t%3.6f,%3.6f,%3.6f ',wpl(k).lon,wpl(k).lat,wpl(k).alt);
    fprintf(fid1,'\n\t\t\t\t\t\t%3.6f,%3.6f,%3.6f ',wpl(k+1).lon,wpl(k+1).lat,wpl(k+1).alt);
    fprintf(fid1,'\n\t\t\t\t\t\t%3.6f,%3.6f,%3.6f ',wpu(k+1).lon,wpu(k+1).lat,wpu(k+1).alt);
    fprintf(fid1,'\n\t\t\t\t\t\t%3.6f,%3.6f,%3.6f ',wpu(k).lon,wpu(k).lat,wpu(k).alt);
    fprintf(fid1,'\n\t\t\t\t\t\t%3.6f,%3.6f,%3.6f ',wpl(k).lon,wpl(k).lat,wpl(k).alt);
    %Cierra la marca del poligono.
	fprintf(fid1,'\n\t\t\t\t\t</coordinates>\n\t\t\t\t</LinearRing>\n\t\t\t</outerBoundaryIs>\n\t\t</Polygon>');
end

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
        system(['googleearth ', filename]);
    end
else
    fprintf('\n**************************\n\tNo se lanzar el GoogleEarth automaticamente\n\tDebes abrir el archivo %s manualmente\n**************************\n', launcher_complet);
    input('Pulsa Intro para continuar');
end