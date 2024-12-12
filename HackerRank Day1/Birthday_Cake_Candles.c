#include <stdio.h>

void Blowout(int n, int arr[n])
{
    int BO = 0;
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        if(arr[i] > BO){
            BO = arr[i];
            total = 1;
        }
        if(arr[i] == BO){
            total++;
        }
    }
    printf("%d",total-1);
}
int main()
{
    int n;
    // printf("Enter the numberof candels: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    Blowout(n, arr);
    return 0;
}