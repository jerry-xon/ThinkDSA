#include <stdio.h>
#include <stdlib.h>

#define MAX 10 


void insert(int tree[], int key, int index) {
    if (index >= MAX) {
        printf("Tree is full, cannot insert %d\n", key);
        return;
    }
    if (tree[index] != -1) {
        printf("Node already exists at index %d!\n", index);
        return;
    }
    tree[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}


void deleteNode(int tree[], int index) {
    if (index >= MAX || tree[index] == -1) {
        printf("No node exists at index %d!\n", index);
        return;
    }
    printf("Deleted node with value %d from index %d\n", tree[index], index);
    tree[index] = -1;
}


void display(int tree[], int size) {
    printf("Tree represented in array form:\n");
    for (int i = 0; i < size; i++) {
        if (tree[i] != -1)
            printf("%d ", tree[i]);
        else
            printf("_ "); 
    }
    printf("\n");
}


int main() {
    int tree[MAX];
  
    for (int i = 0; i < MAX; i++) {
        tree[i] = -1;
    }

    int choice, value, index;

    while (1) {
      
        printf("\nMenu:\n");
        printf("1. Add new node\n");
        printf("2. Delete a node\n");
        printf("3. Display the tree\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter index to insert the value (starting from 0): ");
                scanf("%d", &index);
                insert(tree, value, index);
                break;

            case 2:  
                printf("Enter index of the node to delete: ");
                scanf("%d", &index);
                deleteNode(tree, index);
                break;

            case 3: 
                printf("Enter number of elements to display (up to %d): ",MAX);
                scanf("%d", &index);  
                display(tree, index);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
