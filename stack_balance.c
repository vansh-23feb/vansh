#include <stdio.h>
#include <string.h>
#define MAX 100
// Stack structure
char stack[MAX];
int top = -1;
// Push operation
void push(char c)
{
    if (top == MAX - 1)
     {
	printf("Stack Overflow\n");
     }
     else
      {
	stack[++top] = c;
     }
}

// Pop operation
char pop()
{
    if (top == -1)
    {
	return '\0';
    }
     else
    {
	return stack[top--];
    }
}
// Function to check matching pairs
int isMatchingPair(char open, char close)
{
    if (open == '(' && close == ')')
     return 1;
    if (open == '{' && close == '}')
     return 1;
    if (open == '[' && close == ']')
     return 1;
    return 0;
}
// Function to check balanced expression
int isBalanced(char expr[])
 { 
    int i;
    for (i = 0; i < strlen(expr); i++)
    {
	char ch = expr[i];
	// If opening bracket, push to stack
	if (ch == '(' || ch == '{' || ch == '[')
	 {
	    push(ch);
	 }
	// If closing bracket
	else if (ch == ')' || ch == '}' || ch == ']')
	 {
	    char popped = pop();
	    if (popped == '\0' || !isMatchingPair(popped, ch))
	     {
		return 0; // Not balanced
	     }
	}
    }
    return (top == -1); // Balanced if stack is empty
}
int main()
 {
    char expr[MAX];
    printf("Enter an expression: ");
    scanf("%s", expr);
    if (isBalanced(expr))
    {
	printf("Balanced Expression\n");
    }
    else
    {
	printf("Not Balanced Expression\n");
    }
     getch();
     return 0;
}
