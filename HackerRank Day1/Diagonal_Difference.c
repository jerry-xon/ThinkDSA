#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 

int Diff(int n, int arr[n][n])
{
    int LD = 0, RD = 0;
    for(int i = 0 ; i < n ; i++){
        LD += arr[i][i];
    }
    for(int i = 0 ; i < n ; i++){
        RD += arr[i][n - i -1];
    }

    return LD - RD;
}

int main()
{
    int n;
    // printf("Enter the size of matrix: ");
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);

        }
        
    }
    int dif = Diff(n,arr);
    printf("%d", abs(dif));

    return 0;
}