#include <stdio.h>
#include <stdlib.h>
// Structure of a node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
// Create new node
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// Stack structure
struct Stack
{
   int top;
   unsigned capacity;
   struct Node** array;
};
// Create stack
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (struct Node**)malloc(capacity * sizeof(struct Node*));
    return stack;
}
// Check if stack is empty
int isEmpty(struct Stack* stack)
{
    return (stack->top == -1);
}
// Push operation
void push(struct Stack* stack, struct Node* node)
{
    stack->array[++stack->top] = node;
}
// Pop operation
struct Node* pop(struct Stack* stack)
{
    if (isEmpty(stack))
	return NULL;
    return stack->array[stack->top--];
}
// ================= INORDER (Non-Recursive) =================
void inorder(struct Node* root)
{
    struct Stack* stack = createStack(100);
    struct Node* curr = root;
    while (curr != NULL || !isEmpty(stack))
    {
	// Reach leftmost node
	while (curr != NULL)
	{
	    push(stack, curr);
	    curr = curr->left;
	}
	curr = pop(stack);
	printf("%d ", curr->data);
	curr = curr->right;
    }
}
// ================= PREORDER (Non-Recursive) =================
void preorder(struct Node* root)
{
    struct Stack* stack = createStack(100);
    if (root == NULL)
	return;
    push(stack, root);
    while (!isEmpty(stack))
    {
	struct Node* curr = pop(stack);
	printf("%d ", curr->data);
	// Push right first so left is processed first
	if (curr->right != NULL)
	    push(stack, curr->right);
	if (curr->left != NULL)
	    push(stack, curr->left);
    }
}
// Main function
int main()
{
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    getch();
    return 0;
}