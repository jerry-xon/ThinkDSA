#include <stdio.h>
#include <stdlib.h>

void CatandMouse(int n)
{
    int x, y, z;
    for (int i = 0; i < n; i++)
    {

        scanf("%d %d %d", &x, &y, &z);

        int disA = abs(z - x);
        int disB = abs(z - y);

        if (disA < disB)
        {
            printf("Cat A\n");
        }
        else if (disB < disA)
        {
            printf("Cat B\n");
        }
        else
        {
            printf("Mouse C\n");
        }
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    CatandMouse(n);

    return 0;
}
