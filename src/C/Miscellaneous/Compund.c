#include <stdio.h>
#include <math.h>

int main() {
    long double principal, rate, time, n, amount, compoundInterest;

    
    printf("Enter the principal amount: ");
    scanf("%Lf", &principal);

    printf("Enter the annual interest rate (in %%): ");
    scanf("%Lf", &rate);

    printf("Enter the time (in years): ");
    scanf("%Lf", &time);

    printf("Enter the number of times interest is compounded per year: ");
    scanf("%Lf", &n);

   
    rate /= 100;

    
    amount = principal * powl((1 + rate / n), n * time);

   
    compoundInterest = amount - principal;

   
    printf("Final amount (A): %.10Lf\n", amount);
    printf("Compound Interest: %.10Lf\n", compoundInterest);

    return 0;
}
