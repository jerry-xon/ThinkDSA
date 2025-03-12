#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }

int alphabeta(int depth, int nodeIndex, int isMax, int scores[], int h, int alpha, int beta) {
    if (depth == h)
        return scores[nodeIndex];

    if (isMax) {
        int best = -1000;
        best = max(best, alphabeta(depth + 1, nodeIndex * 2, 0, scores, h, alpha, beta));
        alpha = max(alpha, best);
        if (beta <= alpha)
            return best;
        best = max(best, alphabeta(depth + 1, nodeIndex * 2 + 1, 0, scores, h, alpha, beta));
        return best;
    } else {
        int best = 1000;
        best = min(best, alphabeta(depth + 1, nodeIndex * 2, 1, scores, h, alpha, beta));
        beta = min(beta, best);
        if (beta <= alpha)
            return best;
        best = min(best, alphabeta(depth + 1, nodeIndex * 2 + 1, 1, scores, h, alpha, beta));
        return best;
    }
}

int main() {
    int h;
    printf("Enter height of the tree: ");
    scanf("%d", &h);
    int totalNodes = 1 << h;
    int scores[totalNodes];

    printf("Enter %d leaf node scores:\n", totalNodes);
    for (int i = 0; i < totalNodes; i++) {
        scanf("%d", &scores[i]);
    }

    int optimal = alphabeta(0, 0, 1, scores, h, -1000, 1000);
    printf("The optimal value is: %d\n", optimal);
    return 0;
}
