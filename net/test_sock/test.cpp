#include <iostream>
#include "ip_address.h"
#include "socket_util.h"
#include "socket.h"
#include <string.h>
#include "thread.h"
#include <boost/bind.hpp>
/* 
*echo server
*/

void talk(int connfd)
{
	Socket sock(connfd, false);
	char buf[1024];
	while(1)
	{
		bzero(&buf[0], 1024);
		int n = sock.recv(&buf[0], 1024);
		std::cout << "recv n = " << n << std::endl;
		buf[n] = '\0';
		std::cout << "recv:" << &buf[0] << std::endl;
		sock.send(&buf[0], n);
	}
}

int main()
{
	Socket sock(-1, false);
	sock.setReuseAddr(true);
	IpAddress addr;
	addr.setIp();
	addr.setPort(20000);
	sock.bindAddress(addr);
	sock.listen(10);
	while(1)
	{
		IpAddress c_addr;
		int connfd = sock.accept(c_addr);
		std::cout << "connect from：" << c_addr.toString() << std::endl;
		Thread* th = new Thread(boost::bind(talk, connfd));
		th->start();
	}
	return 0;
}
