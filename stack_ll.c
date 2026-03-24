#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *top=NULL;
void push(int value)
{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
if(newnode==NULL)
{
 printf("stack is overflow");
 return;
}
newnode->data=value;
newnode->next=top;
top=newnode;
}
void pop()
{
 struct node *temp=top;
 if(top==NULL)
 {
   printf("stack is underflow");
   return;
 }
 top=top->next;
 free(temp);
}
void display()
{
struct node *temp=top;
while(temp!=NULL)
{
 printf("%d\t",temp->data);
 temp=temp->next;
}
}

int main()
{
 int ch,value;
 clrscr();
 while(1)
 {
  printf("\n1.Push\n");
  printf("2.Pop\n");
  printf("3.Display\n");
  printf("4.Exit\n");
  printf("Enter your choice");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
    printf("Enter value to push");
    scanf("%d",&value);
    push(value);
    break;
   case 2:
    pop();
    break;
   case 3:
    display();
    break;
   case 4:
    return 0;
   default:
    printf("Invalid choice\n");
  }
 }
}
