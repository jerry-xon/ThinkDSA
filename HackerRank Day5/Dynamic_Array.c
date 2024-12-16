#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    int **seqList = (int **)malloc(n * sizeof(int *));
    int *seqSizes = (int *)calloc(n, sizeof(int));


    for (int i = 0; i < n; i++)
    {
        seqList[i] = NULL;
    }

    int lastAns = 0;

    for (int i = 0; i < q; i++)
    {
        int type, x, y;
        scanf("%d %d %d\n", &type, &x, &y);

        int index = (x ^ lastAns) % n;

        if (type == 1)
        {

            seqSizes[index]++;
            seqList[index] = (int *)realloc(seqList[index], seqSizes[index] * sizeof(int));
            seqList[index][seqSizes[index] - 1] = y;
        }
        else if (type == 2)
        {

            int elementIndex = y % seqSizes[index];
            lastAns = seqList[index][elementIndex];
            printf("%d\n", lastAns);
        }
    }

    for (int i = 0; i < n; i++)
    {
        free(seqList[i]);
    }
    free(seqList);
    free(seqSizes);

    return 0;
}
