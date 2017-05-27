#include "request_parser.h"
#include <cstring>
#include <string>

namespace http
{

int RequestParser::parse(const std::string& reqstr, Request& req)
{
	return parse(reqstr.c_str(), reqstr.size(), req);	
}

int RequestParser::parse(const char* buf, int n, Request& req)
{
	//
}

int RequestParser::consume(const char* buf, int n, int offset, Request& req, ParseState state)
{
	static char* rey = "\r";
	const char* rpos = strstr(buf+offset, rey);
	if (rpos == NULL)
	{
		return http::BAD;
	}
	if (*++rpos != '\n')
	{
		return http::BAD;
	}
	if (state == http::BEGIN)
	{
		int action = 1;//1==>method;2==>uri;3==>version
		char* space = " ";
		char* spos = strstr(buf+offset, space);
		if (spos == NULL)
		{
			return http::BAD;
		}
		std::string method;
		char* temp = (char*)buf+offset;
		while(temp != spos)
		{
			method.push_back(*temp);
			++temp;
		}
		int method_type;
		if (!is_method(method, method_type))
		{
			return http::BAD;
		}
		//find uir
		spos = strstr(spos+1, space);
		if (spos == NULL)
		{
			return http::BAD;
		}
		temp = temp + 1;
		std::string uri;
		while(temp != spos)
		{
			uri.push_back(*temp);
			++temp;
		}
		req.uri = uri;
		//find ver
		spos = strstr(spos+1, rey);
		if (spos == NULL)
		{
			return http::BAD;
		}
		if (*(spos + 1) != '\n')
		{
			return http::BAD;
		}
		temp = temp + 1;
		while(temp != spos)
		{
			if (*temp == '1')
			{
				req.version.major = 1;
				if (temp + 2 < spos)
				{
					req.version.minor = (temp+2) - '0';
				}
				else
				{
					return http::BAD;
				}
			}
		}
	}
	else
	{
	}
	int new_offset = rpos+1 - buf;
	if (buf + new_offset
}

}
