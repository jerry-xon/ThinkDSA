#include <stdio.h>

long long taumBday(int b, int w, int Bc, int Wc, int z) {
    long long blackCost = (long long)b * Bc;
    long long whiteCost = (long long)w * Wc;
    long long convertToBlackCost = (long long)b * (Wc + z);
    long long convertToWhiteCost = (long long)w * (Bc + z);

    long long minBlackCost = blackCost < convertToBlackCost ? blackCost : convertToBlackCost;
    long long minWhiteCost = whiteCost < convertToWhiteCost ? whiteCost : convertToWhiteCost;

    return minBlackCost + minWhiteCost;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int b, w, Bc, Wc, z;
        scanf("%d %d", &b, &w);
        scanf("%d %d %d", &Bc, &Wc, &z);
        printf("%lld\n", taumBday(b, w, Bc, Wc, z));
    }

    return 0;
}
