#include "http_server.h"
#include "../net/epoll/tcp_server.h"
#include <boost/bind.hpp>
#include <../socket_util.h>
#include "request_parser.h"
#include "request.h"
#include "responese.h"

static char buf[BUF_SIZE];

namespace http
{

HttpServer::HttpServer(unsigned port)
	:_port(port)
{
}


int HttpServer::do_read(int sockfd)
{
	int n = SocketUtil::Read(sockfd, buf, BUF_SIZE);
	if (n == 0)
	{
		std::cout << "client close connection." << std::endl;
		return 1;
	}
	buf[n] = '\0';
	
	Request req;
	int res = RequestParser.parse(buf, n, req);
	if (res == 0)
	{
	}
	else if (res == 1)
	{
	}
	else
	{
	}
	Response resp;
	//handle_request(req, resp);
	//SocketUtil::Write(sockfd, resp.data(), resp.length());
}

}
