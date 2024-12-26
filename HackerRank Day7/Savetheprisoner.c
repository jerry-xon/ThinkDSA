#include <stdio.h>

int saveThePrisoner(int n, int m, int s) {
    int result = (s + m - 1) % n;
    return (result == 0) ? n : result;
}

int main() {
    int t;
    scanf("%d", &t); 

    while (t--) {
        int n, m, s;
        scanf("%d %d %d", &n, &m, &s); 
        int result = saveThePrisoner(n, m, s);
        printf("%d\n", result);
    }

    return 0;
}
