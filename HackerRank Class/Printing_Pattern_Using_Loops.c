#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // Read input value
    
    int size = 2 * n - 1; // Matrix size

    for (int i = 0; i < size; i++) { 
        for (int j = 0; j < size; j++) {
            // Calculate minimum distance from any edge
            int min_dist = i < j ? i : j;
            min_dist = min_dist < (size - i - 1) ? min_dist : (size - i - 1);
            min_dist = min_dist < (size - j - 1) ? min_dist : (size - j - 1);
            
            printf("%d ", n - min_dist);
        }
        printf("\n");
    }

    return 0;
}
