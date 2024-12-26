#include <stdio.h>

int equalizeArray(int n, int arr[n])
{
    int count = 0;
    int frequency[100] = {0};
    for (int i = 0; i < n; i++)
    {
        frequency[arr[i]]++;
    }

    int maxcount = 0;
    int Numtype = 0;

    for (int i = 1; i < 100; i++)
    {
        if (frequency[i] > maxcount)
        {
            maxcount = frequency[i];
            Numtype = i;
        }
        else if (frequency[i] == maxcount && i < Numtype)
        {
            Numtype = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != Numtype)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int deletion = equalizeArray(n, arr);
    printf("%d", deletion);
    return 0;
}