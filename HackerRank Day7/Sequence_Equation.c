#include <stdio.h>

void sequenceEquation(int n, int p[]) {
    int position[n + 1];
    for (int i = 1; i <= n; i++) {
        position[p[i]] = i;
    }
    for (int x = 1; x <= n; x++) {
        printf("%d\n", position[position[x]]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int p[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    sequenceEquation(n, p);
    return 0;
}
