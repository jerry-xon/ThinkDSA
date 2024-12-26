#include <stdio.h>
#include <string.h>
#include <ctype.h>


int camelcase(char *str)
{
    int len = strlen(str);
    int words = 1;
    for(int i = 0;i<len-1;i++){
        if(isupper(str[i])){
            words++;
        }
    }
    return words;
}
int main()
{
    char str[100000];
    scanf("%s", str);
    int words = camelcase(str);
    printf("%d\n", words);
    return 0;
}