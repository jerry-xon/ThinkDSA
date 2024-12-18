#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
        printf("Left Child of node %d\n ", x);
        newnode->left = create(newnode);
        printf("Right child of node %d\n ", x);
        newnode->right = create(newnode);
    }
    return newnode;
}

int findMaxDepth(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftDepth = findMaxDepth(root->left);
    int rightDepth = findMaxDepth(root->right);
    int edges = (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;

       return edges;
}

int main()
{
    struct node *root = NULL;
    root = create(root);

    int edges = findMaxDepth(root) - 1;
    printf("The number of edges in the tree is: %d\n", edges);

    return 0;
}
