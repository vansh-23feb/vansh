#include<stdio.h>
#include<conio.h>
#define max 50
int stack[max];
int top=-1;
void push(char s)
{
  if(top==max-1)
  {
   printf("Stack overflow:stack is full");
  }
  else
  {
   top=top+1;
   stack[top]=s;
  }
 }

char pop()
{
 if(top==-1)
 {
  printf("Stack underflow:stack is empty");
  return 0;
 }
 else
 {
  return stack[top--];
 }
}

void display()
{
  int i,l;
 if(top==-1)
 {
  printf("Stack underflow");
 }
 else
 {
  printf("stack elements are\n");
  for(i=top;i>=0;i--)
  {
   printf("%c\n",stack[i]);
  }
 }
}

int main()
{
 int ch,value;
 clrscr();
 while(1)
 {
  int i,l;
  char str[max];
  printf("\n1.Push\n");
  printf("2.Pop & Reverse the string\n");
  printf("3.Display Pushed Elements\n");
  printf("4.Exit\n");
  printf("Enter your choice");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
    printf("Enter a string to push=");
    scanf("%s",str);
    l=strlen(str);
    for(i=0;i<l;i++)
      push(str[i]);
    break;
   case 2:
    for(i=0;i<l;i++)
     str[i]=pop();
    printf("%s",str);
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
