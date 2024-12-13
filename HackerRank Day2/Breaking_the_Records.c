#include <stdio.h>

void breakingRecords(int n, int score[n])
{
    int min = score[0];
    int max = score[0];
    int Cmax = 0;
    int Cmin = 0;
    for (int i = 1; i < n; i++)
    {
        if (score[i] > max)
        {
            max = score[i];
            Cmax++;
        }
        if (score[i] < min)
        {
            min = score[i];
            Cmin++;
        }
    }
    printf("%d %d", Cmax, Cmin);


}
int main()
{
    int n;
    scanf("%d", &n);
    int score[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &score[i]);
    }
    breakingRecords(n, score);

    return 0;
}

