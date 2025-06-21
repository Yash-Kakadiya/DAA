#include <stdio.h>
#include <stdlib.h>

int size = 0;

struct Stack
{
    int data;
    struct Stack *next;
} *top = NULL;

void push(int data)
{
    struct Stack *new_node = (struct Stack *)malloc(sizeof(struct Stack));
    new_node->data = data;
    new_node->next = NULL;

    if (top == NULL)
    {
        top = new_node;
        size++;
        return;
    }
    new_node->next = top;
    top = new_node;
    size++;
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack is empty");
        return -1;
    }
    int data = top->data;
    top = top->next;
    size--;
    return data;
}

int peek()
{
    if (top == NULL)
    {
        printf("Stack is empty");
        return -1;
    }
    return top->data;
}

int peep(int i)
{
    if (i > size)
    {
        printf("Index out of bounds");
        return -1;
    }

    struct Stack *temp = top;
    while (i > 1)
    {
        temp = temp->next;
        i--;
    }
    return temp->data;
}

void printStack()
{
    struct Stack *temp = top;
    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
}

void main()
{
    push(1);
    push(2);
    push(3);

    printStack();
    printf("\n%d", peek());

    printf("\n%d", peep(3));
}