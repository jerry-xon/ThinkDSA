#include <stdio.h>
#define MAX_SIZE 1000
int Stack[MAX_SIZE], top = -1;


void check(){
    int ptr;
}
void Push()
{
    if (top == MAX_SIZE - 1)
    {
        printf("\nStack overflow.");
    }
    else
    {
        int n;
        printf("Enter the element to push: ");
        scanf("%d", &n);
        top++;
        Stack[top] = n;
    }
}

void Pop()
{
    if (top == -1)
    {
        printf("\nStack is empty.\n\n\n");
    }
    else
    {
        printf("\nElement popped is: %d", Stack[top]);
        top--;
    }
}

void Display()
{
    if (top == -1)
    {
        printf("\nStack is empty.");
    }
    else
    {
        printf("\nStack elements are:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", Stack[i]);
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    char str[1000];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
    }

    return 0;
}