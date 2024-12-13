#include <stdio.h>

void choco(int n, int arr[], int d, int m) {
    int count = 0;

    
    for (int i = 0; i <= n - m; i++) {
        int sumofval = 0;

      
        for (int j = 0; j < m; j++) {
            sumofval += arr[i + j];
        }

        if (sumofval == d) {
            count++;
        }
    }

    
    printf("%d\n", count);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d ", &arr[i]);
    }

    int d, m;
    scanf("%d %d", &d, &m);

    choco(n, arr, d, m);
    return 0;
}
