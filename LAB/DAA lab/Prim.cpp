#include <stdio.h>

int main() {
    int n, i, j, ne = 1;
    int visited[10] = {0}, min, a, b, u, v, mincost = 0;
    int cost[10][10];

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (use 999 for infinity):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) cost[i][j] = 999;
        }
    }

    visited[1] = 1;
    while (ne < n) {
        min = 999;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    if (visited[i] != 0) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }
        if (visited[u] == 0 || visited[v] == 0) {
            printf("\n Edge %d:(%d %d) cost:%d", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\n Minimum cost = %d", mincost);
    return 0;
}