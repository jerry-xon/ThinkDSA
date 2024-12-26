#include <stdio.h>

int jumpingOnCloudsRevisited(int n, int k, int clouds[]) {
    int energy = 100;
    int current = 0;

    do {
        current = (current + k) % n;
        energy--; 
        if (clouds[current] == 1) {
            energy -= 2; 
        }
    } while (current != 0);

    return energy;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int clouds[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &clouds[i]);
    }

    int energy = jumpingOnCloudsRevisited(n, k, clouds);
    printf("%d\n", energy);

    return 0;
}
