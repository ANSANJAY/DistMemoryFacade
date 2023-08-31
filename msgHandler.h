#include "headers.h"
#include "declarations.h"

int forYou(int num,char request[])		//check whether request is for current node or not
{
	
	int k;
	if(getOrPut(request)==1)				//check whether request is get or put

		k = extractKeyFromGet(request);			
 	else
 		k=extractKeyFromPut(request);		

 	if((k % N) == num)			

 		return 1;					//return 1 if for current node
 	else
 		return 0;					//return 0 if not for current node
}


// ----------------------- String handling functions---------------------------------


int extractKeyFromPut(char request[])		//method for extracting key from put request.
{	
	
	char *b = strstr(request, "("),*c = strstr(request, ",");
	int position = b - request,position1 = c - request,k;
	char to[4];
	strncpy(to, request + position+1, position1 - position);   //for extracting the first integer no. k of put(k,x)
 
	k = atoi(to);		//converting to int
	fflush(stdout);
	return k;
}

int extractKeyFromGet(char request[])		//method for extracting key from get request.
{	

	char *b = strstr(request, "("),*c = strstr(request, ")");
	int position = b - request,position1 = c - request,k;
	char to[4];
	strncpy(to, request + position+1, position1 - position);   //for extracting the first integer no. k of put(k,x) 
	k = atoi(to);
	fflush(stdout);
	return k;
}


int extractValueFromPut(char request[])
{

	char *b = strstr(request, ","),*c = strstr(request, ")");
	int position = b - request,position1 = c - request,k;
	char to[16];
	memset(to, 0 , 16);
	strncpy(to, request + position+1, position1 - position);   //for extracting the first integer no. k of put(k,x) 
	k = atoi(to);
	return k;
}

char *forwardedData(char inputbuff[],char flag,int num)			//Called to prepare data to be forwaded to next node
{
	
	int key,tcpportno;
	char keybuff[5],portbuff[5],fl[2];
	fl[0]=flag;
	fl[1]='\0';
	char *outputbuff=(char *)malloc(sizeof(char)*40),nodebuff[3];

 	if(getOrPut(inputbuff)==1)
  		key = extractKeyFromGet(inputbuff);		//extract key from data get before preparing sending data
 	else
		key = extractKeyFromPut(inputbuff);		//extract key from data get before preparing sending data

	tcpportno=node[num].tcpportno;		

	itoa(tcpportno,portbuff);					//convert integer port number to character array

	itoa(key,keybuff);						//convert integer key to character array

	strcpy(outputbuff,"xxx(");   					//start forwarding data with xxx( 

	strcat(outputbuff,keybuff);					

	strcat(outputbuff,",");						

	strcat(outputbuff,portbuff);					

	strcat(outputbuff,")");   					

	itoa(num,nodebuff);				//convert integer node number to character array

	strcat(outputbuff,nodebuff);					 

	strcat(outputbuff,"[");						

	strcat(outputbuff,node[num].ip_address);	

	strcat(outputbuff,",");						

	strcat(outputbuff,fl);						

	strcat(outputbuff,"]");						

	outputbuff[strlen(outputbuff)+1] = '\0';			//end 

	return outputbuff;					//return the address of data in memory which is to be forwaded
}

