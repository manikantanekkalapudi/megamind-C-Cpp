#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<stdbool.h>

struct Node
{
    int data; // Data stored in the node
    struct Node *next; // Self-referential pointer to point next node in the linked list
}*first=NULL,*second=NULL,*third=NULL; //These become global pointers

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node)); // Creating first node 
    first->data = A[0]; // Assigning 0th array index value to first node in the Linked List
    first->next = NULL; // first node's next will point to next node
    last = first; // last node will point to first node.

    // for loop to access all the elements in the array from index 1 to n
    for(i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node *)); // Creating a temp node in head for each value in the array
        t->data = A[i]; // Assigning temp node's data with array element
        t->next = NULL; // Assigning temp node's next to NULL
        last->next = t; // Previous last node's next will be assigned to temp node
        last = t; // last node is moved to t node
    }
}
void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for(i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node *)); 
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}



void Display(struct Node *p)
{
    // Iterate through the Linked List as long as p is not NULL using a while loop
    while(p != NULL)
    {
        printf("%d->",p->data); // Print the data.
        p=p->next; // p pointing to next node of p
    }
}

int count(struct Node *p)
{
    int len = 0; // Initial length is assigned to 0
    // Iterate through the Linked List as long as p is not NULL using a while loop
    while(p != NULL)
    {
        len++; // Increment len by 1 for each node
        p = p->next; // move p to nxt node
    }
    return len;
}

int Add(struct Node *p)
{
    int sum = 0;
    while(p != NULL)
    {
        sum+=p->data;
        p = p->next;
    }
    return sum;
}

int Max(struct Node *p)
{
    int max = INT_MIN;
    while (p != NULL)
    {
        if(p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max; 
}

int Min(struct Node *p)
{
    int min = INT_MAX;
    while (p != NULL)
    {
        if(p->data < min)
        {
            min = p->data;
        }
        p = p->next;
    }
    return min;
    
}

struct Node * linearSearchMovetoHead(struct Node *p, int key) // linear search with move to first improvement
{
    struct Node *q = NULL;
    while(p != NULL)
    {
        if(key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    if(index < 0 || index > count(p))
    {
        return;
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else if(index > 0)
    {
        int i;
        p = first;
        for(i=0; i<index-1 && p; i++)
        {
            p = p->next;
        }
        if(p != NULL)
        {
            t->next = p->next;
            p->next = t;
        }
    }
    
}

void InsertLast(int x)
{
    struct Node *p, *last;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = x;
    p->next = NULL;

    if(p == NULL)
    {
        first = last = p;   
    }
    else
    {
        last->next = p;
        last = p;
    }
}

void InsertinSortedLinkedList(struct Node *p, int x)
{
    struct Node *t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if(first == NULL)
    {
        first = t;
    }
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p = p->next;
        }
        if(p==first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = p->next;
            q->next = p;
        }
        
    }
    
}

int Delete(struct Node *p, int index)
{
    struct Node *q;
    int x = -1, i = 0;

    if(index < 1 || index > count(p))
    {
        return -1;
    }
    if(index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for(i=0; i<index; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

int isSorted(struct Node *p)
{
    int x = INT_MIN;
    while( p != NULL)
    {
        if(p->data < x)
        {
            return false;
        }
        x = p->data;
        p = p->next;
    }
    return true;
}

void removeDuplicate(struct Node *p)
{
    struct Node *q = first->next;

    while(q != NULL)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
        
        
    }

    
}

void reverseLinkedListbyValues(struct Node *p)
{
    int *A, i=0;
    struct Node *q = p;

    A = (int *)malloc(sizeof(int)*count(p));

    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while(q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void Reverse(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while(p != NULL)
    {
        r = q; // moving r to q's node
        q = p; // moving q to p's node
        p = p->next; // moving p to next node
        q->next = r; // pointing q node link to r node in backward direction
    }
    first = q;
}

void RecReverse(struct Node *q, struct Node *p)
{
    if(p != NULL)
    {
        RecReverse(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
    
}

void Concat(struct Node *p, struct Node *q)
{
    third = p;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if(p->data < q->data)
    {
        last=third=p;
        p=p->next;
        third->next = NULL; 
    }
    else
    {
        last=third=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next; 
            last->next = NULL;
        }
        
    }
    if(p != NULL)
    {
        last->next = p;
    }
    if(q != NULL)
    {
        last->next = q;
    }
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
int main()
{
    int A[] = {10,20,30,40,50};
    int B[] = {15,25,35,45,55};
    struct Node *temp, *t1, *t2;
    create(A,5);
    create2(B,5);
    // printf("The no. of elements is %d\n\n", count(first));
    // printf("The sum of elements is %d\n\n", Add(first));
    // printf("The max element in the list is %d\n\n", Max(first));
    // printf("The min element in the list is %d\n\n", Min(first));
    // temp = linearSearchMovetoHead(first, 6);
    // temp = linearSearchMovetoHead(first, 2);
    // if(temp != NULL)
    // {
    //     printf("Key is found %d\n\n",temp->data);
    // }
    // else
    // {
    //     printf("Key is not found!");
    // }
    // Display(first);
    // insert(first,2,9);
    // Display(first);
    // // InsertLast(77);
    // InsertinSortedLinkedList(first, 3);
    // Display(first);
    // printf("Deleted element %d\n",Delete(first,2));
    // printf("is sorted? %d\n", isSorted(first));
    // removeDuplicate(first);
    // Display(first);
    // printf("Reverse by values\n");
    // reverseLinkedListbyValues(first);
    // Display(first);
    // printf("Reverse by links\n");
    // Reverse(first);
    // Display(first);

    // temp = NULL;
    // printf("Recuring Reverse\n");
    // RecReverse(NULL, first); 
    // Display(first);
    // return 0;

    // Concat(first,second);
    // printf("Concatinated:\n\n");
    // Display(third);
    Merge(first,second);
    Display(third);
    
    printf("\nisLoop: %d\n", isLOOP(first));

    // t1 = first->next->next;
    // t2 = first->next->next->next->next;
    // t2->next = t1;
    // printf("\nisLoop: %d\n", isLOOP(first));
}