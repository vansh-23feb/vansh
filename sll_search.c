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
void search()
{
 int s,pos=1;
 int found=0;
 struct node *temp=head;
 printf("Enter the node to be search=");
 scanf("%d",&s);
 while(temp!=NULL)
 {
  if(temp->data==s)
  {
    found=1;
    break;
  }
   temp=temp->next;
   pos=pos+1;
 }
  if(found==1)
   printf("Node is present at position = %d",pos);
  else
   printf("Node does not exist");
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
 search();
 getch();
 return 0;
}
