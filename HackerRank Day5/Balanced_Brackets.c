#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ismatchingpair(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int isbalanced(char *str)
{
    int len = strlen(str);

    char *stack = (char *)malloc(len * sizeof(char));
    int top = -1;

    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            stack[++top] = str[i];
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (top == -1 || !ismatchingpair(stack[top], str[i]))
            {
                free(stack);
                return 0;
            }
            top--;
        }
    }
    int balanced = (top == -1);
    free(stack);
    return balanced;
}

int main()
{
    int n;
    scanf("%d", &n);

    while (n != 0)
    {
        n--;
        char str[1001];
        scanf("%s", str);

        if (isbalanced(str))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}