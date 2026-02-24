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
printf("After inserting node at %d position\n",pos);
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
 int pos;
 clrscr();
 insertfirst(40);
 display();
 printf("Node inserted at the beginning\n");
 insertlast(30);
 display();
 printf("Node inserted at the last\n");
 insertbetween(20,2);
 display();
 getch();
 return 0;
}
