#include<stdio.h>
#include<conio.h>
#define max 5
int stack[max];
int top=-1;
void push(int value)
{
  if(top==max-1)
  {
   printf("Stack overflow:stack is full");
  }
  else
  {
   top=top+1;
   stack[top]=value;
  }
 }
void pop()
{
 if(top==-1)
 {
  printf("Stack underflow:stack is empty");
 }
 else
 {
  top=top-1;
 }
}
void display()
{
  int i;
 if(top==-1)
 {
  printf("Stack underflow");
 }
 else
 {
  printf("stack elements are\n");
  for(i=top;i>=0;i--)
  {
   printf("%d\n",stack[i]);
  }
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