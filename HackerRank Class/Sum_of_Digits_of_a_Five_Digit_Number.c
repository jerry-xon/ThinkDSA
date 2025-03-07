#include <stdio.h>

int main() {
    int num, sum = 0;
    scanf("%d", &num);  // Read the 5-digit number

    // Extract digits and sum them up
    while (num > 0) {
        sum += num % 10;  // Get last digit
        num /= 10;        // Remove last digit
    }

    printf("%d\n", sum);  // Print the sum
    return 0;
}
