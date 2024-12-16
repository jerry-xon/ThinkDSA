#include <stdio.h>
#include <stdlib.h>

void leftRotate(int arr[], int n, int d) {
    int* rotatedArr = (int*)malloc(n * sizeof(int));
    
    d = d % n;

    for (int i = 0; i < n; i++) {
        rotatedArr[i] = arr[(i + d) % n];
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", rotatedArr[i]);
    }

    free(rotatedArr);
}

int main() {
    int n, d;
    scanf("%d %d", &n, &d);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    leftRotate(arr, n, d);

    free(arr);
    return 0;
}
