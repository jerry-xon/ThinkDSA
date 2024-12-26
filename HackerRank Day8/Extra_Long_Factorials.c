#include <stdio.h>

void multiply(int result[], int *size, int num) {
    int carry = 0;
    for (int i = 0; i < *size; i++) {
        int product = result[i] * num + carry;
        result[i] = product % 10;
        carry = product / 10;
    }
    while (carry) {
        result[(*size)++] = carry % 10;
        carry /= 10;
    }
}

void extraLongFactorials(int n) {
    int result[5000];
    int size = 1;
    result[0] = 1;

    for (int i = 2; i <= n; i++) {
        multiply(result, &size, i);
    }

    for (int i = size - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    extraLongFactorials(n);
    return 0;
}
