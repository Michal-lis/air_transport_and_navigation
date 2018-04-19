if(strcmp(computer, 'PCWIN'))
	import('freemat-net.dll', 'udp_send', 'udp_send', 'int32', 'string data, int32 tam, int32 port, string ip');
	import('freemat-net.dll', 'udp_recv', 'udp_recv', 'int32', 'string &data, int32 tam, int32 port');
	import('freemat-net.dll', 'tcp_connect', 'tcp_connect', 'int32', 'string ip, int32 port');
	import('freemat-net.dll', 'tcp_disconnect', 'tcp_disconnect', 'int32', 'int32 fd');
	import('freemat-net.dll', 'tcp_recv', 'tcp_recv', 'int32', 'int32 fd, string &data, int32 tam');
	import('freemat-net.dll', 'tcp_send', 'tcp_send', 'int32', 'int32 fd, string data, int32 tam');
	import('freemat-net.dll', 'tcp_getchar', 'tcp_getchar', 'uint8', 'int32 fd');
	import('freemat-net.dll', 'tcp_ungetchar', 'tcp_ungetchar', 'void', '');
	import('freemat-net.dll', 'tcp_readline', 'tcp_readline', 'int32', 'int32 fd, string &buff, int32 tam');
elseif(strcmp(computer, 'MAC'))
	import('freemat-net.dylib', 'udp_send', 'udp_send', 'int32', 'string data, int32 tam, int32 port, string ip');
	import('freemat-net.dylib', 'udp_recv', 'udp_recv', 'int32', 'string &data, int32 tam, int32 port');
	import('freemat-net.dylib', 'tcp_connect', 'tcp_connect', 'int32', 'string ip, int32 port');
	import('freemat-net.dylib', 'tcp_disconnect', 'tcp_disconnect', 'int32', 'int32 fd');
	import('freemat-net.dylib', 'tcp_recv', 'tcp_recv', 'int32', 'int32 fd, string &data, int32 tam');
	import('freemat-net.dylib', 'tcp_send', 'tcp_send', 'int32', 'int32 fd, string data, int32 tam');
	import('freemat-net.dylib', 'tcp_getchar', 'tcp_getchar', 'uint8', 'int32 fd');
	import('freemat-net.dylib', 'tcp_ungetchar', 'tcp_ungetchar', 'void', '');
	import('freemat-net.dylib', 'tcp_readline', 'tcp_readline', 'int32', 'int32 fd, string &buff, int32 tam');
elseif(strcmp(computer, 'UNIX'))
	import('freemat-net.so', 'udp_send', 'udp_send', 'int32', 'string data, int32 tam, int32 port, string ip');
	import('freemat-net.so', 'udp_recv', 'udp_recv', 'int32', 'string &data, int32 tam, int32 port');
	import('freemat-net.so', 'tcp_connect', 'tcp_connect', 'int32', 'string ip, int32 port');
	import('freemat-net.so', 'tcp_disconnect', 'tcp_disconnect', 'int32', 'int32 fd');
	import('freemat-net.so', 'tcp_recv', 'tcp_recv', 'int32', 'int32 fd, string &data, int32 tam');
	import('freemat-net.so', 'tcp_send', 'tcp_send', 'int32', 'int32 fd, string data, int32 tam');
	import('freemat-net.so', 'tcp_getchar', 'tcp_getchar', 'uint8', 'int32 fd');
	import('freemat-net.so', 'tcp_ungetchar', 'tcp_ungetchar', 'void', '');
	import('freemat-net.so', 'tcp_readline', 'tcp_readline', 'int32', 'int32 fd, string &buff, int32 tam');
end
