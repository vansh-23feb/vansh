#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head, *temp, *slow, *fast;
    
    // Creating nodes
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;

    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 20;

    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 30;

    head->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->data = 40;

    head->next->next->next->next = NULL;

    // Creating a cycle
    head->next->next->next->next = head->next;

    slow = head;
    fast = head;

    // Detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            printf("Cycle detected in the linked list.\n");
            return 0;
        }
    }

    printf("No cycle in the linked list.\n");

    return 0;
}