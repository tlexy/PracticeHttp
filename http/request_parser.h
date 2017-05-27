#ifndef REQUEST_PARSER
#define REQUEST_PARSER

#include <string>

namespace http
{

enum ParseState
{
	BEGIN = 11,
	HEADER = 12,
	BAD = 13,
	GOOD = 14,
};

class Request;

class RequestParser
{
public:
	static int parse(const std::string& request_string, Request&);
	static int parse(const char* buf, int n, Request&);

private:
	//parse the request one per line on one time.
	static int consume(const char* buf, int n, int offset, Request&, ParseState state);
};

}

#endif
