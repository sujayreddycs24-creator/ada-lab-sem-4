#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue implementation
int queue[MAX], front = 0, rear = -1;

void enqueue(int v) {
    queue[++rear] = v;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

int main() {
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n], indegree[n];
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v) meaning u -> v:\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        adj[u][v] = 1;
        indegree[v]++;
    }

    // Enqueue vertices with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    printf("\nTopological Ordering: ");
    int count = 0;
    while (!isEmpty()) {
        int v = dequeue();
        int s=v;
        printf("%d ", ++s);
        count++;

        for (int i = 0; i < n; i++) {
            if (adj[v][i]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    if (count != n) {
        printf("\nGraph has a cycle, topological ordering not possible.\n");
    }

    return 0;
}
