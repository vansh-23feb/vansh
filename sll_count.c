#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};

struct node *head=NULL;

void insert(int value)
{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=value;
newnode->next=head;
head=newnode;
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
printf("No. of nodes in singly link list=%d",c);
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
 insert(40);
 insert(30);
 insert(20);
 insert(10);
 display();
 printf("Nodes Inserted Successfully\n");
 count();
 getch();
 return 0;
}
