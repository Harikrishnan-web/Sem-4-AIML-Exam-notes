#include <stdio.h>

void warshall(int n, int adj[10][10]) {
    int i, j, k;
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                adj[i][j] = adj[i][j] || (adj[i][k] && adj[i][k]);
            }
        }
    }
}

int main() {
    int n, i, j, adj[10][10];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (0/1):\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &adj[i][j]);
    
    warshall(n, adj);
    
    printf("\nTransitive Closure Matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
    return 0;
}