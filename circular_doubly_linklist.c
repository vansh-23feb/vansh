#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL;
void insertfirst(int value)
{
    struct node *last=head->prev;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    if(head==NULL)
    {
	newnode->next=newnode;
	newnode->prev=newnode;
	head=newnode;
	return;
    }
    newnode->next=head;
    newnode->prev=last;
    last->next=newnode;
    head->prev=newnode;
    head=newnode;
}

void insertlast(int value)
{
    struct node *last=head->prev;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    if(head==NULL)
    {
	newnode->next=newnode;
	newnode->prev=newnode;
	head=newnode;
	return;
    }
    newnode->next=head;
    newnode->prev=last;
    last->next=newnode;
    head->prev=newnode;
}

void deletefirst()
{
    struct node *last=head->prev;
    struct node *temp=head;
    if(head==NULL)
	return;
    if(head->next==head)
    {
	free(head);
	head=NULL;
	return;
    }
    head=head->next;
    head->prev=last;
    last->next=head;
    free(temp);
}
void deletelast()
{
    struct node *last=head->prev;
    struct node *newlast=last->prev;
    if(head==NULL)
	return;
    if(head->next==head)
    {
	free(head);
	head=NULL;
	return;
    }
    newlast->next=head;
    head->prev=newlast;
    free(last);
}

void count()
{
 int c=1;
 struct node *temp=head;
 temp=head->next;
 while(temp!=head)
 {
  c=c+1;
  temp=temp->next;
 }
printf("No. of nodes in Doubly circular link list=%d\n",c);
}

void display()
{
    struct node *temp=head;
    if (head == NULL)
    {
	printf("List is empty\n");
	return;
    }
    do
    {
	printf("%d\t",temp->data);
	temp=temp->next;
    }
    while(temp!=head);
    printf("NULL\n");
}

int main()
{
 clrscr();
 insertfirst(30);
 display();
 printf("Node inserted at the beginning\n");
 insertfirst(40);
 display();
 printf("Node inserted at the beginning\n");
 insertlast(20);
 display();
 printf("Node inserted at the last\n");
 count();
 deletefirst();
 printf("List after deletiing first node\n");
 display();
 deletelast();
 printf("List after deletiing last node\n");
 display();
 getch();
 return 0;
}
