#include "server.h"
#include <string>
#define _WINSOCK_DEPRECATED_NO_WARNINGS 
#define _WINSOCK_DEPRECATED_NO_WARNINGS




void server() {
    //��ʼ�� DLL
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	bool ok;
	//�����׽���
	SOCKET servSock = socket(PF_INET, SOCK_STREAM, 0);

	//�ж���Ч�׽���
	if (servSock == INVALID_SOCKET)
	{
		printf("socket error!");
		return;
	}

	sockaddr_in sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));             //ÿ���ֽڶ���0���
	sockAddr.sin_family      = PF_INET;                 //ʹ��IPV4��ַ
	sockAddr.sin_port        = htons(1234);             //���ö˿�
	sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  //����ip��ַ

	ok = bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
	if (ok == SOCKET_ERROR)
	{
		printf("can't bind the socket!");
		return;
	}
	listen(servSock, 20);

	//���ܿͻ�������
	SOCKADDR clntAddr;
	int nSize = sizeof(SOCKADDR);
	SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nSize);
	printf("hello:%s", clntAddr.sa_data);
	//��ͻ��˷�������
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
	   std::cout << "�����룺";
	   std::cin >> str;
	   send(clntSock, str, );
	   if (strcmp(str, "quit"))
	   {
		   break;
	   }
	}
	//�ر��׽���
	closesocket(clntSock);
	closesocket(servSock);

	//��ֹDLL��ʹ��
	WSACleanup();

}