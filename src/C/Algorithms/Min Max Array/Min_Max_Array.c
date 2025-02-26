#include <stdio.h>
#include <limits.h>

void findMinMax(int arr[], int low, int high, int *min, int *max) {
    // Base Case: Only one element
    if (low == high) {
        if (*min > arr[low]) *min = arr[low];
        if (*max < arr[low]) *max = arr[low];
        return;
    }

    // Base Case: Two elements, compare directly
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            if (*min > arr[low]) *min = arr[low];
            if (*max < arr[high]) *max = arr[high];
        } else {
            if (*min > arr[high]) *min = arr[high];
            if (*max < arr[low]) *max = arr[low];
        }
        return;
    }

    // Recursive Case: Split the array into two halves
    int mid = (low + high) / 2;
    
    findMinMax(arr, low, mid, min, max);
    findMinMax(arr, mid + 1, high, min, max);
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int min = INT_MAX, max = INT_MIN;
    findMinMax(arr, 0, n - 1, &min, &max);

    printf("Minimum Element: %d\n", min);
    printf("Maximum Element: %d\n", max);

    return 0;
}
