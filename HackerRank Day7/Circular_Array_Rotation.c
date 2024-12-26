#include <stdio.h>

void circularArrayRotation(int n, int arr[], int k) {
    k = k % n; 
    int rotatedArr[n];

    for (int i = 0; i < n; i++) {
       
        rotatedArr[(i + k) % n] = arr[i];
    }

    
    for (int i = 0; i < n; i++) {
        arr[i] = rotatedArr[i];
    }
}

int main() {
    int n, k, q, index;

  
    scanf("%d %d %d", &n, &k, &q);
    int arr[n];

   
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    circularArrayRotation(n, arr, k);

    
    for (int i = 0; i < q; i++) {
        scanf("%d", &index); 
        printf("%d\n", arr[index]); 
    }

    return 0;
}
