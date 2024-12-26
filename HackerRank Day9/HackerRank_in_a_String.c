#include <stdio.h>
#include <string.h>

int main()
{
    int q;
    scanf("%d", &q);
    while (q--)
    {
        char s[10000];
        scanf("%s\n", s);

        char target[] = "hackerrank";
        int targetlen = strlen(target);
        int j = 0;
        for (int i = 0; i < strlen(s); i++)
        {
            if (s[i] == target[j])
            {
                j++;
            }
            else if (j == targetlen)
            {
                break;
            }
        }
        if (j == targetlen)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}