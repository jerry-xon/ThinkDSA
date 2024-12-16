#include <stdio.h>
#include <stdlib.h>
int hurdleRace(int n, int height[n], int k)
{

    int max;

    int highest = height[0];
    for (int i = 0; i < n; i++)
    {
        if (height[i] > highest)
        {
            highest = height[i];
        }
    }

    if(k<highest){
    max = abs(highest - k);
    return max;
    }
    else{
        return 0;
    }
}
int main()
{
    int n;
    int k;

    scanf("%d %d", &n, &k);
    int height[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &height[i]);
    }

    int max = hurdleRace(n, height, k);
    printf("%d", max);

    return 0;
}