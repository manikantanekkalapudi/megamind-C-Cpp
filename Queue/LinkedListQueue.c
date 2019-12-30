#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front=NULL, *rear=NULL;

void enqueue(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL)
    {
        printf("\nQueue Overflow!\n");
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
        
    }
    
}

int dequeue()
{
    int x = -1;
    struct Node *q;
    if(front == NULL)
    {
        printf("\nQueue Underflow!\n");
    }
    else
    {
        x = front->data;
        q = front;
        front = front->next;
        free(q);
    }
    return x;
}

void Display()
{
    struct Node *p = front;

    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    enqueue(9);
    enqueue(8);
    enqueue(7);
    enqueue(6);
    Display();
    printf("Dequeued element: %d\n",dequeue());
    Display();
    return 0;
}