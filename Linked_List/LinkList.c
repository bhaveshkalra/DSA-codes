#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

void insertFirst(struct node **header, int d)
{
	struct node* t=(struct node *) malloc(sizeof(struct node));
	if (*header==NULL)
	{
		t->data=d;
		t->next=NULL;
	}	
	else
	{
		t->data=d;
		t->next=*header;
	}
	*header=t;	
}
void insertAfter(struct node *header, int a, int b)
{
	struct node *t=(struct node*) malloc(sizeof(struct node));
	t->data=b;
	while(header!=NULL)
	{
		if(header->data==a)
			break;
		header=header->next;
	}
	if (header!=NULL)
	{
		t->next=header->next;
		header->next=t;
	}
}
void insertBefore(struct node *header, int a, int b)
{
	struct node *t=(struct node*) malloc(sizeof(struct node));
	t->data=b;
	while(header!=NULL)
	{
		if(header->next->data==a)
			break;
		header=header->next;
	}
	if (header!=NULL)
	{
		t->next=header->next;
		header->next=t;
	}
}

void deleteNode(struct node*header, int d)
{
	while(header!=NULL)
	{
		if(header->next->data==d)
			break;
		header=header->next;
	}
	struct node *t=header->next;
	header->next=t->next;
	free(t);
}
struct node * reverse(struct node * header)
{
	struct node *t=NULL;		
	while(header!=NULL)
	{
		insertFirst(&t,header->data);
		header=header->next;
	}
	return t;
}

void printList(struct node *header)
{
	while(header!=NULL)
	{
		printf("%d ",header->data);
		header=header->next;		
	}		
	printf("\n");
}


void main()
{
	struct node* head=NULL;
	insertFirst(&head,10);
	printList(head);
	insertFirst(&head,5);
	printList(head);
	insertFirst(&head,1);
	printList(head);
	printf("inserting 7 after 5 \n");
	insertAfter(head,5,7);
	printList(head);
	insertAfter(head,10,2);
	printList(head);
	printf("inserting 4 before 5 \n");
	insertBefore(head,5,4);
	printList(head);
	printf("Deleting node 5 \n");
	deleteNode(head,5);
	printList(head);
	printf("the reverse list is \n");
	struct node *t=reverse(head);
	printList(t);
	
}	
