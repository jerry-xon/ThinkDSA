#include <stdio.h>

int lisasWorkbook(int n, int k, int arr[]) {
    int page = 1, specialProblems = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= arr[i]; j++) {
            if (j == page) {
                specialProblems++;
            }
            if (j % k == 0 || j == arr[i]) {
                page++;
            }
        }
    }
    return specialProblems;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", lisasWorkbook(n, k, arr));
    return 0;
}
