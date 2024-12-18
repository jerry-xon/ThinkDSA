#include <stdio.h>

int main()
{
    int m, n, r, temp, ring, ro;
    scanf("%d %d %d", &m, &n, &r);
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    if (m > n)
    {
        ring = n / 2;
    }
    else
    {
        ring = m / 2;
    }
    for (int i = 0; i < ring; i++)
    {

        ro = r % (2 * m + 2 * n - 8 * i - 4);
        for (int k = 0; k < ro; k++)
        {
            for (int j = i; j < n - i - 1; j++)
            {
                temp = a[i][j];
                a[i][j] = a[i][j + 1];
                a[i][j + 1] = temp;
            }
            for (int j = i; j < m - i - 1; j++)
            {
                temp = a[j][n - i - 1];
                a[j][n - i - 1] = a[j + 1][n - i - 1];
                a[j + 1][n - i - 1] = temp;
            }
            for (int j = n - i - 1; j > i; j--)
            {
                temp = a[m - i - 1][j];
                a[m - i - 1][j] = a[m - i - 1][j - 1];
                a[m - i - 1][j - 1] = temp;
            }
            for (int j = m - i - 1; j > i + 1; j--)
            {
                temp = a[j][i];
                a[j][i] = a[j - 1][i];
                a[j - 1][i] = temp;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}