#include <stdio.h>
#include <math.h>

int squares(int a, int b)
{

    int start = ceil(sqrt(a));
    int end = floor(sqrt(b));

    if (start > end)
    {
        return 0;
    }
    return end - start + 1;
}

int main()
{
    int q, a, b;

    scanf("%d", &q);

    for (int i = 0; i < q; i++)
    {

        scanf("%d %d", &a, &b);

        int count = squares(a, b);
        printf("%d\n", count);
    }

    return 0;
}
