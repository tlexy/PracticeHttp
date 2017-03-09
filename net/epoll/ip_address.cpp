#include "ip_address.h"
#include <boost/lexical_cast.hpp>
#include <stdlib.h>
#include <string.h>

#define IPV4_LEN 16

IpAddress::IpAddress(int family, unsigned short port)
{	
	_addr.addr_ip4.sin_family = family;
	_addr.addr_ip4.sin_port = htons(port);
}

void IpAddress::setIp(uint32_t ip, int family)
{
	if (family == AF_INET)
	{
		_addr.addr_ip4.sin_addr.s_addr = htonl(ip);
	}
}

void IpAddress::setIp(const std::string& ip_str, int family)
{
	if (family == AF_INET)
	{
		inet_pton(AF_INET, ip_str.c_str(), &_addr.addr_ip4.sin_addr.s_addr);
	}
}

void IpAddress::setPort(unsigned short  port)
{
	_addr.addr_ip4.sin_port = htons(port);
}

std::string IpAddress::toString(bool withPort)
{
	if (_addr.addr_ip4.sin_family != AF_INET)
	{
		return std::string();
	}
	char buf[IPV4_LEN];
	inet_ntop(AF_INET, (void*)&_addr.addr_ip4.sin_addr.s_addr, (char*)&buf, IPV4_LEN);
	std::string ip((const char*)&buf);	
	if (withPort)
	{
		ip.append(":");
		ip.append(boost::lexical_cast<std::string>(ntohs(_addr.addr_ip4.sin_port)));
	}

	return ip;
}

int IpAddress::addressLength()
{
	if (_addr.addr_ip4.sin_family == AF_INET)
	{
		return sizeof(_addr.addr_ip4);
	}
	return 0;
}

IpAddress IpAddress::fromRawSocketAddress(sockaddr* sa, socklen_t len)
{
	IpAddress ip;
	memcpy(ip.rawAddressPtr(), sa, len);
	return ip;
}
