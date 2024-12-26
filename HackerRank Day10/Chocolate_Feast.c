#include <stdio.h>

int chocolateFeast(int n, int c, int m) {
    int chocolates = n / c;
    int wrappers = chocolates;
    while (wrappers >= m) {
        int extraChocolates = wrappers / m;
        chocolates += extraChocolates;
        wrappers = wrappers % m + extraChocolates;
    }
    return chocolates;
}

int main() {
    int t, n, c, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &c, &m);
        printf("%d\n", chocolateFeast(n, c, m));
    }
    return 0;
}
