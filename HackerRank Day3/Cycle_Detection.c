#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


int hasCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          
        fast = fast->next->next;    

        if (slow == fast) {         
            return 1;
        }
    }
    return 0; 
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
  
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    // Creating a cycle for testing (4 -> 2)
    head->next->next->next->next = head->next;

 
    if (hasCycle(head)) {
        printf("Cycle detected\n");
    } else {
        printf("No cycle detected\n");
    }

    return 0;
}
