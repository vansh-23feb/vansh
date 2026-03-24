#include <stdio.h>
#include <ctype.h>
#define MAX 100
int stack[MAX];
int top = -1;
// Push operation
void push(int x)
{
    if (top == MAX - 1)
    {
	printf("Stack Overflow\n");
    }
    else
    {
     stack[++top] = x;
    }
}
// Pop operation
int pop()
{
    if (top == -1)
    {
	printf("Stack Underflow\n");
	return -1;
    }
    else
    {
	return stack[top--];
    }
}
// Function to evaluate postfix expression
int evaluatePostfix(char exp[])
{
    int i = 0;
    int a, b, result;
    while (exp[i] != '\0')
    {
     char ch = exp[i];
     // If operand, push to stack
     if (isdigit(ch))
     {
	push(ch - '0');  // convert char to int
     }
     // If operator
     else
     {
       b = pop();
       a = pop();
       switch (ch)
       {
	 case '+': result = a + b; break;
	 case '-': result = a - b; break;
	 case '*': result = a * b; break;
	 case '/': result = a / b; break;
	 default:
	    printf("Invalid operator\n");
	 return -1;
	}
	  push(result);
      }
	i++;
     }
     return pop();
}
int main()
{
    char exp[] = "23*54*+9-";
    int result = evaluatePostfix(exp);
    printf("Postfix Expression: %s\n", exp);
    printf("Result = %d\n", result);
    getch();
    return 0;
}

