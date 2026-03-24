#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
// Push operation
void push(char x)
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
// Peek top element
char peek()
{
    if (top == -1)
	return '\0';
    return stack[top];
}

// Operator precedence
int precedence(char op)
{
    if (op == '^')
     return 3;
    if (op == '*' || op == '/')
     return 2;
    if (op == '+' || op == '-')
     return 1;
    return 0;
}

// Check if operator is right associative
int isRightAssociative(char op)
{
    return (op == '^');
}
// Infix to Postfix conversion
void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char ch;
    for (i = 0; infix[i] != '\0'; i++)
     {
	ch = infix[i];
	// If operand, add to postfix
	if (isalnum(ch))
	{
	    postfix[j++] = ch;
	}
	// If opening bracket
	else if (ch == '(')
	{
	    push(ch);
	}
	// If closing bracket
	else if (ch == ')')
	{
	  while (peek() != '(')
	  {
	   postfix[j++] = pop();
	  }
	    pop(); // remove '('
	}
	// If operator
	else
	{
	  while (top != -1 &&
		   ((precedence(peek()) > precedence(ch)) ||
		   (precedence(peek()) == precedence(ch) && !isRightAssociative(ch))))
		   {
		    postfix[j++] = pop();
		   }
   push(ch);
	}
    }
// Pop remaining operators
   while (top != -1)
   {
    postfix[j++] = pop();
   }
   postfix[j] = '\0';
}
int main()
{
    char infix[MAX] = "A+B*(C^D-E)^(F+G*H)-I";
    char postfix[MAX];
    infixToPostfix(infix, postfix);
    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);
    getch();
    return 0;
}
            
