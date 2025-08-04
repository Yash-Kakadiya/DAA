#include <stdio.h>
#define V 8

int queue[V];
int front = -1, rear = -1;
int visited[V] = {0};

void enqueue(int value)
{
    if (rear == V - 1)
    {
        printf("Queue is full\n");
        return;
    };
    if (front == -1)
    {
        front = 0;
    };
    queue[++rear] = value;
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return -1;
    };
    return queue[front++];
}

void printQueue()
{
    int i = front;
    while (i <= rear)
    {
        printf("%d ", queue[i++]);
    }
}

void bfs(int graph[V][V])
{
    visited[0] = 1;
    enqueue(0);

    while (front <= rear)
    {
        int vertex = dequeue();
        printf("%d ", vertex+1);

        for (int i = 0; i < V; i++)
        {
            if (graph[vertex][i] == 1 && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
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

    bfs(graph);
}