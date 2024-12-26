#include <stdio.h>
#include <string.h>
#include <ctype.h>

void caesarCipher(char *text, int shift, int n) {
    shift = shift % 26; 

    for (int i = 0; i < n; i++) {
        char ch = text[i];

        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a'; 
            text[i] = (ch - base + shift + 26) % 26 + base; 
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar(); 

    char text[n + 1]; 
    int shift;

    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; 

    scanf("%d", &shift);

    caesarCipher(text, shift, strlen(text));

    printf("%s\n", text);

    return 0;
}
