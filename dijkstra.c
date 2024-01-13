/*
Author: https://github.com/ravikumark815

------- Dijkstra's Algorithm -------
*/

#include <stdio.h>
#include <limits.h>

#define V 9

void dijkstra(int g[V][V], int s) {
    int visit[V];
    int dist[V];
    
    for (int i=0; i<V; i++) {
        visit[i] = 0;
        dist[i] = INT_MAX;
    }

    dist[s] = 0;

    for (int i=0; i<V; i++) {
        int u, u_dist = INT_MAX;

        for (int j=0; j<V; j++) {
            if ((!visit[j]) && (u_dist >= dist[j])) {
                u_dist = dist[j];
                u = j;
            }
        }
        
        visit[u] = 1;
        for (int j=0; j<V; j++) {
            if((!visit[j]) &&  //Not visited Before
                (g[u][j]) &&  //An edge exists
                ((dist[u] + g[u][j]) < dist[j]) // stov + utov is less than stov
            )
            dist[j] = dist[u] + g[u][j];
        }
    }

    printf("Result:\n");
    for (int i=0; i<V; i++)
        printf("%d---%d: %d\n", s, i, dist[i]);
    return;
}

void main()
{
    int g[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                    { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                    { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                    { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                    { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                    { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                    { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                    { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                    { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    dijkstra(g, 0);
    return;
}