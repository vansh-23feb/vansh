#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct Node
{
    int data;
    struct Node *left, *right;
};
// Create a new node
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// Insert node (level order)
struct Node* insert(struct Node* root, int value)
{
  struct Node* queue[100];
  int front = 0, rear = 0;
  if (root == NULL)
    return createNode(value);
    queue[rear++] = root;
    while (front < rear)
    {
      struct Node* temp = queue[front++];
      if (temp->left == NULL)
      {
	temp->left = createNode(value);
	return root;
      }
      else
      {
       queue[rear++] = temp->left;
      }
      if (temp->right == NULL)
      {
	temp->right = createNode(value);
	return root;
      }
      else
      {
	queue[rear++] = temp->right;
      }
    }
    return root;
}
// (i) Inorder Traversal (L ? Root ? R)
void inorder(struct Node* root)
{
  if (root != NULL)
  {
   inorder(root->left);
   printf("%d ", root->data);
   inorder(root->right);
  }
}
// (ii) Preorder Traversal (Root ? L ? R)
void preorder(struct Node* root)
{
 if(root != NULL)
 {
  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
 }
}
// (iii) Postorder Traversal (L ? R ? Root)
void postorder(struct Node* root)
{
  if (root != NULL)
  {
   postorder(root->left);
   postorder(root->right);
   printf("%d ", root->data);
  }
}
// Main function
int main()
{
  struct Node* root = NULL;
 // Sample input
  clrscr();
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  printf("Inorder Traversal: ");
  inorder(root);
  printf("\nPreorder Traversal: ");
  preorder(root);
  printf("\nPostorder Traversal: ");
  postorder(root);
  getch();
  return 0;
}