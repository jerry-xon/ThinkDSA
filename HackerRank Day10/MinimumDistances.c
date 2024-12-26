#include <stdio.h>
#include <limits.h>

int minimumDistances(int n, int arr[]) {
    int minDistance = INT_MAX;
    int lastIndex[100001];
    for (int i = 0; i < 100001; i++) {
        lastIndex[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        if (lastIndex[arr[i]] != -1) {
            int distance = i - lastIndex[arr[i]];
            if (distance < minDistance) {
                minDistance = distance;
            }
        }
        lastIndex[arr[i]] = i;
    }
    return (minDistance == INT_MAX) ? -1 : minDistance;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", minimumDistances(n, arr));
    return 0;
}
