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



char *forwardedData(char inputbuff[],char flag)			//Called to prepare data to be forwaded to next node
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

int getOrPut(char rec_buff[])			//method to check  whether put or get request.
{

	if(rec_buff[0] == 'g' || rec_buff[0] == 'G')
  		return 1;
	else
  		return 0;
}