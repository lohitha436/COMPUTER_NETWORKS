#include <stdio.h>

#define INF 99
#define MAX 10

int main() {
    int n, cost[MAX][MAX], dist[MAX], visited[MAX], parent[MAX];
    int i, j, count, u, v, min;

    printf("Enter number of routers: ");
    scanf("%d", &n);

    // Input cost matrix
    printf("Enter the cost adjacency matrix (use 99 for no link):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    int src;
    printf("Enter source router (0-%d): ", n - 1);
    scanf("%d", &src);

    // Initialization
    for (i = 0; i < n; i++) {
        dist[i] = cost[src][i];
        parent[i] = src;
        visited[i] = 0;
    }
    dist[src] = 0;
    visited[src] = 1;

    // Dijkstra’s algorithm
    for (count = 1; count < n - 1; count++) {
        min = INF;
        for (i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }
        visited[u] = 1;

        for (v = 0; v < n; v++) {
            if (!visited[v] && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
                parent[v] = u;
            }
        }
    }

    // Display shortest paths
    printf("\nShortest paths from Router %c:\n", 'A' + src);
    for (i = 0; i < n; i++) {
        if (i != src) {
            printf("To %c: Cost = %d, Path = %c", 'A' + i, dist[i], 'A' + i);
            j = i;
            while (parent[j] != src) {
                printf(" <- %c", 'A' + parent[j]);
                j = parent[j];
            }
            printf(" <- %c\n", 'A' + src);
        }
    }
    return 0;
}
