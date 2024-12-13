#include <stdio.h>

int divisibleSumPairs(int n, int arr[], int k) {
    int count = 0;

    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { 
            if ((arr[i] + arr[j]) % k == 0) {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    int n;
    int pair;
    int k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    pair = divisibleSumPairs(n, arr, k);
    printf("%d", pair);
    return 0;
}