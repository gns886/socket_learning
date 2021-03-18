#include "client.h"
#include "server.h"
#include "main.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS 

void selectMod(int &mod)
{
    int x;
    printf("please choose mod:%d.SERVER  %d.CLIENT", _SERVER_MOD_, _CLIENT_MOD_);
	scanf("%d", &x);
	switch (x)
	{
		case _CLIENT_MOD_: mod = _CLIENT_MOD_; client(); break;
		case _SERVER_MOD_: mod = _SERVER_MOD_; server(); break;
		default:           mod = -1;           break;
	}

}

void main()
{
    char a[10] = "cccc";
	char b[10] = "aaaa";
	int mod;
	strcat(a, b);
	//printf("%s", a);
	selectMod(mod);
    //server();
	
}