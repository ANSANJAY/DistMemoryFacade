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




