function wp=routefinder_read(file)
% It reads a text file produced by Route Finder defining a route
% like the one provided in LEVC-UEEE.txt
% It produces a list waypoints contained in the Route Finder file 
% with the following attributes:
% wp(n).lon
% wp(n).lat
% wp(n).alt
% wp(n).gspeed
% wp(n).desc

wp=[];
n=1;
fid=fopen(file);

tline = fgetl(fid);
while ischar(tline)
    disp(tline);
    clear tok;
    i=1;
    [tok{i},remain]=strtok(tline);
    wp(n).name=tok{i};
    while strcmp(tok{i},'')==0
        i=i+1;
        [tok{i},remain]=strtok(remain);
    end
    j=i-1;
  
    while isempty(sex2dec(tok{j})) && j>0
        j=j-1;
        %tok{j}
        %sex2dec(tok{j})
    end
    %j=j+1;
    long=tok{j};
    lat=[tok{j-1}(1),'0',tok{j-1}(2:end)];
    
    wp(n).lat=sex2dec(lat);
    wp(n).lon=sex2dec(long);
    wp(n).alt=0;
    wp(n).gspeed=0;
    wp(n).desc=num2str(n);
    n=n+1;
    tline = fgetl(fid);
end

fclose(fid);
    
end