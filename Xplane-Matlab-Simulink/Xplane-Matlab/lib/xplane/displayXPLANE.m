function displayXPLANE(data)
% Display the following Xplane data in console:

% data.position.latitude  : Latitude in decimal degrees
% data.position.longitude : Longitude in decimal degrees
% data.position.altitude  : Altitude in feet
%
% data.eulers.pitch       : Pitch angle in degrees
% data.eulers.roll        : Roll angle in degrees
% data.eulers.heading     : Heading angle in degrees
%
% data.ias                : Indicated Airspeed in mph
% data.tas                : True Airspeed in mph
% data.gs                 : Ground speed in mph
%
% data.vspeed             : Vertical speed in fpm
% data.brakes             : Parking brakes. Boolean.
%
% data.angles.alpha       : Angle of attack in degrees
% data.angles.beta        : Sideslip angle in degrees
% data.angles.vpath       : The pitch the aircraft actually flies in degrees. (vpath+alpha=theta)
% NOT SHOWN:
% data.rates.pitch        : Pitch rate in degrees
% data.rates.roll         : Roll rate in degrees
% data.rates.heading      : Heading rate in degrees
% data.angles.hpath       : The heading the aircraft actually flies in degrees. (hpath+beta=psi)

clc;
fprintf('Lat : \t%7.4f \t Lon  : \t%7.4f \t Alt  :\t\t%7.4f \n', data.position.latitude, data.position.longitude, data.position.altitude);
fprintf('Roll: \t%7.4f \t Pitch: \t%7.4f \t Head :\t\t%7.4f \n', data.eulers.roll, data.eulers.pitch, data.eulers.heading);
fprintf('IAS : \t%7.4f \t TAS  : \t%7.4f \t GS   :\t\t%7.4f \n', data.ias, data.tas, data.gs);
fprintf('VS  : \t%7.4f \t brake: \t%7.4f \n', data.vspeed, data.brake);
fprintf('AoA : \t%7.4f \t Beta : \t%7.4f \t Vpath:\t\t%7.4f \t Hpath:\t\t%7.4f \n', data.angles.alpha, data.angles.beta, data.angles.vpath, data.angles.hpath);

end