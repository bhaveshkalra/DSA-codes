#include<stdio.h>
#include<stdlib.h>


struct node {
	int data;
	struct node* next;
	struct node* prev;
}

void insertFirst(struct node **header,struct node **tail, int d)
{
	struct node* t=(struct node*)malloc(sizeof(struct node));
	t->data=d;
	if (*header==NULL)
	{
		t->next=NULL;
		t->prev=NULL;
		*tail=t;
	}
	else
	{
		t->next=*header;
		t->prev=NULL;
		*header->prev=t;
	}
	*header=t;
}
void deleteNode(struct node* header, int d)
{
	while(header!=NULL)
	{
		if (header->data==d)
			break;
		header=header->next;
	}
	if (header!=NULL)
	{
		struct node* t=header;
		t->prev->next=t->next;
		t->next->prev=t->prev;
		free(t);
	}
}
void main()
{
	struct node* head=NULL;
	struct node* tail=NULL;
	insertFirst(&head,&tail,10)
	insertFirst(&head,&tail,15)
	insertFirst(&head,&tail,25)
	deleteNode(head,15);
	
}
