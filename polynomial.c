#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    int coeff;
    int exp;
    struct node *next;
};
int main()
{
    struct node *head = NULL, *temp = NULL, *newnode = NULL;
    int n, i;
    float x, sum = 0;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter coefficient: ");
	scanf("%d", &newnode->coeff);
	printf("Enter exponent: ");
	scanf("%d", &newnode->exp);
	newnode->next = NULL;
	if(head == NULL)
	{
	    head = newnode;
	    temp = newnode;
	}
	else
	{
	    temp->next = newnode;
	    temp = newnode;
	}
    }
    printf("\nPolynomial is: ");
    temp = head;
    while(temp != NULL)
    {
	printf("%dx^%d", temp->coeff, temp->exp);
	if(temp->next != NULL)
	    printf(" + ");
	temp = temp->next;
    }
    printf("\n\nEnter value of x: ");
    scanf("%f", &x);
    temp = head;
    while(temp != NULL)
    {
	sum += temp->coeff * pow(x, temp->exp);
	temp = temp->next;
    }
    printf("\nValue of polynomial at x = %.2f is %.2f\n", x, sum);
    getch();
    return 0;
}
