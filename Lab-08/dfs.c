#include <stdio.h>;
#define V 8

int visited[V] = {0};
void dfs(int graph[V][V])
{
    dfsHelper(graph, visited, 0);
}

void dfsHelper(int graph[V][V], int visited[], int vertex)
{
    visited[vertex] = 1;
    printf("%d ", vertex + 1);
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0 && graph[vertex][i])
        {
            dfsHelper(graph, visited, i);
        }
    }
}

void main()
{
    int graph[V][V] =
        {
            // 0  1  2  3  4  5  6
            {0, 1, 1, 0, 0, 0, 0}, // Node 0
            {0, 0, 0, 1, 0, 0, 0}, // Node 1
            {0, 0, 0, 1, 0, 0, 0}, // Node 2
            {0, 0, 0, 0, 1, 0, 0}, // Node 3
            {0, 0, 0, 0, 0, 1, 0}, // Node 4
            {0, 0, 0, 0, 0, 0, 1}, // Node 5
            {0, 0, 0, 0, 1, 0, 0}  // Node 6
        };

    dfs(graph);
}