#include "headers.h"
#include "declarations.h"

/***
This function forwards UDP packets to the next node in the ring topology. 
Forwards a given string (`sendString`) to another node (`destination_node`) using UDP.
- **Parameters**: 
  - `destination_node`: The next node to which data should be forwarded.
  - `sendString[]`: The data that needs to be forwarded.

- **Operations**:
  - It calculates the next destination node by taking the modulo with `N` (`destination_node = destination_node % N`).
  - It uses `gethostbyname()` to get the address of the destination node.
  - It creates a UDP socket (`SOCK_DGRAM`) and initializes its parameters.
  - Finally, it forwards the data to the destination node using `sendto()`.

  Code Explanation:

- `destination_node = destination_node % N;`: This line ensures that the destination node ID wraps around once it reaches the upper limit (`N`), creating a ring structure.

- `int sock; struct sockaddr_in server_addr; struct hostent *host;`: Declare variables for the UDP socket, destination server address, and host information.

- `host = (struct hostent *) gethostbyname(node[destination_node].ip_address);`: Resolves the IP address of the destination node.

- `if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) { ... }`: Creates a UDP socket. If it fails, it exits the program.

- `server_addr.sin_family = AF_INET; ... bzero(&(server_addr.sin_zero),8);`: Initializes the `server_addr` struct with the destination node's details.

- `sendto(sock, sendString, strlen(sendString), 0,(struct sockaddr *)&server_addr, sizeof(struct sockaddr));`: Sends `sendString` to `destination_node` via UDP.

- `printf("\nFORWARD REQUEST : '%s' has been forwarded to node ---->%d\n",sendString,destination_node);`: Logs the forward operation.

- `close(sock);`: Closes the UDP socket.

***/

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

