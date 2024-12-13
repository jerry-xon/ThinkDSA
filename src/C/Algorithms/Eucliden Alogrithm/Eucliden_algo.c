// The Euclidean algorithm is a way to find the greatest common divisor of two positive integers.

#include <stdio.h>

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}
int main()
{
    int a = 10, b = 15;
    printf("GCD(%d %d) is = %d.\n", a, b, gcd(a, b));
    a = 35, b = 10;
    printf("GCD(%d %d) is = %d.\n", a, b, gcd(a, b));
    a = 31, b = 2;
    printf("GCD(%d %d) is = %d.\n", a, b, gcd(a, b));
    return 0;
}