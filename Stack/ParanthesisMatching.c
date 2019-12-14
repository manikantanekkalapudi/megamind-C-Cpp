#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
}*Top =NULL;

void push(char x)
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

char pop()
{
    struct Node *p = Top;
    char x = -1;
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

int isBalanced(char *exp)
{
    int i=0;

    for(i=0; exp[i]!='\0'; i++)
    {
        if(exp[i] == '(')
        {
            push(exp[i]);
        }
        else if(exp[i] == ')')
        {
            if(Top == NULL)
            {
                return 0;
            }
            pop();
        }
    }
    if(Top == NULL)
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
    char *exp = "((a+b)*(c-d)))";
    printf("isBalanced: %d\n", isBalanced(exp));
}