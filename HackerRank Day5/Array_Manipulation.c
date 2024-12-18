#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long n, m, max = 0, x = 0;

    scanf("%lld %lld", &n, &m);

    long long *arr = (long long *)calloc(n + 2, sizeof(long long));

    // Perform operations
    for (int i = 0; i < m; i++)
    {
        long long a, b, k;
        scanf("%lld %lld %lld", &a, &b, &k);

        arr[a] += k;
        arr[b + 1] -= k;
    }

    for (int i = 1; i <= n; i++)
    {
        x += arr[i];
        if (max < x)
            max = x;
    }

    printf("%lld\n", max);

    free(arr);

    return 0;
}
