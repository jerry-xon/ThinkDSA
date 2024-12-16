#include <stdio.h>
#include <string.h>
void revers(char str[200]){
    int length = strlen(str);
    for(int i = length - 1;i>=0;i++){
        printf("%c",str[i]);
    }
}
int main()
{
    char str[200];
    scanf("%s",str);
    revers(str);
  return 0;
}