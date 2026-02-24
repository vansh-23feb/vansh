#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void insertfirst(int value)
{
    struct node *newnode = malloc(sizeof(struct node));
    struct node *temp = head;
    newnode->data = value;
    if (head == NULL)
    {
	newnode->next = newnode;  // points to itself
	head = newnode;
	return;
    }
     while (temp->next != head)
	temp = temp->next;
    newnode->next = head;
    temp->next = newnode;
    head = newnode;
}

void insertlast(int value)
{
    struct node *newnode = malloc(sizeof(struct node));
    struct node *temp = head;
    newnode->data = value;
    if (head == NULL)
    {
	newnode->next = newnode;
	head = newnode;
	return;
    }
     while (temp->next != head)
	temp = temp->next;
    temp->next = newnode;
    newnode->next = head;
}

void deletefirst()
{
    struct node *temp = head;
    struct node *del=head;
    if (head == NULL)
	return;
    if (head->next == head)
    {
	free(head);
	head = NULL;
	return;
    }
    while (temp->next != head)
	temp = temp->next;
    head = head->next;
    temp->next = head;
    free(del);
}

void deletelast()
{
    struct node *temp = head;
     struct node *prev;
    if (head == NULL)
	return;
    if (head->next == head)
    {
	free(head);
	head = NULL;
	return;
    }
    while (temp->next != head)
    {
	prev = temp;
	temp = temp->next;
    }
    prev->next = head;
    free(temp);
}
void count()
{
 int c=1;
 struct node *temp=head;
 temp=head->next;
 while(temp!=head)
 {
  c=c+1;
  temp=temp->next;
 }
printf("No. of nodes in Circular singly link list=%d\n",c);
}

void display()
{
    struct node *temp = head;
    if (head == NULL)
    {
	printf("List is empty\n");
	return;
    }
    do
    {
	printf("%d ", temp->data);
	temp = temp->next;
    } while (temp != head);
    printf("NULL\n");
}

int main()
{
 clrscr();
 insertfirst(40);
 display();
 printf("Node inserted at the beginning\n");
 insertfirst(50);
 display();
 printf("Node inserted at the beginning\n");
 insertlast(30);
 display();
 printf("Node inserted at the last\n");
 count();
 deletefirst();
 printf("List after deletiing first node\n");
 display();
 deletelast();
 printf("List after deletiing last node\n");
 display();
 getch();
 return 0;
}
