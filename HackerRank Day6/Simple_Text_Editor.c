#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *stack[1000000];
int top = -1;

void push(const char *text) {
    stack[++top] = strdup(text);
}

char *pop() {
    if (top == -1) return "";
    return stack[top--];
}

int main() {
    int q;
    scanf("%d", &q);

    char text[1000000] = "";
    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 1) { 
            push(text); 
            char appendStr[1000000];
            scanf("%s", appendStr);
            strcat(text, appendStr);
        } 
        else if (type == 2) {
            push(text); 
            int k;
            scanf("%d", &k);
            int len = strlen(text);
            if (k <= len) {
                text[len - k] = '\0'; 
            }
        } 
        else if (type == 3) { 
            int k;
            scanf("%d", &k);
            printf("%c\n", text[k - 1]); 
        } 
        else if (type == 4) { 
            strcpy(text, pop()); 
        }
    }


    for (int i = 0; i <= top; i++) {
        free(stack[i]);
    }

    return 0;
}
