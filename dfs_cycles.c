#include <stdio.h>

#define V 4

void dfs_cycles(int g[V][V], int visited_arr[], int in_current_stack[], int source, int parent)
{
    visited_arr[source] = 1;
    in_current_stack[source] = 1;

    for (int neighbor = 0; neighbor < V; neighbor++) {
        if (neighbor == source) continue;
        if (g[source][neighbor] > 0) {
            if (!visited_arr[neighbor]) {
                dfs_cycles(g, visited_arr, in_current_stack, neighbor, source);
            } else if ((in_current_stack[neighbor]) && (neighbor !=parent)) {
                printf("Cycle Detected: %d, %d\n", neighbor, parent);
            }
        }
    }

    in_current_stack[source] = 0;
    return;
}

void main()
{
    int g[V][V] = {
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 1},
        {0, 1, 1, 0}
    };

    int visited_arr[V];
    int in_current_stack[V];

    for (int i = 0; i < V; i++) {
        visited_arr[i] = 0;
        in_current_stack[i] = 0;
    }

    for (int i = 0; i < V; i++) {
        if (visited_arr[i] == 0) {
            dfs_cycles(g, visited_arr, in_current_stack, i, -1);
        }
    }

    return;
}
