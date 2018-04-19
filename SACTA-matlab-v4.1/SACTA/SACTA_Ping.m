function status = SACTA_Ping()
% It sends a ping to the SACTA monitor to check it is alive.
%
% RETURN VALUES
% It returns an "0" if success
%

status = SACTA_SendCmd('ping', 'nada');
end
    
    

