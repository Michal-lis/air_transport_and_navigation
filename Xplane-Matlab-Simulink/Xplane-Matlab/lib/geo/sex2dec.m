function x=sex2dec(rfs)
% Converts from sex degrees to decimal degrees
% TWO FORMATS ADMITTED
% FORMAT 1
% Format  'N039°29''22.00"' 
% Format  'W028°30''54.00"'
% FORMAT 2
% Format  402959N / ddmmss for latitude
% Format 0005020W / ddmmss for longitude

if upper(rfs(1))>=65
    x=sextodec1(rfs);
else
    x=sextodec2(rfs);
end
end

function x=sextodec1(rfs)
% Format  'N039°29''22.00"' 
% Format  'W028°30''54.00"'
try
    deg=str2num(rfs(2:4));
    min=str2num(rfs(6:7));
    seg=str2num(rfs(9:13));
    x=deg+min/60+seg/3600;
    if rfs(1)=='W' || rfs(1)=='S'
        x=-x;
    elseif isempty(deg) || isempty(min) || isempty(seg)
        x=[];
    end
catch
    x=[];
end
end

function x=sextodec2(dms)
% Format  402959N / ddmmss for latitude
% Format 0005020W / ddmmss for longitude
% dms=dms(end-6:end);
try
    p=upper(dms(end));
    if p=='W' || p=='E'
        deg=str2num(dms(1:3));
        min=str2num(dms(4:5));
        sec=str2num(dms(6:end-1));
    else
        deg=str2num(dms(1:2));
        min=str2num(dms(3:4));
        sec=str2num(dms(5:end-1));
    end
    x=deg+min/60+sec/3600;
    if p=='W' || p=='S'
        x=-x;
    elseif isempty(deg) || isempty(min) || isempty(sec)
        x=[];
    end
catch
    x=[];
end
end