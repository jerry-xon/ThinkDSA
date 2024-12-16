#include <stdio.h>

int pickingNumbers(int n, int arr[n]) {
    int frequency[101] = {0}; 

    for (int i = 0; i < n; i++) {
        frequency[arr[i]]++;
    }

    int maxCount = 0;

    for (int i = 1; i <= 100; i++) {
        int currentCount = frequency[i] + frequency[i - 1];
        if (currentCount > maxCount) {
            maxCount = currentCount;
        }
    }

    return maxCount;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    int result = pickingNumbers(n, arr);


    printf("%d\n", result);

    return 0;
}

