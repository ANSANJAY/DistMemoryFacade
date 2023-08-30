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