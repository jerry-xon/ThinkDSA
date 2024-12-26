#include <stdio.h>

void cutthestick(int n, int arr[]) {
    while (1) {
        int len = 0;  
        int min = __INT_MAX__; 
        
        
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0 && arr[i] < min) {
                min = arr[i];
            }
            if (arr[i] > 0) {
                len++;
            }
        }
        
        if (len == 0) {
            break;
        }

        
        printf("%d\n", len);

        
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                arr[i] -= min;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    
   
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    cutthestick(n, arr);

    return 0;
}
