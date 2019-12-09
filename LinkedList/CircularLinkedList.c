#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*Head;

void Create(int A[], int n)
{
    struct Node *t, *last;
    int i = 0;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for(i=1; i<n; i++)
    {
        t = (struct Node *)malloc(n*sizeof(struct Node)); // Creating the node
        t->data = A[i]; // Assigning the data in the array to the node
        t->next = last->next; // Pointing node's next to last node's next node, i.e., Head node
        last->next=t; // Pointing last node's next link to node t
        last=t; // Finally, moving the last pointer to new node
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

int Length()
{
    int len;
    struct Node *p = Head;
    do
    {
        len += 1;
        p = p->next;

    } while (p != Head);
    return len;
}

void RDisplay(struct Node *p)
{
    static int flag = 0;
    if(p != Head || flag == 0)
    {
        flag = 1;
        printf("%d ",p->data);
        RDisplay(p->next);
    }
    flag = 0;
    printf("\n");
}

int isLOOP(struct Node *first)
{
    struct Node *p, *q;
    p = q = first;
    do
    {
        p = p->next;
        q = q->next;
        if(q != NULL)
        {
            q = q->next;
        }
    } 
    while(p != NULL && q != NULL && p != q);
    if(p == q)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *q; //q->to create a temp node; p(Head)->traverse the LinkedList
    int i; // to traverse to a certain node for insert operation
    /*
    1. Insert before Head or Insert after last node
    2. Insert at any given indexition -> same as insert operation in linear LinkedList
    */
   if(index == 0)
   {
       q = (struct Node *)malloc(sizeof(struct Node));
       q->data = x;
       if(Head == NULL)
       {
           Head == NULL;
           Head->next = Head;
       }
       else
       {
           while(p->next != NULL)
           {
               p = p->next;
           }
           p->next = q;
           q->next = Head;
           Head = q; //This is optional
       }   
   }
   else
   {
       if(index < 1 || index > Length())
       {
           return;
       }
       q = (struct Node *)malloc(sizeof(struct Node));
       q->data = x;
       for(i=0; i<index-1; i++)
       {
           p = p->next;
       }
       q->next = p->next;
       p->next = q;
   }
    
}

int Delete(struct Node *p, int index)
{
    struct Node *q; //p-> pointing to the node before the index; q->pointing to the node to be deleted
    int i, x;

    if(index <= 1 || index > Length())
    {
        return -1;
    }
    if(index == 1)
    {
        while(p->next != Head)
        {
            p = p->next;
        }
        x = Head->data;
        if(p == Head)
        {
            free(p);
            Head = NULL;
        }
        else
        {
            p->next = Head->next;
            free(Head);
            Head = p->next;
        }
    }
    else
    {
        for(i=0; i<index-2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }

    return x;
    
}

int main()
{
    int A[] = {1,2,3,4,5};
    Create(A,5);
    Display(Head);
    RDisplay(Head);
    // printf("\nisLoop: %d\n", isLOOP(Head));
    Insert(Head, 2, 33);
    Display(Head);
    printf("Deleted element :%d \n", Delete(Head, 2));
    Display(Head);
    return 0;
}