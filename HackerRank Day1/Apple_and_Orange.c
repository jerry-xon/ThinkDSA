#include <stdio.h>

void countApplesAndOranges(int s, int t, int a, int b, int m, int n, int apple[], int orange[])
{
    int CountApple = 0;
    for (int i = 0; i < m; i++)
    {
        apple[i] += a;
        if (s <= apple[i] && apple[i] <= t)
        {
            CountApple++;
        }
    }

    int CountOrange = 0;
    for (int i = 0; i < n; i++)
    {
        orange[i] += b;
        if (s <= orange[i] && orange[i] <= t)
        {
            CountOrange++;
        }
    }

    printf("%d\n", CountApple);
    printf("%d\n", CountOrange);
};

int main()
{
    int s, t, a, b, m, n;

    scanf("%d %d", &s, &t);

    scanf("%d %d", &a, &b);

    scanf("%d %d", &m, &n);



    int apple[m], orange[n];

    // printf("Enter distances for apples: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d ", &apple[i]);
    }

    // printf("Enter distances for oranges: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &orange[i]);
    }

    countApplesAndOranges(s, t, a, b, m, n, apple, orange);

    return 0;
}
