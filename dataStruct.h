#include "headers.h"
#include "declarations.h"

struct node 
{
	int data;
	struct node *link;
};

struct HTEntry
{
	int data;
	struct node *link;
	
};

struct HTEntry Htable[tablesize]; 

struct machine_id 
{
	char *ip_address;
	int tcpportno;
	int udpportno;
}
node[20];
