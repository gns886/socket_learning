#pragma once
#include <stdio.h>
#include <winsock2.h>
#include "general.h"
#pragma comment (lib, "ws2_32.lib")  //  ╪сть ws2_32.dll

struct IPAddress{
	char host_name[_MAX_CHAR_];
	char IP_address[16];
};

class server {
	char *name;
	void connectToClient(SOCKET sock);
	void disconnectFromClient(SOCKET sock);
	void sendAMessage();
public:
	void chatwith(IPAddress IP);
};

void server();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            