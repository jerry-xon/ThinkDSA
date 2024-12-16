#include <stdio.h>

void reverseArray(int n, int arr[n]){
    for(int i = n-1 ; i>=0 ;i--){
        printf("%d ",arr[i]);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i =0 ; i<n;i++){
        scanf("%d",&arr[i]);
    }
    reverseArray(n, arr);
  return 0;
}