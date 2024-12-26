#include <stdio.h>

int jumpingOnClouds(int n, int c[]) {
    int jumps = 0;
    int i = 0;   

    while (i < n - 1) {
        
        if (i + 2 < n && c[i + 2] == 0) {
            i += 2;
        } else {
            
            i += 1;
        }
        jumps++; 
    }

    return jumps;
}

int main() {
    int n;
    scanf("%d", &n); 
    int c[n];

    
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    int jumps = jumpingOnClouds(n, c);
    printf("%d\n", jumps);

    return 0;
}
