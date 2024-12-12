#include <stdio.h>

void PlusMinus(int n, int arr[n])
{
    float N = 0, P = 0, Z = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            P++;
        }
        else if (arr[i] < 0)
        {
            N++;
        }
        else
        {
            Z++;
        }
    }
    printf("%0.6f\n",P/n);
    printf("%0.6f\n",N/n);
    printf("%0.6f\n",Z/n);
}

int main()
{
    int n;
    // printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    PlusMinus(n ,arr);
    return 0;
}