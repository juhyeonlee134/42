#include "Connection.hpp"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/event.h>
#include <fcntl.h>
#include <unistd.h>
#include <map>
#include <string>
#include <iostream>

Connection::Connection()
{
	initServerSocket(this->mListening, this->mListeningAddr);
	initEvent(this->mKqueueFd, this->mListening, this->events);
	std::cout << "server runing\n";
}

Connection::~Connection()
{
	close(this->mListening);
	close(this->mKqueueFd);
	std::memset(&(this->mListeningAddr), 0, sizeof(this->mListeningAddr));
	std::cout << "Good bye :)\n";
}

void Connection::echo(void)
{
	struct kevent eventArr[10];
	int newEvent = kevent(this->mKqueueFd, &this->events[0], this->events.size(), eventArr, 10, NULL);
	if (newEvent < 0)
	{
		throw std::runtime_error("kevent() error");
	}
	this->events.clear();
	for (int indext = 0; indext < newEvent; indext++)
	{
		struct kevent * currEvent = &eventArr[indext];
		if (currEvent->flags & EV_ERROR) // in error event
		{
			if (static_cast<fd_t>(currEvent->ident) == this->mListening)
			{
				throw std::logic_error("server socket error");
			}
			else
			{
				disconnect(this->mClients, currEvent->ident);
				std::cerr << "client socket error\n";
			}
		}
		else if (currEvent->filter == EVFILT_READ) // in read event
		{
			this->readHandling(currEvent);
		}
		else if (currEvent->filter ==EVFILT_WRITE) // in write event
		{
			this->writeHandling(currEvent);
		}
	}
}

void Connection::readHandling(struct kevent const * event)
{
	if (static_cast<fd_t>(event->ident) == this->mListening) // server socket
	{
		fd_t clientSocket;
		if ((clientSocket = accept(this->mListening, NULL, NULL)) == -1)
		{
			throw std::runtime_error("accept() error");
		}
		std::cout << "accept new client : " << clientSocket << "(fd)\n";
		fcntl(clientSocket, F_SETFL, O_NONBLOCK);
		changeEvent(this->events, clientSocket, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
		changeEvent(this->events, clientSocket, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, NULL);
		this->mClients[clientSocket] = "";
	}
	else if (this->mClients.find(event->ident) != this->mClients.end()) // find client socekt
	{
		char buf[1024];
		int len = read(event->ident, buf, sizeof(buf) - 1);
		if (len < 0)
		{
			throw std::logic_error("client read error");
		}
		else if (len == 0)
		{
			disconnect(this->mClients, event->ident);
		}
		else
		{
			buf[len] = '\0';
			this->mClients[event->ident] += buf;
			std::cout << "received data from " << event->ident;
		}
	}
}

void Connection::writeHandling(struct kevent const * event)
{
	std::map<fd_t, std::string>::iterator it = this->mClients.find(event->ident);
	if (it != this->mClients.end() && this->mClients[event->ident] != "")
	{
		char const * echoStr = this->mClients[event->ident].c_str();
		int ret = write(event->ident, echoStr, sizeof(echoStr));
		if (ret < 0)
		{
			disconnect(this->mClients, event->ident);
			std::cerr << "client write error\n";
		}
		else
		{
			this->mClients[event->ident].clear();
		}
	}
}

void Connection::initServerSocket(fd_t & listening, struct sockaddr_in & addr)
{
	if ((listening = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		throw std::runtime_error("socket() error");
	}
	fcntl(listening, F_SETFL, O_NONBLOCK);
	std::memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8080);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(listening, (struct sockaddr *)(&addr), sizeof(addr)) < 0)
	{
		throw std::runtime_error("bind() error");
	}
	if (listen(listening, 5) < 0)
	{
		throw std::runtime_error("listen() error");
	}
}

void Connection::initEvent(fd_t & kqueueFd, fd_t const listening, std::vector<struct kevent> & events)
{
	if ((kqueueFd = kqueue()) < 0)
	{
		throw std::runtime_error("kqueue() error");
	}
	changeEvent(events, listening, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
}

void Connection::changeEvent(std::vector<struct kevent> & events, uintptr_t ident, int16_t filter, uint16_t flags, uint32_t fflags, intptr_t data, void * udata)
{
	struct kevent event;
	EV_SET(&event, ident, filter, flags, fflags, data, udata);
	events.push_back(event);
}

void Connection::disconnect(std::map<fd_t, std::string> & clients, fd_t clientSocket)
{
	close(clientSocket);
	clients.erase(clientSocket);
}
