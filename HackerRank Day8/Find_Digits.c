#include <stdio.h>

int findDigits(int n)
{
    int count = 0, original = n;
    while (n != 0)
    {
        int remainder = n % 10;
        if (remainder != 0 && original % remainder == 0)
        {
            count++;
        }
        n /= 10;
    }
    return count;
}
int main()
{
    int t, n;
    scanf("%d", &t);
    while (t != 0)
    {
        scanf("%d", &n);
        int result = findDigits(n);
        printf("%d\n", result);
        t--;
    }
    return 0;
}
