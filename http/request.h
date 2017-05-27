#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <unordered_map>

namespace http
{

enum Method
{
	GET = 1,
	POST = 2,
};

struct HttpVersion
{
	int major;
	int minor;
};

struct HttpHeaderPair
{
	std::string key;
	std::string value;
};

struct Request
{
	int method;
	HttpVersion version;
	std::string uri;
	//key to header pair map.
	std::unordered_map<std::string, HttpHeaderPair> Headers;
};

}

#endif
