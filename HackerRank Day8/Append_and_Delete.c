#include <stdio.h>
#include <string.h>

char *appendAndDelete(char str1[], char str2[], int k)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

   
    int commonLength = 0;
    for (int i = 0; i < len1 && i < len2; i++)
    {
        if (str1[i] == str2[i])
        {
            commonLength++;
        }
        else
        {
            break;
        }
    }


    int deleteOps = len1 - commonLength;   
    int appendOps = len2 - commonLength;   
    int totalOps = deleteOps + appendOps;

    if (k >= totalOps && (k - totalOps) % 2 == 0)
    {
        return "Yes";
    }

    if (k >= len1 + len2)
    {
        return "Yes";
    }

    return "No";
}

int main()
{
    char str1[100];
    char str2[100];
    int k;

    scanf("%s", str1);
    scanf("%s", str2);
    scanf("%d", &k);

    
    char *result = appendAndDelete(str1, str2, k);
    printf("%s\n", result);

    return 0;
}
