function [pos,IAF,IF,FAP]=Fixes(wp,WPaprox)
%Function for identifying the important waypoints
[n,m]=size(WPaprox);
for i=1:n
    lat=WPaprox(i,1);
    long=WPaprox(i,2);
    %Using the function orto distazi to calcultae the distances between the
    %waypoints guessing from latitude and longitude
    for j=1:length(wp)
        [d(j),a12,a21]=orto_distazi(lat,long,wp(j).lat,wp(j).lon);
    end
    dmin=min(d);
    %Using the function strfind
    k=strfind(d,dmin);
    pos(i)=k(1);
    if i==1
        IAF=[wp(k(1)).lat wp(k(1)).lon];
    elseif i==2
        IF=[wp(k(1)).lat wp(k(1)).lon];
    else
        FAP=[wp(k(1)).lat wp(k(1)).lon];
    end
end    
end