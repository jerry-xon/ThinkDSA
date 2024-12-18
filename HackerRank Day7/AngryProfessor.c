#include <stdio.h>

void angryProfessor(int t) {
    while (t--) {
        int n, k, count = 0;
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) {
            int arrivalTime;
            scanf("%d", &arrivalTime);
            if (arrivalTime <= 0) {
                count++;
            }
        }
        if (count >= k) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    angryProfessor(t);
    return 0;
}
