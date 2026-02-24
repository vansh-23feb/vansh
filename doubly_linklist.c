#include<stdio.h>
#include<conio.h>
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
struct node *newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=value;
newnode->prev=NULL;
newnode->next=head;
if(head!=NULL)
     head->prev=newnode;
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
 newnode->prev=NULL;
 head=newnode;
 return;
}
while(temp->next!=NULL)
  temp=temp->next;
temp->next=newnode;
newnode->prev=temp;
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
newnode->prev=temp;
temp->next->prev=newnode;
temp->next=newnode;
printf("Forward display :: After inserting node at %d position\n",pos);
}

void count()
{
 int c=0;
 struct node *temp=head;
 while(temp!=NULL)
 {
  c=c+1;
  temp=temp->next;
 }
printf("No. of nodes in Doubly link list=%d",c);
}

void deletefirst()
{
 struct node *temp=head;
 head=head->next;
 head->prev=NULL;
 free(temp);
}

void deletelast()
{
struct node *temp=head;
while(temp->next!=NULL)
{
 temp=temp->next;
}
temp->prev->next=NULL;
free(temp);
}

void deletebetween(int pos)
{
int i;
struct node *temp=head;
for(i=1;i<pos;i++)
{
 temp=temp->next;
}
if(temp->prev!=NULL)
   temp->prev->next=temp->next;
if(temp->next!=NULL)
   temp->next->prev=temp->next;
free(temp);
printf("List after deleting node at %d position\n",pos);

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
void backward_display()
{
struct node *temp=head;
while(temp->next!=NULL)
    temp=temp->next;
while(temp!=NULL)
{
 printf("%d\t",temp->data);
 temp=temp->prev;
}
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
 insertbetween(20,2);
 display();
 count();
 printf("\nBackward display of Nodes\n");
 backward_display();
 deletefirst();
 printf("List after deletiing first node\n");
 display();
 deletelast();
 printf("List after deletiing last node\n");
 display();
 deletebetween(2);
 display();
 getch();
 return 0;
}
