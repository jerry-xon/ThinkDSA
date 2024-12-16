#include <stdio.h>

int utopianTree(int n) {
    int height = 1; 

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) { 
            height *= 2;
        } else { 
            height += 1;
        }
    }

    return height;
}

int main() {
    int t;
    scanf("%d", &t); 

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n); 
        int result = utopianTree(n);
        printf("%d\n", result);
    }

    return 0;
}
