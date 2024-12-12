#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isQueueEmpty() {
    return front == -1 || front > rear;
}

void BFS(int graph[MAX][MAX], int startVertex, int numVertices) {
    int visited[MAX] = {0};
    enqueue(startVertex);
    visited[startVertex] = 1;

    printf("BFS Traversal: ");
    while (!isQueueEmpty()) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}
int main() {
    int graph[MAX][MAX] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 1, 0, 1, 0}
    };
    int numVertices = 5;
    int startVertex = 0;

    BFS(graph, startVertex, numVertices);
    // performDFS(graph, startVertex, numVertices);

    return 0;
}
