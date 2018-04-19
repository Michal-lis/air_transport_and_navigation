function dref_displayXPLANE(data)
% Display the Xplane datarefs of data in console.
clc;
for i=1:length(data)
    switch i
        case 1
            fprintf('Latitude    : \t%7.4f\n', data(1));
        case 2
            fprintf('Longitude   : \t%7.4f\n', data(2));
        case 3
            fprintf('Altitude    : \t%7.4f\n', data(3));
        case 4
            fprintf('IAS kts     : \t%7.4f\n', data(4));      
        case 5
            fprintf('TAS kts     : \t%7.4f\n', data(5));
        case 6
            fprintf('GS  kts     : \t%7.4f\n', data(6));
        case 7
            fprintf('VS fpm      : \t%7.4f\n', data(7));
        case 8
            fprintf('Pitch deg   : \t%7.4f\n', data(8));
        case 9
            fprintf('Roll  deg   : \t%7.4f\n', data(9));
        case 10
            fprintf('Heading deg : \t%7.4f\n', data(10));
        case 11
            fprintf('Roll rate   : \t%7.4f\n', data(11));
        case 12
            fprintf('Pitch rate  : \t%7.4f\n', data(12));      
        case 13
            fprintf('Yaw rate    : \t%7.4f\n', data(13));
        case 14
            fprintf('AoA deg     : \t%7.4f\n', data(14));
        case 15
            fprintf('Yaw deg     : \t%7.4f\n', data(15));
        case 16
            fprintf('Vpath deg   : \t%7.4f\n', data(16));
        case 17
            fprintf('Track deg   : \t%7.4f\n', data(17));
        case 18
            fprintf('Parkbrake   : \t%7.4f\n', data(18));
        otherwise
            fprintf('Dataref #%d : \t%7.4f\n', i, data(i));
    end
            
end
end