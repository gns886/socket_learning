#include "client.h"
#include <iostream>
void client() {
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	int ok;
	char hostname[128] = {0};
	int namelen = 128;
	SOCKET sock = socket(PF_INET, SOCK_STREAM, 0);


	//���������������
	sockaddr_in sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));
	
	sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    sockAddr.sin_family = PF_INET;
	sockAddr.sin_port = htons(1234);
	
	ok = connect(sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));

	if (ok == SOCKET_ERROR)
	{
		printf("ok:%d \n", ok);
	}
	//printf("%s", sockAddr);
	//���ܷ��������ص�����
	char data_buffer[MAXBYTE] = {0};
	ok = recv(sock, data_buffer, MAXBYTE, NULL);
	if (ok == SOCKET_ERROR)
	{
		printf("can't receive the message!");
	}
	std::cout<<data_buffer;
	//printf("Message from server: %s\n", data_buffer);

	//�ر�
	closesocket(sock);

	//��ֹʹ��DLL
	WSACleanup();


	system("pause");
//	return(0);
}