#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

// Structure of node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* createNode(int value) {
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
    if (root == NULL) {
	return createNode(value);
    }

    // Using queue for level order insertion

    queue[rear++] = root;

    while (front < rear) {
	struct Node* temp = queue[front++];

	if (temp->left == NULL) {
	    temp->left = createNode(value);
	    return root;
	} else {
	    queue[rear++] = temp->left;
	}

	if (temp->right == NULL) {
	    temp->right = createNode(value);
	    return root;
	} else {
	    queue[rear++] = temp->right;
	}
    }
    return root;
}

// Count total nodes
int countNodes(struct Node* root) {
    if (root == NULL)
	return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Count leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL)
	return 0;

    if (root->left == NULL && root->right == NULL)
	return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Find height of tree
int height(struct Node* root)
 {
     int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (root == NULL)
	return 0;  // height in terms of edges
   // int leftHeight = height(root->left);
   // int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Inorder traversal (for display)
void inorder(struct Node* root) {
    if (root != NULL) {
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
	printf("\n--- Binary Tree (Linked List) ---\n");
	printf("1. Insert Node\n");
	printf("2. Display (Inorder)\n");
	printf("3. Count Total Nodes\n");
	printf("4. Count Leaf Nodes\n");
	printf("5. Height of Tree\n");
	printf("6. Exit\n");
	printf("Enter choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		printf("Enter value: ");
		scanf("%d", &value);
		root = insert(root, value);
		break;

	    case 2:
		printf("Inorder Traversal: ");
		inorder(root);
		printf("\n");
		break;

	    case 3:
		printf("Total Nodes: %d\n", countNodes(root));
		break;

	    case 4:
		printf("Leaf Nodes: %d\n", countLeafNodes(root));
		break;

	    case 5:
		if(root==NULL)
		{
		 printf("Tree is Empty\n");
		 }
		 else
		 {
		printf("Height of Tree: %d\n", height(root));
		}
		break;

	    case 6:
	       return 0;

	    default:
		printf("Invalid choice!\n");
	}
    }
}