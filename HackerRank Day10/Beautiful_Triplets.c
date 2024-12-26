#include <stdio.h>

int beautifulTriplets(int d, int n, int arr[]) {
    int count = 0;

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            if (arr[j] - arr[i] == d) {
                for (int k = j + 1; k < n; k++) {
                    if (arr[k] - arr[j] == d) {
                        count++;
                    }
                }
            }
        }
    }

    return count;
}

int main() {
    int n, d;
    scanf("%d %d", &n, &d);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", beautifulTriplets(d, n, arr));
    return 0;
}
