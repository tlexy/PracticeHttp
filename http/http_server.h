#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include <boost/shared_ptr.hpp>

namespace http
{

class RequestParser;
class Request;
class Responese;

class HttpServer
{
public:
	HttpServer();
	void start();
};

}

#endif
