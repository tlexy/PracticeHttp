#include <iostream>
#include <string.h>
#include "socket.h"
#include "ip_address.h"
#include <string>
#include <stdlib.h>

int main()
{
	Socket sock(-1, false);
	IpAddress ipaddr;
	ipaddr.setIp(std::string("127.0.0.1"));
	ipaddr.setPort(20000);
	sock.bindAddress(ipaddr);
	sock.connect();
	char buf[1024];
	while (1)
	{
		bzero(buf, 1024);
		std::cin.getline(buf, 1024);
		sock.send(&buf, strlen(buf));
		int n = sock.recv(&buf, 1024);
		if (n != 0)
		{
			std::cout << &buf[0] << std::endl;
		}
		else
		{
			std::cout << "error" << std::endl;
			exit(1);
		}
	}

	return 0;
}
