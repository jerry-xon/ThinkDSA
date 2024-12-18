#include <stdio.h>
#include <stdlib.h>

int reverse(int num) {
    int reverse = 0;
    while (num != 0) {
        int remainder = num % 10;
        reverse = reverse * 10 + remainder;
        num /= 10;
    }
    return reverse;
}

int beautifulDays(int i, int j, int k) {
    int day = 0;
    for (int start = i; start <= j; start++) {
        int reversed = reverse(start);
        if (abs(start - reversed) % k == 0) {
            day++;
        }
    }
    return day;
}

int main() {
    int i, j, k;
    scanf("%d %d %d", &i, &j, &k);
    int days = beautifulDays(i, j, k);
    printf("%d\n", days);
    return 0;
}
