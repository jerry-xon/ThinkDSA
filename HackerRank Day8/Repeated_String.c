#include <stdio.h>
#include <string.h>

long repearedstring(char str[100], long n)
{
    long completecount = 0;
    long len = strlen(str);
    long count = 0;
    long complete = n / len;
    long left = n % len;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'a')
        {
            completecount++;
        }
    }
    if (left == 0)
    {
        count = 0;
    }
    else
    {
        for (int i = 0; i < left; i++)
        {
            if (str[i] == 'a')
            {
                count++;
            }
        }
    }

    long total = (completecount * complete) + count;
    return total;
}

int main()
{
    char str[100];
    scanf("%s", str);

    long n;
    scanf("%ld", &n);
    long total = repearedstring(str, n);
    printf("%ld", total);

    return 0;
}