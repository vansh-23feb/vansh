#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    int roll;
    char name[50];
    int marks;
    struct student *next;
};
struct student *head = NULL;

void insert()
{
    struct student *newnode, *temp;
    newnode = (struct student*)malloc(sizeof(struct student));
    printf("Enter Roll Number: ");
    scanf("%d", &newnode->roll);
    printf("Enter Name: ");
    scanf(" %[^\n]", newnode->name);
    printf("Enter Marks: ");
    scanf("%d", &newnode->marks);
    newnode->next = NULL;
    if(head == NULL)
    {
	head = newnode;
    }
    else
    {
	temp = head;
	while(temp->next != NULL)
	    temp = temp->next;
	temp->next = newnode;
    }
    printf("Record Inserted Successfully!\n");
}

void delete()
{
    int roll;
    struct student *temp = head, *prev = NULL;
    if(head == NULL)
    {
	printf("List is Empty!\n");
	return;
    }
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);
    if(temp->roll == roll)
    {
	head = temp->next;
	free(temp);
	printf("Record Deleted Successfully!\n");
	return;
    }
    while(temp != NULL && temp->roll != roll)
    {
	prev = temp;
	temp = temp->next;
    }
    if(temp == NULL)
    {
	printf("Record Not Found!\n");
	return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Record Deleted Successfully!\n");
}

void search()
{
    int roll;
    struct student *temp = head;
    if(head == NULL)
    {
	printf("List is Empty!\n");
	return;
    }
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);
    while(temp != NULL)
    {
	if(temp->roll == roll)
	{
	    printf("\nRecord Found!\n");
	    printf("Roll Number: %d\n", temp->roll);
	    printf("Name: %s\n", temp->name);
	    printf("Marks: %d\n", temp->marks);
	    return;
	}
	temp = temp->next;
    }
    printf("Record Not Found!\n");
}

void display()
{
    struct student *temp = head;
    if(head == NULL)
    {
	printf("List is Empty!\n");
	return;
    }
    printf("\nStudent Records:\n");
    printf("-----------------------------------\n");
    while(temp != NULL)
    {
	printf("Roll: %d | Name: %s | Marks: %d\n",
	       temp->roll, temp->name, temp->marks);
	temp = temp->next;
    }
    printf("-----------------------------------\n");
}

int main()
{
    int choice;
    while(choice!=5)
    {
	printf("\n--- Student Record Management ---\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Search\n");
	printf("4. Display\n");
	printf("5. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	switch(choice)
	{
	    case 1: insert(); break;
	    case 2: delete(); break;
	    case 3: search(); break;
	    case 4: display(); break;
	    case 5: exit(0);
	    default: printf("Invalid Choice!\n");
	}
    }
    getch();
    return 0;
}
