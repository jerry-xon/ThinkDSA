#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 4  // Number of cities

int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find the minimum edge cost for a given row
int findMinRowCost(int costMatrix[N][N], int row, bool visited[]) {
    int minCost = INT_MAX;
    for (int j = 0; j < N; j++) {
        if (!visited[j] && costMatrix[row][j] && row != j)
            minCost = min(minCost, costMatrix[row][j]);
    }
    return (minCost == INT_MAX) ? 0 : minCost;
}

// Function to find the initial lower bound
int calculateLowerBound(int costMatrix[N][N]) {
    int bound = 0;
    for (int i = 0; i < N; i++)
        bound += (findMinRowCost(costMatrix, i, (bool[N]) {false}));
    return (bound + 1) / 2;
}

// TSP Recursive Function
void tsp(int costMatrix[N][N], bool visited[], int currPos, int count, int cost, int* minCost, int path[], int bestPath[]) {
    if (count == N && costMatrix[currPos][0]) {
        *minCost = min(*minCost, cost + costMatrix[currPos][0]);
        if (*minCost == cost + costMatrix[currPos][0]) {
            for (int i = 0; i < N; i++)
                bestPath[i] = path[i];
            bestPath[N] = 0;
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i] && costMatrix[currPos][i]) {
            visited[i] = true;
            path[count] = i;
            tsp(costMatrix, visited, i, count + 1, cost + costMatrix[currPos][i], minCost, path, bestPath);
            visited[i] = false;
        }
    }
}

// Driver Function
int main() {
    int costMatrix[N][N] = {
        { 0, 10, 15, 20 },
        { 10, 0, 35, 25 },
        { 15, 35, 0, 30 },
        { 20, 25, 30, 0 }
    };

    int minCost = INT_MAX;
    bool visited[N] = {false};
    visited[0] = true;  // Start from the first city
    int path[N + 1], bestPath[N + 1];

    tsp(costMatrix, visited, 0, 1, 0, &minCost, path, bestPath);

    printf("Minimum Cost: %d\n", minCost);
    printf("Path: ");
    for (int i = 0; i <= N; i++)
        printf("%d ", bestPath[i]);
    printf("\n");

    return 0;
}
