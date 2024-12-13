#include <stdio.h>

int pageCount(int n, int p)
{
    int turns_from_front = p / 2;
    int turns_from_back = (n / 2) - (p / 2);
    return (turns_from_front < turns_from_back) ? turns_from_front : turns_from_back;
}

int main()
{
    int n, p;
    scanf("%d", &n);
    scanf("%d", &p);

    int result = pageCount(n, p);
    printf("%d\n", result);

    return 0;
}
