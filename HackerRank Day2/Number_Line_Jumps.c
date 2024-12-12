#include <stdio.h>
void kangaro(int K1, int v1, int K2, int v2)
{
    int l2 = K2;
    int l1 = K1;

    do
    {
        l1 += v1;
        l2 += v2;

    } while (l1 != l2);

    if (K2 > K1 && v2 > v1)
    {
        printf("NO");
    }
    else if (l1 == l2)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}

int main()
{
    int K1, K2;
    int v1, v2;

    scanf("%d %d %d %d", &K1, &v1, &K2, &v2);

    kangaro(K1, v1, K2, v2);

    return 0;
}