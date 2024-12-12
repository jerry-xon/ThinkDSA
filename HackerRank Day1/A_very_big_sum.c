#include <stdio.h>

long Sum(long arr[], int size)
{
    long total = 0;

    for (int i = 0; i < size; i++)
    {
        total += arr[i];
    }
    return total;
};

int main()
{
    int n;
    // printf("Enter size of array: ");
    scanf("%d ", &n);
        long arr[n];
        for (int i = 0; i < n; i++)
        {
            // printf("Enter %d element of array: ", i + 1);
            scanf("%ld", &arr[i]);
           
            
        }
        long total = Sum(arr, n);
        printf("%ld", total);
        // printf("The total sum of all elements is: %ld", total);
    

    return 0;
}
