#include <stdio.h>

void dayOfProgrammer(int year) {
    if (year == 1918) {
        // Transition year
        printf("26.09.1918\n");
    } else if ((year < 1918 && year % 4 == 0) || // Julian leap year
               (year > 1918 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))) { // Gregorian leap year
        printf("12.09.%d\n", year); // Leap year
    } else {
        printf("13.09.%d\n", year); // Non-leap year
    }
}

int main() {
    int year;
    scanf("%d", &year);

    dayOfProgrammer(year);

    return 0;
}
