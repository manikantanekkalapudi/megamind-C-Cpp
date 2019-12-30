#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int *) malloc(q->size*sizeof(int));
}

void enqueue(struct Queue *q, int x)
{
    if((q->rear+1)%q->size == q->front)
    {
        printf("\nQueue Overflow!\n");
    }
    else
    {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->front == q->rear)
    {
        printf("\nQueue Underflow!\n");
    }
    else
    {
        q->front = (q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q)
{
    int i;
    for(i=q.front+1; i<=q.rear;i++)
    {
        printf("%d ",q.Q[i]);
    }
    printf("\n");
}
int main()
{
    struct Queue q;
    create(&q, 5);

    enqueue(&q,5);
    enqueue(&q,6);
    enqueue(&q,7);
    enqueue(&q,8);
    enqueue(&q,9);
    Display(q);
    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));
    return 0;
}