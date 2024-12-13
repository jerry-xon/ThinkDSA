#include <stdio.h>

int migratoryBirds(int n, int arr[n]){

    int  frequency[6] = {0};
    for(int i = 0; i <n; i++){
        frequency[arr[i]]++;
    }

    int maxcount = 0;
    int birdtype = 0;

    for(int i = 1 ; i <= 5 ;i++){
        if(frequency[i] > maxcount){
            maxcount = frequency[i];
            birdtype = i;
        }
        else if(frequency[i] == maxcount && i < birdtype){
            birdtype = i;
        }
    }
     return birdtype;
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

    int result = migratoryBirds(n,arr);
    printf("%d",result);

    return 0;
}