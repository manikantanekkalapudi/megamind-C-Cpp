#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*Head;

void Create(int A[], int n)
{
    struct Node *p, *last;
    int i=0;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->next = Head;
    Head->data = A[0];
    Head->prev = Head;
    last = Head;

    for(i=1; i<n; i++)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->prev = last;
        p->data = A[i];
        p->next = last->next;
        last->next = p;
        Head->prev = p;
        last=p;
    }
}

void Display(struct Node *p)
{
    do
    {
        printf("%d ",p->data);
        p = p->next;
    } while (p != Head);
    printf("\n");
}

int Length(struct Node *p)
{
    int len = 0;
    do
    {
        len += 1;
        p = p->next;
    } while (p != Head);
    return len;   
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *q;
    int i;
    if(index <1 || index > Length(p))
    {
        return;
    }
    if(index == 1)
    {
        q = (struct Node *)malloc(sizeof(struct Node));
        q->data = x;
        q->prev = p->prev;
        q->next = p;
        Head->prev = q;
        q->prev->next = q;
        Head = q;
    }
    else
    {
        for(i=1; i<index; i++)
        {
            p = p->next;
        }
        q = (struct Node *)malloc(sizeof(struct Node));
        q->data = x;
        q->next = p->next;
        q->prev = p;
        p->next->prev = q;
        p->next = q;
    }
}

int Delete(struct Node *p, int index)
{
    int x=-1, i;
    if(index<1 || index>Length(p))
    {
        return -1;
    }
    if(index == 1)
    { 
        Head = Head->next;
        Head->prev = p->prev;
        Head->prev->next = Head;
        x = p->data;
        free(p);
    }
    else
    {
        for(i=1; i<index; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        x = p->data;
        free(p);
    }
    return x;
}

int main()
{
    int A[] = {1,2,3,4,5};
    Create(A,5);
    Display(Head);
    Insert(Head,1,6);
    Display(Head);
    Insert(Head,6,7);
    Display(Head);
    printf("Deleted Item: %d\n", Delete(Head,7));
    Display(Head);
}