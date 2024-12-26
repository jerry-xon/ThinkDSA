#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isPangram(char *str) {
    int alphabet[26] = {0}; 
    int count = 0;         

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) { 
            char lower = tolower(str[i]);
            int index = lower - 'a';
            if (alphabet[index] == 0) {
                alphabet[index] = 1; 
                count++;
            }
        }
    }

    return count == 26; 
}

int main() {
    char str[1001];
    fgets(str, sizeof(str), stdin); 

    if (isPangram(str)) {
        printf("pangram\n");
    } else {
        printf("not pangram\n");
    }

    return 0;
}
