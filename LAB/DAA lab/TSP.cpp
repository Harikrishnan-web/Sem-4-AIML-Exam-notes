#include <stdio.h>

int n, dist[10][10], visited[10];
int optimal_cost = 999;

void find_optimal(int curr, int count, int cost, int start) {
    if (count == n && dist[curr][start]) {
        if (cost + dist[curr][start] < optimal_cost)
            optimal_cost = cost + dist[curr][start];
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[curr][i]) {
            visited[i] = 1;
            find_optimal(i, count + 1, cost + dist[curr][i], start);
            visited[i] = 0;
        }
    }
}

int main() {
    int i, j, approx_cost = 0, curr = 1;
    printf("Enter number of cities: ");
    scanf("%d", &n);
    printf("Enter distance matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &dist[i][j]);

    visited[1] = 1;
    find_optimal(1, 1, 0, 1);

    for (i = 1; i <= n; i++) visited[i] = 0;
    visited[1] = 1;
    for (i = 1; i < n; i++) {
        int next = -1, min = 999;
        for (j = 1; j <= n; j++) {
            if (!visited[j] && dist[curr][j] < min) {
                min = dist[curr][j];
                next = j;
            }
        }
        approx_cost += min;
        visited[next] = 1;
        curr = next;
    }
    approx_cost += dist[curr][1];

    printf("\nOptimal Cost: %d", optimal_cost);
    printf("\nApproximation Cost (Nearest Neighbor): %d", approx_cost);
    printf("\nError: %d", approx_cost - optimal_cost);
    return 0;
}