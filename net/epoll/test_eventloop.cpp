#include "base/thread.h"
#include <boost/bind.hpp>
#include "event_loop.h"
#include "sapper.h"
#include "socket_util.h"
#include "socket.h"
#include "common.hpp"
#include <string.h>
#include <iostream>

Socket sock(-1);

EventLoopPtr event_loop = Creator<EventLoop>::Create();

void read()
{
	IpAddress ipaddr;
	bzero(&ipaddr, sizeof(ipaddr));
	sock.accept(ipaddr);
	std::cout << "connect from:" << ipaddr.toString() << std::endl;
}

void loop()
{
	IpAddress ipaddr;
	ipaddr.setIp();
	ipaddr.setPort(20000);
	sock.setReuseAddr(true);
	sock.bindAddress(ipaddr);
	sock.listen(10);
	SapperPtr sapper = Creator<Sapper>::Create(sock.fd(), event_loop);
	sapper->focusRead();
	Sapper::CallBackHandler cb = boost::bind(read);
	sapper->setReadHandler(cb);
	event_loop->init();
	event_loop->loop();
}


int main()
{
	Thread th(loop);
	th.start();
	th.join();
	return 0;
}
