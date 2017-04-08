#pragma once

#include <string.h>

class Client
{
public:
	Client();
	~Client();
	void InitClient(int port, char* ip);
	void Send(char* msg);
	char* Recv();
	void Disconnect();
};

