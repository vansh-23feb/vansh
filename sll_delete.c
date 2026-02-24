#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *head=NULL;

void insertfirst(int value)
{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=value;
newnode->next=head;
head=newnode;
}

void insertlast(int value)
{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
struct node *temp=head;
newnode->data=value;
newnode->next=NULL;
if(head==NULL)
{
 head=newnode;
 return;
}
while(temp->next!=NULL)
  temp=temp->next;
temp->next=newnode;
}

void insertbetween(int value,int pos)
{
int i;
struct node *newnode=(struct node*)malloc(sizeof(struct node));
struct node *temp=head;
newnode->data=value;
for(i=1;i<pos-1;i++)
{
  temp=temp->next;
}
newnode->next=temp->next;
temp->next=newnode;
}

void deletefirst()
{
 struct node *temp=head;
 head=head->next;
 free(temp);
}

void deletelast()
{
struct node *temp=head;
struct node *prev;
while(temp->next!=NULL)
{
 prev=temp;
 temp=temp->next;
}
prev->next=NULL;
free(temp);
}

void deletebetween(int pos)
{
int i;
struct node *temp=head;
struct node *prev;
for(i=1;i<pos;i++)
{
 prev=temp;
 temp=temp->next;
}
prev->next=temp->next;
free(temp);
}

void display()
{
struct node *temp=head;
while(temp!=NULL)
{
 printf("%d\t",temp->data);
 temp=temp->next;
}
printf("NULL\n");
}
int main()
{
 clrscr();
 insertfirst(40);
 insertlast(30);
 insertbetween(20,2);
 insertlast(50);
 insertlast(60);
 display();
 printf("Nodes Inserted Successfully\n");
 deletefirst();
 printf("List after deletiing first node\n");
 display();
 deletelast();
 printf("List after deletiing last node\n");
 display();
 deletebetween(2);
  printf("List after deleting node at desired position\n");
 display();
 getch();
 return 0;
}
