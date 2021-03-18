#include "server.h"
#include <string>
#define _WINSOCK_DEPRECATED_NO_WARNINGS 
#define _WINSOCK_DEPRECATED_NO_WARNINGS




void server() {
    //初始化 DLL
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	bool ok;
	//创建套接字
	SOCKET servSock = socket(PF_INET, SOCK_STREAM, 0);

	//判断无效套接字
	if (servSock == INVALID_SOCKET)
	{
		printf("socket error!");
		return;
	}

	sockaddr_in sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));             //每个字节都用0填充
	sockAddr.sin_family      = PF_INET;                 //使用IPV4地址
	sockAddr.sin_port        = htons(1234);             //设置端口
	sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  //设置ip地址

	ok = bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
	if (ok == SOCKET_ERROR)
	{
		printf("can't bind the socket!");
		return;
	}
	listen(servSock, 20);

	//接受客户端请求
	SOCKADDR clntAddr;
	int nSize = sizeof(SOCKADDR);
	SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nSize);
	printf("hello:%s", clntAddr.sa_data);
	//向客户端发送数据
	char str[MAXBYTE] = "Hello, ";
	strcat(str, clntAddr.sa_data);
	strcat(str, ", you can talk to me now!\n");
	printf("I want to send: %s\n", str);
	ok = send(clntSock, str, strlen(str) + sizeof(char), NULL);
	if (ok == SOCKET_ERROR)
	    printf("can't send the message!");
	while (1)
	{
	   char *str;
	   std::cout << "请输入：";
	   std::cin >> str;
	   send(clntSock, str, );
	   if (strcmp(str, "quit"))
	   {
		   break;
	   }
	}
	//关闭套接字
	closesocket(clntSock);
	closesocket(servSock);

	//终止DLL的使用
	WSACleanup();

}