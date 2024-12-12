#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

// Push function to add an element to the stack
void Push(struct Node *top_ref, int new_data)
{

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->link = top_ref;

    top_ref = new_node;

    printf("\nPushed %d to the stack.", new_data);
}

// Pop function to remove an element from the stack
void Pop(struct Node *top_ref)
{
    // Check if stack is empty
    if (top_ref == NULL)
    {
        printf("\nStack is empty.");
        return;
    }

    struct Node *temp = top_ref;
    top_ref = top_ref->link;

    printf("\nPopped %d from the stack.", temp->data);

    free(temp);
}

// Display function to print the stack elements
void Display(struct Node *top)
{

    if (top == NULL)
    {
        printf("\nStack is empty.");
        return;
    }

    printf("\nStack elements are:\n");

    while (top != NULL)
    {
        printf("%d\n", top->data);
        top = top->link;
    }
}

int main()
{
    struct Node *top = NULL;
    int choice, value;

    do
    {
        printf("\n-------------Stack Operations-------------\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("-------------Enter your Choice-------------\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to push: ");
            scanf("%d", &value);
            Push(&top, value);
            break;
        case 2:
            Pop(&top);
            break;
        case 3:
            Display(top);
            break;
        case 4:
            printf("\nExiting...");
            break;
        default:
            printf("\nInvalid choice.");
        }
    } while (choice != 4);

    return 0;
}
