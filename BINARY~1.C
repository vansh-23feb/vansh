#include <stdio.h>
#define SIZE 100
int tree[SIZE];
int n = 0; // number of elements

// Insert element
void insert(int value)
{
    if (n < SIZE)
     {
	tree[n] = value;
	n++;
     }
     else
     {
	printf("Tree is full!\n");
     }
}
// Display elements
void display()
{
  int i;
  if (n == 0)
  {
   printf("Tree is empty!\n");
   return;
  }
  printf("Tree elements are:\n");
  for (i = 0; i < n; i++)
  {
   printf("%d ", tree[i]);
  }
  printf("\n");
}
// Find parent, left child, right child
void findRelations(int value)
{
  int i, found = -1;
  for (i = 0; i < n; i++)
  {
   if (tree[i] == value)
   {
    found = i;
    break;
   }
  }
  if (found == -1)
  {
   printf("Node not found!\n");
   return;
  }
 // Parent
if (found == 0)
 {
   printf("Parent: No parent (root node)\n");
 }
 else
 {
   printf("Parent: %d\n", tree[(found - 1) / 2]);
 }
 // Left Child
    if (2 * found + 1 < n)
    {
     printf("Left Child: %d\n", tree[2 * found + 1]);
    }
    else
    {
     printf("Left Child: Not exist\n");
    }
 // Right Child
    if (2 * found + 2 < n)
    {
	printf("Right Child: %d\n", tree[2 * found + 2]);
    }
    else
    {
     printf("Right Child: Not exist\n");
    }
}
int main()
{
  int choice, value;
  while (1)
  {
    printf("\n--- Binary Tree using Array ---\n");
    printf("1. Insert\n");
    printf("2. Display\n");
    printf("3. Find Parent/Children\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
      case 1:
	 printf("Enter value to insert: ");
	 scanf("%d", &value);
	 insert(value);
	 break;
      case 2:
	 display();
	 break;
      case 3:
	 printf("Enter node value: ");
	 scanf("%d", &value);
	 findRelations(value);
	 break;
      case 4:
	 return 0;
      default:
	 printf("Invalid choice!\n");
    }
  }
}