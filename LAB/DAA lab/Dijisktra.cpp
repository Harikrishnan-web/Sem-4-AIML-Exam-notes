#include <stdio.h>
#define INF 999

void dijkstra(int n, int cost[10][10], int src) {
    int dist[10], visited[10], count, min, nextnode, i, j;
    for (i = 1; i <= n; i++) {
        dist[i] = cost[src][i];
        visited[i] = 0;
    }
    dist[src] = 0;
    visited[src] = 1;
    count = 1;
    while (count < n) {
        min = INF;
        for (i = 1; i <= n; i++)
            if (dist[i] < min && !visited[i]) {
                min = dist[i];
                nextnode = i;
            }
        visited[nextnode] = 1;
        for (i = 1; i <= n; i++)
            if (!visited[i])
                if (min + cost[nextnode][i] < dist[i])
                    dist[i] = min + cost[nextnode][i];
        count++;
    }
    for (i = 1; i <= n; i++)
        if (i != src) printf("\nDistance to %d: %d", i, dist[i]);
}

int main() {
    int n, cost[10][10], i, j, s;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter weight matrix (use 999 for infinity):\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);
    printf("Enter source: ");
    scanf("%d", &s);
    dijkstra(n, cost, s);
    return 0;
}