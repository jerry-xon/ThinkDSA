#include <stdio.h>
#include <limits.h>
int hourglassSum(int arr[6][6])
{
    int i, j;

    int max_sum = INT_MIN;
    int sum = 0;
    for (i = 1; i < 5; i++)
    {
        for (j = 1; j < 5; j++)
        {
            sum = arr[i][j] + arr[i - 1][j - 1] + arr[i - 1][j] + arr[i - 1][j + 1]
            +arr[i + 1][j - 1] + arr[i + 1][j] + arr[i + 1][j + 1];
            if (sum > max_sum)
            {
                max_sum = sum;
            }
        }
    }
    return max_sum;
}

int main()
{
    int arr[6][6];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int result = hourglassSum(arr);
    printf("%d", result);
    return 0;
}