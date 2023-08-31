#include "headers.h"
#include "declarations.h"
//Converts an integer to a string.


void itoa(int n,char buff[])
{
	int i =0,j;

	if(n==0)
	{
		
		buff[0] = '0';
		buff[1] = '\0';
  		i=1;
 	}

 	while(n>0)
	{
		  		
		int rem = n %10;
  		n=n/10;
  		buff[i]=rem+48;			
		i++;
	} 

	buff[i]='\0';

	for(j=0;j<i/2;j++)
	{

 		char temp = buff[j];
 		buff[j] = buff[i-j-1];
 		buff[i-j-1] = temp;
		
	}

}




char *extractIpaddress(char *buff,char a,char b)
{
	
	char *ptr = (char *)malloc(20);
	int i=0,j=0;

	while(buff[i]!=a)
	{
		i++;
	}
 	i=i+1;

  	while(buff[i]!=b)
	{
    		
		ptr[j++]=buff[i];
    		i++;
  	}
 	ptr[j]='\0';
 	return ptr;
}


int extractNodeno(char * buff)
{

	char *nodeno=extractIpaddress(buff,')','[');
 	return atoi(nodeno);
}

/***
This function decides if a request is a GET request or a PUT request.

- **Parameters**:
  - `rec_buff[]`: The received buffer which contains either 'GET' or 'PUT'.

- **Operations**:
  - Checks if the first character in `rec_buff` is 'g' or 'G' (for a GET request).
  - Returns 1 for GET requests and 0 otherwise.

	Code Explanation:

- `if(rec_buff[0] == 'g' || rec_buff[0] == 'G') return 1; else return 0;`: Checks the first character to identify if it's a GET request (returns 1) or PUT request (returns 0).

***/



int getOrPut(char rec_buff[])			//method to check  whether put or get request.
{

	if(rec_buff[0] == 'g' || rec_buff[0] == 'G')
  		return 1;
	else
  		return 0;
}