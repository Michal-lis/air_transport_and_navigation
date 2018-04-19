function [plan,n]= KMLprocess( file )
%  KMLprocess(file)
%  Reads .kml file and returns a list of waypoints for each object in it
%  n is the number of lists processed
%  Works best with independent linestrings with a name each
%  Expects coordinates to start in the line following <coordinates>


plannumber=1;

fid=fopen (file,'r');
line=fgets(fid);
while ~(line==-1)

    namepos=strfind(line,'name>');
    coordin_start=strfind(line,'<coordinates>');
   
    if namepos>0
       name=line((namepos(1)+5):(namepos(2)-3));
       plan(plannumber).name=name;
    end;
    if coordin_start>0 %Now I will read the next line and search for groups of coordinates
        [wp,number]=fscanf(fid,'%f,%f,%f ',[3,inf]);
        for i=1:number/3
           plan(plannumber).wp(i).lon = wp(1,i);
           plan(plannumber).wp(i).lat = wp(2,i);
           plan(plannumber).wp(i).alt = wp(3,i)*3.3; %Kml files store height in meters
        end
        plannumber=plannumber+1;
        
        
    end
 
    line=fgets(fid);
        
end;
n=plannumber-1;

fclose (fid);
end
