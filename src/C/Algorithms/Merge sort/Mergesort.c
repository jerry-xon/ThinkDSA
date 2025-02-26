#include <stdio.h>

void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] =arr[l + i]; 
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {

            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
   
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

void printarr(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}
int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter %d elements for the array: ",n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Before sort\n");
    printarr(arr, n);
    mergeSort(arr, 0, n-1);
    printf("\nAfter sort\n");
    printarr(arr, n);

    return 0;
}