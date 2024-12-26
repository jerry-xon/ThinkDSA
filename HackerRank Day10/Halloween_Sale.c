#include <stdio.h>

int howManyGames(int p, int d, int m, int s) {
    int count = 0, cost = 0;
    while (cost + p <= s) {
        cost += p;
        count++;
        p = (p - d > m) ? p - d : m;
    }
    return count;
}

int main() {
    int p, d, m, s;
    scanf("%d %d %d %d", &p, &d, &m, &s);
    printf("%d\n", howManyGames(p, d, m, s));
    return 0;
}
