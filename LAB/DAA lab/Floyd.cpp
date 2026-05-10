#include <stdio.h>

#define INF 999

void floyd(int n, int dist[10][10]) {
    int i, j, k;
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int n, i, j, dist[10][10];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter weight matrix (use 999 for INF):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }
    floyd(n, dist);
    printf("\nAll-Pairs Shortest Paths Matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (dist[i][j] == INF) printf("INF\t");
            else printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}