#include <stdio.h>
#include <string.h>
int main()
{
    char str[99];
    int count = 0;
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (i % 3 == 0 && str[i] != 'S') {
            count++; 
        } else if (i % 3 == 1 && str[i] != 'O') {
            count++; 
        } else if (i % 3 == 2 && str[i] != 'S') {
            count++; 
        }
    }

    printf("%d",count);

    return 0;
}