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

int main()
{
    int A[] = {2,4,5,6,7,8};
    int array_size = sizeof(A)/sizeof(A[0]);
    Create(A, array_size);
    Display(first);
    printf("Length of LinkedList: %d\n", Length(first));
}
