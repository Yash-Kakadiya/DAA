#include <stdio.h>
#include <stdlib.h>

int size = 0;

struct Node
{
    int data;
    struct Node *next;
} *head = NULL, *tail = NULL;

void insert(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = tail = new_node;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
    }
    size++;
}

void delete(int data)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;

    while (temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Element not found\n");
        return;
    }

    if (prev == NULL)
    {
        head = temp->next; // Deleting the head
    }
    else
    {
        prev->next = temp->next;
    }

    if (temp == tail)
    {
        tail = prev;
    }

    free(temp);
    size--;
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
    insert(10);
    insert(20);
    insert(30);
    printf("List after insertion: ");
    display();

    delete(20);
    printf("List after deleting 20: ");
    display();

    delete(10);
    printf("List after deleting 10: ");
    display();

    delete(30);
    printf("List after deleting 30: ");
    display();

    delete(40);
}