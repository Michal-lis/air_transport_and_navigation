function kmlwrite_point(wp,filename,name,icon_file,icon_scale)
if nargin<5
    icon_scale=1;
end

if nargin<4
    icon_file='http://maps.google.com/mapfiles/kml/paddle/wht-circle.png';
end

if nargin<3
    name='';
end

kmlwrite(filename,wp.lat,wp.lon,'Name',name,'Icon',icon_file,'IconScale',icon_scale);

if(ispc)
    winopen(filename);
elseif(exist('ismac'))
    if(ismac)
        system(['open ', filename]);
    else
        system(['googleearth ', filename]);
    end
end
end