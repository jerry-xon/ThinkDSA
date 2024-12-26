#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int q;
    scanf("%d", &q);
    int isPalindrome = 1;

    while (q--)
    {
        scanf("%s", str);
        int len = strlen(str);

        for (int i = 0; i < len / 2; i++)
        {
            if (str[i] != str[len - i - 1])
            {
                
                isPalindrome = 0;
                break;
            }
        }
        if (isPalindrome)
        {
            printf("Palindrome\n");
        }
        else
        {
            printf("Not a Palindrome\n");
        }
    }

    return 0;
}
