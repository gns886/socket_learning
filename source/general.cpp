#include "general.h"
void getHostIP(char* &hostname, char* &IPAdress)
{
    const int namelen = 128;
	gethostname(hostname, namelen);
	HOSTENT *host = gethostbyname(hostname);
	char *address;
	address = host->h_addr_list[0];
	in_addr PcAddr;
	memcpy(&(PcAddr.S_un.S_addr), address, host->h_length);
	char *IP = ::inet_ntoa(PcAddr);

	//std::cout << hostname << host << "\n" << IP << "\n";
}
