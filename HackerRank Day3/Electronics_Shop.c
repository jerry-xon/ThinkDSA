#include <stdio.h>

int getMoneySpent(int keyboards[], int n, int drives[], int m, int budget) {
    int max_spent = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int total = keyboards[i] + drives[j];
            if (total <= budget && total > max_spent) {
                max_spent = total;
            }
        }
    }

    return max_spent;
}

int main() {
    int budget, n, m;

    
    scanf("%d %d %d", &budget, &n, &m);

    int keyboards[n], drives[m];


    for (int i = 0; i < n; i++) {
        scanf("%d", &keyboards[i]);
    }

  
    for (int i = 0; i < m; i++) {
        scanf("%d", &drives[i]);
    }

    
    int result = getMoneySpent(keyboards, n, drives, m, budget);
    printf("%d\n", result);

    return 0;
}
