#include <stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    int b;
    scanf("%d", &b);
    for (int j = 0; j < a; j++)
    {

        for (int i = 1; i <= b; i++)
        {
            if (i % 2 == 0)
            {
                printf("%d\n", i);
            }
        }
        break;
    }

    return 0;
}