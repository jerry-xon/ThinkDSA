#include <stdio.h>

int main() {
    int n, t;
    scanf("%d %d", &n, &t);
    int width[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &width[i]);
    }
    while (t--) {
        int start, end, min = 100000;
        scanf("%d %d", &start, &end);
        for (int i = start; i <= end; i++) {
            if (width[i] < min) {
                min = width[i];
            }
        }
        printf("%d\n", min);
    }
    return 0;
}
