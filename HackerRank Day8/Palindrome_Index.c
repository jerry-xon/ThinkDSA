#include <stdio.h>
#include <string.h>

int isPalindrome(char str[], int left, int right)
{
    while (left < right)
    {
        if (str[left] != str[right])
        {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

int palindromeIndex(char str[])
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (isPalindrome(str, i + 1, len - 1))
        {
            return i;
        }
        if (isPalindrome(str, 0, len - i - 2))
        {
            return len - i - 1;
        }
    }
    return -1;
}

int main()
{
    int q;
    scanf("%d", &q);
    while (q--)
    {
        char str[100000];
        scanf("%s", str);
        int index = palindromeIndex(str);
        if (index == -1)
        {
            printf("No palindrome index\n");
        }
        else
        {
            printf("%d\n", index);
        }
    }

    return 0;
}
