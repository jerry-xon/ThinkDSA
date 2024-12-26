#include <stdio.h>
#include <string.h>

int isAlternating(char *s, char a, char b)
{
    char prev = '\0';
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != a && s[i] != b)
            continue;
        if (s[i] == prev)
            return 0;
        prev = s[i];
    }
    return 1;
}

int alternateLength(char *s, char a, char b)
{
    int length = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == a || s[i] == b)
            length++;
    }
    return length;
}

int maxAlternatingLength(char *s)
{
    int maxLength = 0;
    int n = strlen(s);

    for (char c1 = 'a'; c1 <= 'z'; c1++)
    {
        for (char c2 = c1 + 1; c2 <= 'z'; c2++)
        {
            if (isAlternating(s, c1, c2))
            {
                int length = alternateLength(s, c1, c2);
                if (length > maxLength)
                    maxLength = length;
            }
        }
    }

    return maxLength;
}

int main()
{
    int n;
    scanf("%d", &n);
    char s[n];

    // printf("Enter the string: ");
    scanf("%s", s);

    int result = maxAlternatingLength(s);
    if (result == 1)
    {
        printf("0\n");
    }
    else
    {

        printf("%d\n", result);
    }

    return 0;
}
