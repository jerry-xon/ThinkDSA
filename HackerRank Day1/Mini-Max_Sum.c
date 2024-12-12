#include <stdio.h>

void MinMaxSum(long arr[5]) {
    long S = 0, Maxsum = 0, Minsum = 0;
    
    for (int i = 0; i < 5; i++) {
        S += arr[i];
    }
    
    Minsum = S - arr[0];
    Maxsum = S - arr[0];
   
    for (int i = 1; i < 5; i++) {
        long currentSum = S - arr[i];
        if (currentSum > Maxsum) {
            Maxsum = currentSum;
        }
        if (currentSum < Minsum) {
            Minsum = currentSum;
        }
    }

    printf("%ld ", Minsum);
    printf("%ld", Maxsum);
}

int main() {
    long arr[5];
    

    // printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%ld", &arr[i]);
    }
    
    
    MinMaxSum(arr);
  
    return 0;
}

