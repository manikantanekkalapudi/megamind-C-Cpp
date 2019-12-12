#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*Top =NULL;

void push(int x)
{
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));

    if(p==NULL)
    {
        printf("\nStack Overflow\n");
    }
    else
    {
        p->data = x;
        p->next = Top;
        Top = p;
    }
}

int pop()
{
    struct Node *p = Top;
    int x = -1;
    if(Top == NULL)
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        Top = Top->next;
        x = p->data;
        free(p);
    }
    return x;
}

void Display()
{
    struct Node *p = Top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    push(10);
    push(15);
    Display();
    printf("Popped Element: %d\n", pop());
}