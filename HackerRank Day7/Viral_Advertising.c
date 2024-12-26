#include <stdio.h>

int viralAdvertising(int n)
{
    int shared = 5, liked = 0, cum = 0;

    for (int i = 1; i <= n; i++)
    {
        liked = shared / 2;
        cum += liked;
        shared = liked * 3;
    }

    return cum;
}

int main()
{
    int n;
    scanf("%d", &n);
    int total = viralAdvertising(n);
    printf("%d\n", total);
    return 0;
}
