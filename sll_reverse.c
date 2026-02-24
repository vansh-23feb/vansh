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
void reverse()
{
 struct node *prev=NULL;
 struct node *curr=head;
 struct node *temp;
 while(curr!=NULL)
  {
   temp=curr->next;
   curr->next=prev;
   prev=curr;
   curr=temp;
  }
  head=prev;
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
 reverse();
 printf("Reversed Link List\n");
  display();
 getch();
 return 0;
}
