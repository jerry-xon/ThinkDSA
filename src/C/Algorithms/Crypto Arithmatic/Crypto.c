#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char word1[10], word2[10], result[10];
char uniqueChars[10];
int charCount = 0;
int charDigit[256];  
bool usedDigit[10];  


long getValue(char *word) {
    long value = 0;
    for (int i = 0; word[i]; i++) {
        value = value * 10 + charDigit[word[i]];
    }
    return value;
}


bool hasLeadingZero(char *word) {
    return charDigit[word[0]] == 0;
}


bool solve(int idx) {
    if (idx == charCount) {
        if (hasLeadingZero(word1) || hasLeadingZero(word2) || hasLeadingZero(result))
            return false;

        long num1 = getValue(word1);
        long num2 = getValue(word2);
        long res  = getValue(result);

        if (num1 + num2 == res) {
            printf("\n✅ Solution Found:\n");
            for (int i = 0; i < charCount; i++) {
                printf("%c = %d\n", uniqueChars[i], charDigit[uniqueChars[i]]);
            }
            printf("\n%ld + %ld = %ld\n", num1, num2, res);
            return true;
        }
        return false;
    }

    for (int d = 0; d < 10; d++) {
        if (!usedDigit[d]) {
            usedDigit[d] = true;
            charDigit[uniqueChars[idx]] = d;

            if (solve(idx + 1))
                return true;

            usedDigit[d] = false;
        }
    }
    return false;
}


void findUniqueChars() {
    int map[256] = {0};
    charCount = 0;
    for (int i = 0; word1[i]; i++)
        if (!map[word1[i]]) {
            map[word1[i]] = 1;
            uniqueChars[charCount++] = word1[i];
            
        }

    for (int i = 0; word2[i]; i++)
        if (!map[word2[i]]) {
            map[word2[i]] = 1;
            uniqueChars[charCount++] = word2[i];
        }

    for (int i = 0; result[i]; i++)
        if (!map[result[i]]) {
            map[result[i]] = 1;
            uniqueChars[charCount++] = result[i];
        }
}

int main() {
    printf("Enter first word: ");
    scanf("%s", word1);

    printf("Enter second word: ");
    scanf("%s", word2);

    printf("Enter result word: ");
    scanf("%s", result);

    findUniqueChars();

    if (charCount > 10) {
        printf("Too many unique characters (max 10 allowed).\n");
        return 1;
    }

    if (!solve(0))
        printf("\n❌ No solution found.\n");

    return 0;
}
