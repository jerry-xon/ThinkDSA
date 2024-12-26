#include <stdio.h>
#include <math.h>

void kaprekarNumbers(long p, long q) {
    int count = 0;
    for (long i = p; i <= q; i++) {
        long square = (long)i * i;
        int length = (int)log10(i) + 1;
        long divisor = pow(10, length);
        long left = square / divisor;
        long right = square % divisor;

        if (left + right == i) {
            printf("%ld ", i);
            count++;
        }
    }
    if (count == 0) {
        printf("INVALID RANGE");
    }
}

int main() {
    long p, q;
    scanf("%ld %ld", &p, &q);
    kaprekarNumbers(p, q);
    return 0;
}
