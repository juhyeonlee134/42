#pragma once
#ifndef __CONNECTION_H__
#define __CONNECTION_H__

#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/event.h>
#include <map>
#include <vector>
#include <string>

typedef int fd_t;

class Connection
{
public:
	Connection();
	~Connection();
	void echo(void);
private:
	fd_t mListening;
	fd_t mKqueueFd;
	struct sockaddr_in mListeningAddr;
	std::vector<struct kevent> events;
	std::map<fd_t, std::string> mClients;
	void readHandling(struct kevent const * event);
	void writeHandling(struct kevent const * event);
	static void initServerSocket(fd_t & listening, struct sockaddr_in & addr);
	static void initEvent(fd_t & kqueueFd, fd_t const listening, std::vector<struct kevent> & events);
	static void changeEvent(std::vector<struct kevent> & events, uintptr_t ident, int16_t filter, uint16_t flags, uint32_t fflags, intptr_t data, void * udata);
	static void disconnect(std::map<fd_t, std::string> & clients, fd_t clientSocket);
};

#endif
