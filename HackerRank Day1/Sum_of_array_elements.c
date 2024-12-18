#include <stdio.h>

int Sum(int arr[], int size)
{
    int total = 0;

    for (int i = 0; i < size; i++)
    {
        total = total + arr[i];
    }
    return total;
};

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element of array: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int total = Sum(arr, n);
    printf("The total sum of all elements is: %d", total);

    return 0;
}