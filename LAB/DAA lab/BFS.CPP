#include <stdio.h>
#include <stdlib.h>

void BFS(int adj[10][10], int visited[10], int n, int start) {
    int queue[10], front = 0, rear = -1, i;
    
    printf("%d ", start);
    visited[start] = 1;
    queue[++rear] = start;

    while (front <= rear) {
        int current = queue[front++];
        for (i = 1; i <= n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    int n, i, j, adj[10][10], visited[10] = {0}, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &adj[i][j]);
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    printf("BFS Traversal: ");
    BFS(adj, visited, n, start);
    return 0;
}