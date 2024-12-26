#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isSpecial(char ch)
{
    return (ch == '!' || ch == '@' || ch == '#' || ch == '$' || ch == '%' || ch == '^' || ch == '&' || ch == '*' || ch == '(' || ch == ')' || ch == '-' || ch == '+');
}
int strongPassword(char *str)
{
    int length = strlen(str);
    int hasdigit = 0, hasupper = 0, haslower = 0, hasSpecial = 0;

    for (int i = 0; i < length; i++)
    {
        if (isdigit(str[i]))
            hasdigit = 1;
        else if (isupper(str[i]))
            hasupper = 1;
        else if (islower(str[i]))
            haslower = 1;
        else if (isSpecial(str[i]))
            hasSpecial = 1;
    }
    int missing = 0;
    if (!hasdigit)
        missing++;
    if (!hasupper)
        missing++;
    if (!haslower)
        missing++;
    if (!hasSpecial)
        missing++;

    int minlen = 6 - length;
    if (minlen > 0)
    {
        return (missing > minlen) ? missing : minlen;
    }
    else
    {
        return missing;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    char a[n];
    scanf("%s", a);
    int letters = strongPassword(a);
    printf("%d\n", letters);

    return 0;
}