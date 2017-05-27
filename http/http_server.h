#ifndef HTTP_SERVER_H
/*
* A http server that only with implementation of GET method
* 2017-5-27 by Lin Xing
*/

#define HTTP_SERVER_H

#include <boost/shared_ptr.hpp>

class TcpServer;

#define BUF_SIZE (4096+1024)

namespace http
{

//class RequestParser;
class Request;
class Responese;

class HttpServer
{
public:
	HttpServer(unsigned port);
	void start();

private:
	TcpServer* _tcp_server;
	unsigned _port;
private:
	int do_read(int);
	int handle_request(Request&, Response&);
};

}

#endif
