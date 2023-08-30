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


