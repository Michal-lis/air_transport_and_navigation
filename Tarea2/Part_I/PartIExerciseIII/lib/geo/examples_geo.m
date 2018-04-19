clc; clear all;
fprintf('\n DIRECT FORMULA--------------------------------------------------------\n');

fprintf('\n(lat1,lon1,lat2,lon2) = (0,0,90,0)\n');
[s,a12,a21] = vincenty_distazi(0,0,90,0);
fprintf('Vincenty- s=%g, a12=%g, a21=%g\n',s,a12,a21);
[s,a12,a21] = orto_distazi(0,0,90,0);
fprintf('Orto-     s=%g, a12=%g, a21=%g\n',s,a12,a21);
[s,a12,a21] = loxo_distazi(0,0,90,0);
fprintf('Loxo-     s=%g, a12=%g, a21=%g\n',s,a12,a21);

fprintf('\n(lat1,lon1,lat2,lon2) = (0,0,0,90)\n');
[s,a12,a21] = vincenty_distazi(0,0,0,90);
fprintf('Vincenty- s=%g, a12=%g, a21=%g\n',s,a12,a21);
[s,a12,a21] = orto_distazi(0,0,0,90);
fprintf('Orto-     s=%g, a12=%g, a21=%g\n',s,a12,a21);
[s,a12,a21] = loxo_distazi(0,0,0,90);
fprintf('Loxo-     s=%g, a12=%g, a21=%g\n',s,a12,a21);

fprintf('\n(lat1,lon1,lat2,lon2) = (0,0,45,45)\n');
[s,a12,a21] = vincenty_distazi(0,0,45,45);
fprintf('Vincenty- s=%g, a12=%g, a21=%g\n',s,a12,a21);
[s,a12,a21] = orto_distazi(0,0,45,45);
fprintf('Orto-     s=%g, a12=%g, a21=%g\n',s,a12,a21);
[s,a12,a21] = loxo_distazi(0,0,45,45);
fprintf('Loxo-     s=%g, a12=%g, a21=%g\n',s,a12,a21);

%--------------------------------------------------------
fprintf('\n INVERSE FORMULA--------------------------------------------------------\n');
s=6662470;
fprintf('\n(lat1,lon1,s,a12) = (0,0,%g,0)\n',s);
[lat2,lon2,a21] = vincenty_reckon(0,0,s,0);
fprintf('Vincenty- lat2=%g, lon2=%g, a21=%g\n',lat2,lon2,a21);
[lat2,lon2,a21] = orto_reckon(0,0,s,0);
fprintf('Orto    - lat2=%g, lon2=%g, a21=%g\n',lat2,lon2,a21);
[lat2,lon2,a21] = loxo_reckon(0,0,s,0);
fprintf('Loxo    - lat2=%g, lon2=%g, a21=%g\n',lat2,lon2,a21);


fprintf('\n(lat1,lon1,s,a12) = (0,0,%g,90)\n',s);
[lat2,lon2,a21] = vincenty_reckon(0,0,s,90);
fprintf('Vincenty- lat2=%g, lon2=%g, a21=%g\n',lat2,lon2,a21);
[lat2,lon2,a21] = orto_reckon(0,0,s,90);
fprintf('Orto    - lat2=%g, lon2=%g, a21=%g\n',lat2,lon2,a21);
[lat2,lon2,a21] = loxo_reckon(0,0,s,90);
fprintf('Loxo    - lat2=%g, lon2=%g, a21=%g\n',lat2,lon2,a21);


fprintf('\n(lat1,lon1,s,a12) = (0,0,%g,45)\n',s);
[lat2,lon2,a21] = vincenty_reckon(0,0,s,45);
fprintf('Vincenty- lat2=%g, lon2=%g, a21=%g\n',lat2,lon2,a21);
[lat2,lon2,a21] = orto_reckon(0,0,s,45);
fprintf('Orto    - lat2=%g, lon2=%g, a21=%g\n',lat2,lon2,a21);
[lat2,lon2,a21] = loxo_reckon(0,0,s,45);
fprintf('Loxo    - lat2=%g, lon2=%g, a21=%g\n',lat2,lon2,a21);

