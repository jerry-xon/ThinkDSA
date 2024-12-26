#include <stdio.h>
#include <string.h>

char *superReducedString(char *str)
{
    int length = strlen(str);

    for (int i = 0; i < length - 1;)
    {
        if (str[i] == str[i + 1])
        {

            for (int j = i; j < length - 1; j++)
            {
                str[j] = str[j + 2];
            }
            length -= 2;
            if (i > 0)
                i--;
        }
        else
        {
            i++;
        }
    }

    if (length == 0)
    {
        strcpy(str, "Empty String");
    }

    return str;
}

int main()
{
    char str[101];
    scanf("%100s", str);
    printf("%s\n", superReducedString(str));

    return 0;
}
