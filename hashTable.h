#include "headers.h"
#include "declarations.h"


//----------------------hash table functions-----------------

void initialiseHashtable()
// initializes the hash table. It sets the `data` field to 0 and the `link` field to NULL for each entry.

{

	int i=0;

	for(i=0;i<tablesize;i++)
	{

		Htable[i].data=0;
  		Htable[i].link=NULL;
 	}
}


void appendNode(struct node *start,int data)
// This function appends a node with a given data value at the end of a given linked list. This is used to resolve hash collisions.

{
	
	while(start->link!=NULL)
	{
		
		start=start->link;
	}
 	start->link = (struct node *)malloc(sizeof(struct node));
 	start=start->link;
 	start->link=NULL;
 	start->data = data;
}

int addToHashtable(int key,int data,int num)
// Inserts a key-value pair into the hash table.
// This function adds a key-value pair to the hash table. It has several cases to consider:
// `Key must satisfy the eqn K % N = num`: Only keys that satisfy this condition are allowed to be added to this node.
// `First Entry`: If the entry is empty, the data is added.
//`Subsequent Collisions`: If the entry already exists, it handles collisions by chaining.

{
 
	int maxlimit_key = (tablesize-1)*N+num;
	int relativeIndex,returnvalue;

	if(key % N == num && key <= maxlimit_key && key > -1)
	{
		// Key must satisfy the eqn K % N = num then only its for current node

		relativeIndex = (key - num)/N;   
		
		// case 1 : if hash table entry is empty 
		
		if(Htable[relativeIndex].data==0)
		{

     			Htable[relativeIndex].data = data;	
     			returnvalue=1;
   		}
  
		
		// case 2 : if exactly one entry in particular entry of hashtable (Ist Collision)

   		else if(Htable[relativeIndex].data!=0 && Htable[relativeIndex].link==NULL)
		{

    			Htable[relativeIndex].link = (struct node *)malloc(sizeof(struct node));
    			Htable[relativeIndex].link->data = data;
    			Htable[relativeIndex].link->link = NULL;
    			returnvalue=1;
   		}

		// case 3: Subsequent Collisions

		else
		{
     			appendNode(Htable[relativeIndex].link,data);
      			returnvalue=1;
   		}

 		printf("\nRESULT: AT KEY : %d, VALUE INSERTED : %d IN HASH TABLE SUCCESS\nENTER NEW GET/PUT REQUEST :",key,data);
 	}
	
 	else
	{
  		printf("\nERROR:KEY = %d,VALUE = %d CANNOT ADD IN TABLE, MAX KEY LIMIT = %d\nENTER NEW GET/PUT 				REQUEST :",key,data,maxlimit_key);
  		
		returnvalue=0;
 	}
 	return returnvalue;
}



int fetchValueFromHT(int key,int num)		//fun() to retrieve value corresponding to a key from hash table
{
	
	int relativeIndex = (key-num)/N,return_value;		//calculate index of key  in hash table

	if(Htable[relativeIndex].link == NULL)					//first value in the list
		return_value =  Htable[relativeIndex].data;

  	else
	{
    		struct node *start = Htable[relativeIndex].link;
     		while(start->link!=NULL)					
      			start = start->link;					// progess pointer to last element
     		return_value =  start->data;					//assign last element 
   	}   
	return return_value;
}


void displayHtable(int num)
//Displays the content of the hash table.
{

	int from_key = num,to_key = (tablesize-1)*N + num;

	if(from_key > to_key)
	{
		
		int temp = from_key;
		from_key = to_key;
		to_key = temp ;
	}

	printf("\n-----Hash Table Contents(%d--%d)------------\n",from_key,to_key);

	if(from_key % N == num && to_key % N == num)
	{

 		int i,from=(from_key - num)/N,to = (to_key - num)/N,fetchValue,key;

 		for(i=from;i<=to;i++)
		{

			key = i*N+num;
			fetchValue = fetchValueFromHT(key,num);
  			if(fetchValue !=0)
  				printf("\nkey : %d ===== value : %d\n",key,fetchValueFromHT(key,num));
 		}
	}
 	else
		printf("invalid keys , hash table cannot be displayed\n");

 	printf("-----------------------------------------------------\nENTER NEW GET/PUT REQUEST:");
}



