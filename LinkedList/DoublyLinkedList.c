#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void Create(int A[], int n)
{
    struct Node *p, *last;
    int i;
    
    first = (struct Node *)malloc(sizeof(struct Node));
    first->prev = NULL;
    first->data=A[0];
    first->next = NULL;
    last = first;

    for(i=1; i<n; i++)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = A[i];
        p->next = last->next;
        p->prev = last;
        last->next = p;
        last = p;

    }
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int Length(struct Node *p)
{
    int len = 0;
    while (p != NULL)
    {
        len += 1;
        p = p->next;
    }
    return len;
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *q;
    int i;
    if(index <0 || index > Length(p))
    {
        return;
    }
    if(index == 0)
    { 
        q = (struct Node *)malloc(sizeof(struct Node));
        q->data = x;
        q->prev = NULL;
        q->next = first;
        first->prev = q;
        first = q;
    }
    else
    {
        for(i=0; i<index-1; i++)
        {
            p = p->next;
        }
        q = (struct Node *)malloc(sizeof(struct Node));
        q->data = x;
        q->next = p->next;
        q->prev = p;
        if(p->next != NULL)
        {
            p->next->prev = q;
        }
        p->next = q;
    }
}

int Delete(struct Node *p, int index)
{
    int x=-1, i;
    if(index <0 || index > Length(p))
    {
        return -1;
    }
    if(index == 1)
    {
        first = first->next;
        if(first != NULL)
        {
            first->prev = NULL;
        }
        x = p->data;
        free(p);
    }
    else
    {
        for(i=0; i<index-1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if(p->next != NULL)
        {
            p->next->prev = p->prev;
        }
        x = p->data;
        free(p);
    }
    return x;
}

void Reverse(struct Node *p)
{
    struct Node *temp;
    while(p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p != NULL && p->next == NULL)
        {
            first = p;
        }
    }
}

int main()
{
    int A[] = {2,4,5,6,7,8};
    int array_size = sizeof(A)/sizeof(A[0]);
    Create(A, array_size);
    Display(first);
    printf("Length of LinkedList: %d\n", Length(first));
    Insert(first, 1, 9);
    Display(first);
    printf("Deleted: %d\n",Delete(first,array_size+1));
    Display(first);
    Reverse(first);
    Display(first);
}
