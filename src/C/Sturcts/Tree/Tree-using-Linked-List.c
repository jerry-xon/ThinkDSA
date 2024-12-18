#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *create(struct node *root) {
    int x;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value of node (-1 for no node): ");
    scanf("%d", &x);
    if (x == -1) {
        return NULL;
    } else {
        newnode->data = x;
        printf("Enter the left child of node %d: ", x);
        newnode->left = create(newnode); 
        printf("Enter the right child of node %d: ", x);
        newnode->right = create(newnode); 
    }
    return newnode;
}

void display(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data); 
        display(root->left); 
        display(root->right); 
    }
}

int main() {
    struct node *root = NULL;
    root = create(root);
    
    printf("Tree in pre-order traversal:\n");
    display(root);
    
    return 0;
}
