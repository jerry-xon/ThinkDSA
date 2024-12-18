#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 1000
#define MAX_LENGTH 21

int main() {
    int n, q;

    scanf("%d", &n);

  
    char strings[MAX_STRINGS][MAX_LENGTH];
    int counts[MAX_STRINGS] = {0};


    for (int i = 0; i < n; i++) {
        char temp[MAX_LENGTH];
        scanf("%s\n", temp);

        
        int found = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(strings[j], temp) == 0) {
                counts[j]++;
                found = 1;
                break;
            }
        }

     
        if (!found) {
            strcpy(strings[i], temp);
            counts[i]++;
        }
    }

    
    scanf("%d", &q);


    for (int i = 0; i < q; i++) {
        char query[MAX_LENGTH];
        scanf("%s\n", query);

      
        int queryCount = 0;
        for (int j = 0; j < n; j++) {
            if (strcmp(strings[j], query) == 0) {
                queryCount = counts[j];
                break;
            }
        }

    
        printf("%d\n", queryCount);
    }

    return 0;
}
