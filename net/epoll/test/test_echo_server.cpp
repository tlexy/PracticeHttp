#include <iostream>
#include <boost/bind.hpp>
#include "../tcp_server.h"
#include "../socket_util.h"

char buf[1024];

int echo(int sockfd)
{
	//std::cout << "data arrive..." << std::endl;
	int	n = SocketUtil::Read(sockfd, buf, 1024);
	//std::cout << "n=" << n << std::endl;
	if (n == 0)
	{
		std::cout << "client close connection." << std::endl;
		return 1;
	}
	buf[n] = '\0';
	std::cout << &buf[0] << std::endl;
	return 0;
}

int main()
{
	TcpServer::ReadHandler handler = boost::bind(echo, _1);
	TcpServer server(55455, handler, 1);
	server.start();

	return 0;
}
