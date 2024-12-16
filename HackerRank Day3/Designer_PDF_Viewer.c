#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int designerPdfViewer(int h[26], char str[10])
{
    int index = 0;
    int max_height = 0;
    for(int i = 0; i < strlen(str); i++)
    {
        index = str[i] - 'a';
        if(h[index] > max_height)
        {
            max_height = h[index];
        }
    }
    int area = max_height * strlen(str);
    return area;
}
int main()
{
    int h[26];
    for (int i = 0; i < 26; i++)
    {
        scanf("%d", &h[i]);
    }
    char str[10];
  
         scanf("%s", str);


    int area = designerPdfViewer(h, str);
    printf("%d",area);

    return 0;
}