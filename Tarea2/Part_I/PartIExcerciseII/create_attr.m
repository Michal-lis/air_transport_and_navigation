function attr=create_attr()
%------------------------------------------------------------------------
% GENERAL
%------------------------------------------------------------------------
% Applicable to kmlwrite_polyline, kmlwrite_polygon,and kmlwrite_volume
% Attributes that apply to the label and icon of the figure
%------------------------------------------------------------------------
% attr.label:Label for the whole figure
% attr.labelscale: Label scale of figure label
% attr.labelcolor: Label color of figure label
% attr.iconurl: File or URL where the graphic for the label of the icon is defined
% attr.iconscale: Icon scale;
% attr.extrude: Specifies whether to connect the figure to the ground (see KML reference).
%------------------------------------------------------------------------
attr.label='label';
attr.labelscale=1.0;
attr.labelcolor='ffffeeee';
attr.iconurl='http://maps.google.com/mapfiles/kml/paddle/wht-circle.png';
attr.iconscale=1.0;
attr.extrude=false;

%------------------------------------------------------------------------
% UPPER SURFACE
%------------------------------------------------------------------------
% Applicable to kmlwrite_polyline, kmlwrite_polygon ,and kmlwrite_volume
% Attributes that apply to the upper surface of a volume, the main surface o a polygon
% and also to the open surface defined by a polyline
%------------------------------------------------------------------------
% attr.color: Color in RGB.
%             Example: FF0055AA is Transparency level=FF, B=00, G=55, R=AA
% attr.fill: Fill surface with color: true OR false.
% attr.altmode: altitude mode =?absolute? OR ?clampToGround' OR 'relativeToGround'
%------------------------------------------------------------------------
attr.color='55555555';
attr.fill=true;
attr.altmode='absolute'; %'clampToGround', 'relativeToGround'

%------------------------------------------------------------------------
% LOWER SURFACE
%------------------------------------------------------------------------
% Applicable to kmlwrite_volume only
% Same attributes that for upper surface
%------------------------------------------------------------------------
attr.color2='551111ff';
attr.fill2=true;
attr.altmode2='relativeToGround'; 

%------------------------------------------------------------------------
% LATERAL SURFACE
%------------------------------------------------------------------------
% Applicable to kmlwrite_volume only
% Same attributes that for upper surface except the altitude
%------------------------------------------------------------------------
attr.latcolor='ff999999';
attr.latfill=true;

%------------------------------------------------------------------------
% EDGES
%------------------------------------------------------------------------
% Applicable to kmlwrite_polyline, kmlwrite_polygon ,and kmlwrite_volume
% Attributes of all edges of a polyline, polygon, or volume.
%------------------------------------------------------------------------
attr.edgewidth=1;
attr.edgecolor='88333333';

%------------------------------------------------------------------------
% WAYPOINTS
%------------------------------------------------------------------------
% Applicable to kmlwrite_polyline, kmlwrite_polygon ,and kmlwrite_volume
% % Attributes of the waypoint that define the upper surface of a figure
% Mainly used with kmlwrite_polyline
%------------------------------------------------------------------------
% attr.wplabelscale: Scale of wp(i).name
% attr.wplabelcolor: Color of wp(i).name
% attr.wpiconurl: File or URL where the graphic for the label of the wp(i).name is defined
%------------------------------------------------------------------------
attr.wplabelscale=.8;
attr.wplabelcolor='fffffffff';
attr.wpiconurl='http://maps.google.com/mapfiles/kml/shapes/triangle.png';
attr.wpiconscale=0.5;
end