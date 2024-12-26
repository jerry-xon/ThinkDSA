#include <stdio.h>
#include <string.h>

char* numbers[] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", 
    "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "quarter", 
    "sixteen", "seventeen", "eighteen", "nineteen", "twenty", 
    "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", 
    "twenty six", "twenty seven", "twenty eight", "twenty nine", "half"
};

void timeInWords(int h, int m) {
    if (m == 0)
        printf("%s o' clock\n", numbers[h]);
    else if (m == 15)
        printf("quarter past %s\n", numbers[h]);
    else if (m == 30)
        printf("half past %s\n", numbers[h]);
    else if (m == 45)
        printf("quarter to %s\n", numbers[h + 1]);
    else if (m < 30)
        printf("%s minute%s past %s\n", numbers[m], m == 1 ? "" : "s", numbers[h]);
    else
        printf("%s minute%s to %s\n", numbers[60 - m], (60 - m) == 1 ? "" : "s", numbers[h + 1]);
}

int main() {
    int h, m;
    scanf("%d %d", &h, &m);
    timeInWords(h, m);
    return 0;
}
