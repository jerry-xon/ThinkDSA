#include <stdio.h>

void bonAppetit(int n, int items[], int k, int annapay)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (i != k)
        {
            sum += items[i];
        }
    }

    
    int annashare = sum / 2;

 
    if (annashare == annapay)
    {
        printf("Bon Appetit\n");
    }
    else
    {
        printf("%d\n", annapay - annashare);
    }
}

int main()
{
    int n, k, annapay;
    scanf("%d %d", &n, &k);

    int items[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &items[i]);
    }

    scanf("%d", &annapay);

    bonAppetit(n, items, k, annapay);

    return 0;
}
