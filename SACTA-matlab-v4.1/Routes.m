function [routes,wpts]=Routes(file)
% Define airways and waypoints in the Valencia airspace
addpath('lib/geo');
global fid;

if nargin>0
    fid=fopen(file,'w');
    if fid<=0
        fid=1;
    end
else
    fid=1;
end

% VORs in airports
vlc=WPT('LEVC','392908N','0002900W',9,'O');
bcn=WPT('LEBL','411826N','0020629E',9,'O');
alt=WPT('LEAL','381606N','0003412W',9,'O');
mjv=WPT('LEPA','392607N','0024529E',9,'O');
iba=WPT('LEIB','385206N','0012157E',9,'O');
ctn=WPT('LECH','401351N','0000835E',9,'O');

% Other airports
lebt=WPT('LEBT','N039°37''26.00"','W000°28''26.00"',9,'*');
lere=WPT('LERE','N039°28''29.00"','W001°02''04.00"',9,'*');

% Other VORs
cjn=WPT('CJN','402219N','0023241W',6,'*');
cdp=WPT('CDP','394151N','0032603E',6,'*');
yes=WPT('YES','382139N','0022109W',6,'*');
mla=WPT('MLA','410747N','0000956E',6,'*');
cma=WPT('CMA','405202N','0011753W',6,'*');
pdt=WPT('PDT','401510N','0032052W',6,'*');

%NDBs
lrd=WPT('LRD','413311N','0003853E',6,'*');
iza=WPT('IZA','385456N','0012813E',6,'*');
% Ibiza NDB IZA 394 KHz N385455 E0012813

% Fixes
rafol=WPT('RAFOL','375658N','0000101W',6,'*');
sopet=WPT('SOPET','395002N','0000017W',6,'*');
labro=WPT('LABRO','371629N','0010726E',6,'*');
abosi=WPT('ABOSI','394645N','0011705W',6,'*');
mabux=WPT('MABUX','393257N','0010859W',6,'*');
laspo=WPT('LASPO','391657N','0003240W',6,'*');
astro=WPT('ASTRO','390128N','0011547W',6,'*');
restu=WPT('RESTU','375427N','0013327W',6,'*');
lotos=WPT('LOTOS','403259N','0010011E',6,'*');
gervu=WPT('GERVU','384911N','0002900E',6,'*');

% Fixes close to Valencia
mulat=WPT('MULAT','392400N','0001048W',6,'*');
opera=WPT('OPERA','393722N','0004644W',6,'*');
argor=WPT('ARGOR','393219N','0001755E',6,'*');
ninot=WPT('NINOT','391232N','0002900E',6,'*');
cls=WPT('CLS','394226N','0005911W',6,'*');
saura=WPT('SAURA','401522N','0001100W',6,'*');
nargo=WPT('NARGO','384418N','0005955W',6,'*');

wpts=[vlc,bcn,alt,iba,ctn,lebt,lere,cjn,cdp,yes,mla,cma,pdt,lrd,iza,...
      rafol,sopet,labro,abosi,mabux,laspo,astro,restu,lotos,gervu,...
      mulat, opera,argor,ninot,cls,saura,nargo];


% Routes close to Valencia

% A-33
% CASTEJÓN 'CJN' DVOR/DME 402219N 0023241W
% VALENCIA 'VLC' DVOR/DME 392908N 0002900W
% CAPDEPERA 'CDP' DVOR/DME 394151N 0032603E
%
a33=RTE('A33',cjn,vlc,cdp);
routes{1}=a33;

% B-28
% BARCELONA 'BCN' DVOR/DME 411826N 0020629E
% VALENCIA 'VLC' DVOR/DME 392908N 0002900W
% YESTE 'YES' VOR/DME 382139N 0022109W
%
b28=RTE('B28',bcn,lotos,sopet,vlc,yes);
routes{2}=b28;

% N-608
% RAFOL 375658N 0000101W
% SOPET 395002N 0000017W
% LÉRIDA NDB 404 LRD 413311N 0003853E
%
n608=RTE('N608',rafol,sopet,lrd);
routes{3}=n608;

% A-34
% MAELLA 'MLA' DVOR/DME 410747N 0000956E
% VALENCIA 'VLC' DVOR/DME 392908N 0002900W
% ALICANTE VOR/DME 113.80 ALT 381606N 0003412W
%
a34=RTE('A34',mla,vlc,alt);
routes{4}=a34;

% R-29
% ALICANTE VOR/DME 113.80 ALT 381606N 0003412W
% CALAMOCHA VOR/DME 116.00 CMA 405202N 0011753W
%
r29=RTE('R29',alt,cma);
routes{5}=r29;

% L-150
% LABRO 371629N 0010726E
% ALICANTE VOR/DME 113.80 ALT 381606N 0003412W
% CASTEJÓN 'CJN' DVOR/DME 402219N 0023241W
%
l150=RTE('L150',labro,alt,cjn);
routes{6}=l150;

% M-871
% ABOSI 394645N 0011705W
% MABUX 393257N 0010859W
% LASPO 391657N 0003240W
% PALMA DE MALLORCA DVOR/DME 113.30 MJV 392607N 0024529E
%
m871=RTE('M871',pdt,abosi,mabux,laspo,mjv);
routes{7}=m871;

% Z-224
% LASPO 391657N 0003240W
% ASTRO 390128N 0011547W
% IBIZA VOR/DME 117.80 IBA 385206N 0012157E
%
z224=RTE('Z224',laspo,astro,iba);
routes{8}=z224;

% G-850
% VALENCIA 'VLC' DVOR/DME 392908N 0002900W
% RESTU 375427N 0013327W
%
g850=RTE('G850',vlc,restu);
routes{9}=g850;

% R-59
% ALICANTE VOR/DME 113.80 ALT 381606N 0003412W
% GERVU 384911N 0002900E
% CAPDEPERA 'CDP' DVOR/DME 394151N 0032603E
% 
r59=RTE('R59',alt,gervu,cdp);
routes{10}=r59;

% B-46
% IBIZA VOR/DME 117.80 IBA 385206N 0012157E
% ALICANTE VOR/DME 113.80 ALT 381606N 0003412W
% RESTU 375427N 0013327W
%
b46=RTE('B46',iba,alt,restu);
routes{11}=b46;

% T-412
% LOTOS 403259N 0010011E 
% CASTELLÓN 'CTN' DVOR/DME 401308N 0000521E
t412=RTE('T412',lotos,ctn);
routes{12}=t412;

% G-30
%
% Ibiza NDB IZA 394 KHz N385455 E0012813
% VALENCIA 'VLC' DVOR/DME 392908N 0002900W
g30=RTE('G30',iza,vlc);
routes{13}=g30;

% LEBT 39°37'26'N, 0°28'26'W
% LERE 39º28'29''N 001º02'04''W

clear fid;

end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Functions to generate wpts, routes
% and java code for SACTA
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function wpt=WPT(name,lat,lon,color,icon)
global fid
wpt.name=name;
wpt.lat=sex2dec(lat);
wpt.lon=sex2dec(lon);
wpt.color=color;
wpt.icon=icon;

fprintf(fid,'Punt %s_pt = new Punt(%g,%g);\n',wpt.name,wpt.lon, wpt.lat);
fprintf(fid, 'Waypoint %s = new Waypoint("%s",%s_pt,%g,%g);\n',wpt.name,wpt.name,wpt.name,wpt.color,wpt.icon);
fprintf(fid,'waypoints.add(%s);\n\n',wpt.name);
end

function rte=RTE(varargin)
global fid

rte=[];
fprintf(fid,'// Route: %s\n',varargin{1});
fprintf(fid,'Poligon %s=new Poligon();\n',varargin{1});
for i=2:nargin
    rte=[rte;[varargin{i}.lon,varargin{i}.lat]];
    fprintf(fid,'%s.AfegirPunt(%s_pt);\n',varargin{1},varargin{i}.name);
end
  fprintf(fid,'rutes.add(%s);\n',varargin{1});
end