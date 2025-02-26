#include <stdio.h>
#include <limits.h>

int maxSubarraySum(int arr[], int n) {
    int max_sum = INT_MIN;  // Stores the maximum sum found
    int current_sum = 0;    // Tracks the sum of the current subarray

    for (int i = 0; i < n; i++) {
        current_sum += arr[i];  // Add the current element
        
        if (current_sum > max_sum)  // Update max_sum if needed
            max_sum = current_sum;
        
        if (current_sum < 0)  // Reset current_sum if it becomes negative
            current_sum = 0;
    }
    
    return max_sum;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int max_sum = maxSubarraySum(arr, n);
    printf("Maximum Subarray Sum: %d\n", max_sum);

    return 0;
}
