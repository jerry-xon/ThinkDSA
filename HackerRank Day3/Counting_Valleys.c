#include <stdio.h>

int countingValleys(int steps, char path[]) {
    int level = 0;
    int valleys = 0;

    for (int i = 0; i < steps; i++) {
        if (path[i] == 'U') {
            level++;
            if (level == 0) {
                valleys++; 
            }
        } else if (path[i] == 'D') {
            level--;
        }
    }

    return valleys;
}

int main() {
    int steps;
    scanf("%d", &steps);
    char path[steps + 1]; 

    scanf("%s", path);

    int valleys = countingValleys(steps, path);
    printf("%d\n", valleys);

    return 0;
}
