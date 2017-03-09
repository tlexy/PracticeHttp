#ifndef ACCEPTOR_H
#define ACCEPTOR_H

#include "socket.h"

class Acceptor
{
public:
	Acceptor(int port, bool nonblock = true, uint64_t ipv4 = INADDR_ANY);
	void listen(int max);
	void accept(IpAddress&);
	int fd() { return _sock.fd(); }
private:
	Socket _sock;
};

#endif
