#include <stdio.h>

int twoStacks(int n, int m, int S1[], int S2[], int max) {
    int sum = 0, count = 0;
    int t1 = 0, t2 = 0;

    while (t1 < n && sum + S1[t1] <= max) {
        sum += S1[t1];
        t1++;
        count++;
    }

   
    int max_count = count; 
    while (t2 < m) {
        sum += S2[t2];
        t2++;
        count++;

        while (sum > max && t1 > 0) {
            t1--;
            sum -= S1[t1];
            count--;
        }

        if (sum <= max) {
            if (count > max_count) {
                max_count = count;
            }
        }
    }

    return max_count;
}

int main() {
    int g;
    scanf("%d", &g);

    for (int i = 0; i < g; i++) {
        int n, m, max;
        scanf("%d %d %d", &n, &m, &max);

        int S1[n], S2[m];
        for (int j = 0; j < n; j++) scanf("%d", &S1[j]);
        for (int j = 0; j < m; j++) scanf("%d", &S2[j]);

        int result = twoStacks(n, m, S1, S2, max);
        printf("%d\n", result);
    }

    return 0;
}
