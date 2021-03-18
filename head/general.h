#pragma once
#include <winsock2.h>
#include <iostream>
#pragma comment(lib, "ws2_32.lib")

#define _MAX_CHAR_ 128

void getHostIP(char* &hostname, char* &IPAdress);