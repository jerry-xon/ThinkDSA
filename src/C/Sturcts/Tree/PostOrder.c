#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create(struct node *root)
{
    int x;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value of node (-1 for no node): ");
    scanf("%d", &x);
    if (x == -1)
    {
        return NULL;
    }
    else
    {
        newnode->data = x;
        printf("Left Child of node %d\n", x);
        newnode->left = create(newnode);
        printf("Right child of node %d\n", x);
        newnode->right = create(newnode);
    }
    return newnode;
}

void Postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    struct node *root = NULL;
    root = create(root);

    printf("Tree in pre-order traversal:\n");
    Postorder(root);

    return 0;
}
