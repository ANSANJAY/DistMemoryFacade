#include "headers.h"
#include "declarations.h"

void forwardUDP( int destination_node ,char sendString[] )
{

	destination_node = destination_node % N;		//destination node to which data is to be forwaded
	int sock;
	struct sockaddr_in server_addr;
				
	struct hostent *host;			//hostent predefined structure use to store info about host
	host = (struct hostent *) gethostbyname(node[destination_node].ip_address);//gethostbyname returns a pointer to hostent 
	if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
	{

		perror("socket");
		exit(1);
	}

	//destination address structure
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(node[destination_node].udpportno);		
	server_addr.sin_addr = *((struct in_addr *)host->h_addr);	//host->h_addr gives address of host
	bzero(&(server_addr.sin_zero),8);
	sendto(sock, sendString, strlen(sendString), 0,(struct sockaddr *)&server_addr, sizeof(struct sockaddr));

	//sendto() function shall send a message through a connectionless-mode socket. 
	printf("\nFORWARD REQUEST : '%s' has been forwarded to node ---->%d\n",sendString,destination_node);  
	close(sock);
} 

