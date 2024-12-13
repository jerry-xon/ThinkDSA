#include <stdio.h>
int sockMerchant(int n, int sock[n])
{
    int pair[200] = {0};

    for (int i = 0; i < n; i++)
    {
        pair[sock[i]]++;
    }
    int count = 0;
    for (int i = 1; i < 200; i++)
    {
        count += pair[i] / 2;
    }

    return count;
}
int main()
{
    int n;
    scanf("%d", &n);
    int sock[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &sock[i]);
    }
    int pairs = sockMerchant(n, sock);
    printf("%d", pairs);
    return 0;
}