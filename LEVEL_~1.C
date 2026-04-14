#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
// Function to create a new node
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// Queue structure
struct Queue
{
    int front, rear, size;
    unsigned capacity;
    struct Node** array;
};
// Create a queue
struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (struct Node**)malloc(capacity * sizeof(struct Node*));
    return queue;
}
// Check if queue is empty
int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}
// Enqueue operation
void enqueue(struct Queue* queue, struct Node* item)
{
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}
// Dequeue operation
struct Node* dequeue(struct Queue* queue)
{
  struct Node* item = queue->array[queue->front];
  queue->front = (queue->front + 1) % queue->capacity;
  queue->size--;
  return item;
}
// Function for Level Order Traversal
void levelOrderTraversal(struct Node* root)
{
  struct Queue* queue = createQueue(100);
  if (root == NULL)
  return;
  enqueue(queue, root);
  while (!isEmpty(queue))
  {
   struct Node* temp = dequeue(queue);
   printf("%d ", temp->data);
   if (temp->left != NULL)
      enqueue(queue, temp->left);
   if (temp->right != NULL)
      enqueue(queue, temp->right);
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
    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    getch();
    return 0;
}