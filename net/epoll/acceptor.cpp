#include "acceptor.h"

Acceptor::Acceptor(int port, bool flag, uint64_t ipv4)
	:_sock(Socket(-1, flag))
{
	_sock.setIp();
	_sock.setReuseAddr(true);
}

void Acceptor::listen(int max)
{
	_sock.listen(max);
}

void Acceptor::accept(IpAddress& ipaddr)
{
	bzero(&ipaddr, sizeof(ipaddr);
	_sock.accept(ipaddr);
}
