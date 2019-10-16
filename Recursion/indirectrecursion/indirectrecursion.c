#include <stdio.h>
#include <stdlib.h>


void funB(int n);

void funA(int n)
{
    if(n>0)
    {
        printf("A: %d\n", n);
        funB(n-1);
    }
}

void funB(int n)
{
    printf("B: %d\n", n);
    funA(n/2);

}

int main()
{
    funA(20);
    return 0;
}
