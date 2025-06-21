#include <stdio.h>
#include <stdlib.h>

int size = 0;

struct Queue
{
    int data;
    struct Queue *next;
} *front = NULL, *rear = NULL;

void enqueue(int data)
{
    struct Queue *new_node = (struct Queue *)malloc(sizeof(struct Queue));
    new_node->data = data;
    new_node->next = NULL;

    if (rear == NULL)
    {
        front = rear = new_node;
        size++;
        return;
    }
    rear->next = new_node;
    rear = new_node;
    size++;
}

int dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int data = front->data;
    struct Queue *temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL; // If the queue is now empty
    free(temp);
    size--;
    return data;
}

void display()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct Queue *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("Dequeued: %d\n", dequeue());
    display();

    printf("Dequeued: %d\n", dequeue());
    display();

    printf("Dequeued: %d\n", dequeue());
    display();
}