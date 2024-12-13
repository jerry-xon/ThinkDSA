#include <stdio.h>

void kangaroo(int K1, int v1, int K2, int v2)
{
    if (v1 == v2) 
    {
    
        if (K1 == K2)
            printf("YES\n");
        else
            printf("NO\n");
    }
    else 
    {
        
        if ((K2 - K1) % (v1 - v2) == 0 && (K2 - K1) / (v1 - v2) > 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
}

int main()
{
    int K1, K2;
    int v1, v2;

    
    scanf("%d %d %d %d", &K1, &v1, &K2, &v2);

    kangaroo(K1, v1, K2, v2);

    return 0;
}
