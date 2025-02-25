#include <stdio.h>

int binarySearch(int arr[], int target, int low, int high)
{
    if (low > high)
    {
        return -1; 
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
    {
        return mid; 
    }
    else if (arr[mid] > target)
    {
        return binarySearch(arr, target, low, mid - 1); 
    }
    else
    {
        return binarySearch(arr, target, mid + 1, high); 
    }
}
  
int main()
{
    int n;
    scanf("%d", &n);
    int sortedArray[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &sortedArray[i]);
    }
    int target;
    scanf("%d", &target);
   
    int result = binarySearch(sortedArray, target, 0, n - 1);

    if (result != -1)
    {
        printf("Element found at index %d\n", result);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}
