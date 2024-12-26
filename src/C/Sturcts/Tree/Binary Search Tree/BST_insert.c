#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

// Function to create a new node
struct node *createNode(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Function to insert a value into the BST
struct node *insert(struct node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        printf("Duplicate value not allowed: %d\n", value);
    }

    return root;
}

// Function to create the tree
struct node *create()
{
    struct node *root = NULL;
    int value;

    while (1)
    {
        printf("Enter the value of node (-1 to stop): ");
        scanf("%d", &value);

        if (value == -1)
        {
            break;
        }

        root = insert(root, value);
    }

    return root;
}

// Function to display the tree in pre-order traversal
void display(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        display(root->left);
        display(root->right);
    }
}

int main()
{
    struct node *root = NULL;

    printf("Create the binary search tree:\n");
    root = create();

    printf("Tree in pre-order traversal:\n");
    display(root);

    return 0;
}
