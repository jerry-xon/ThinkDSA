#include <stdio.h>

int minimax(int depth, int nodeIndex, int isMax, int scores[], int h) {
    if (depth == h)
        return scores[nodeIndex];

    if (isMax)
        return (minimax(depth + 1, nodeIndex * 2, 0, scores, h) >
                minimax(depth + 1, nodeIndex * 2 + 1, 0, scores, h)) ?
                minimax(depth + 1, nodeIndex * 2, 0, scores, h) :
                minimax(depth + 1, nodeIndex * 2 + 1, 0, scores, h);
    else
        return (minimax(depth + 1, nodeIndex * 2, 1, scores, h) <
                minimax(depth + 1, nodeIndex * 2 + 1, 1, scores, h)) ?
                minimax(depth + 1, nodeIndex * 2, 1, scores, h) :
                minimax(depth + 1, nodeIndex * 2 + 1, 1, scores, h);
}

int main() {
    int h;
    printf("Enter height of the game tree: ");
    scanf("%d", &h);
    int totalNodes = 1 << h; // 2^h
    int scores[totalNodes];

    printf("Enter %d leaf node scores:\n", totalNodes);
    for (int i = 0; i < totalNodes; i++) {
        scanf("%d", &scores[i]);
    }

    int optimal = minimax(0, 0, 1, scores, h);
    printf("The optimal value is: %d\n", optimal);
    return 0;
}
