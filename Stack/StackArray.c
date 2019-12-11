#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int Size;
    int Top;
    int *s;
};

void Create(struct Stack *st)
{
    printf("Enter Stack size: ");
    scanf("%d",&st->Size);
    st->Top = -1;
    st->s = (int *)malloc(sizeof(int)*st->Size);
}

void Display(struct Stack st)
{
    int i;
    for(i=st.Top; i>=0; i--)
    {
        printf("%d ",st.s[i]);
    }
    printf("\n");
}

void Push(struct Stack *st, int x)
{
    if(st->Top == st->Size-1)
    {
        printf("\nStack Overflow!\n");
    }
    else
    {
        st->Top += 1;
        st->s[st->Top] = x;
    }
}

int Pop(struct Stack *st)
{
    int x = -1;
    if(st->Top == -1)
    {
        printf("\nStack Underflow!\n");
    }
    else
    {
        x = st->s[st->Top--];
    }
    return x;
}

int Peek(struct Stack *st, int index)
{
    int x = -1;
    if(st->Top-index+1 < 0)
    {
        printf("\nInvalid Position\n");
    }
    else
    {
        x = st->s[st->Top-index+1];
    }
    return x;
}

int StackTop(struct Stack *st)
{
    if(st->Top == -1)
    {
        return -1;
    }
    else
    {
        return st->s[st->Top];
    }
}

int isEmpty(struct Stack *st)
{
    if(st->Top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Stack *st)
{
    if(st->Top == st->Size-1)
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
    struct Stack st;
    Create(&st);
    Push(&st, 8);
    Push(&st, 3);
    Push(&st, 2);
    Push(&st, 4);
    Push(&st, 6);
    // Push(&st, 0);
    Display(st);
    // printf("Popped value %d: \n", Pop(&st));
    // printf("Popped value %d: \n", Pop(&st));
    // printf("Popped value %d: \n", Pop(&st));
    // printf("Popped value %d: \n", Pop(&st));
    // printf("Popped value %d: \n", Pop(&st));
    // printf("Popped value %d: \n", Pop(&st));
    
    printf("isEmpty: %d\n",isEmpty(&st));
    printf("isFull: %d\n",isFull(&st));
    printf("Peeked value: %d\n",Peek(&st, 1));
    // printf("Peeked value: %d\n",Peek(&st, 6));
}