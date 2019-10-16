#include <stdio.h>
#include <stdlib.h>

void fun(int n)
{
    if(n>0)
    {
        printf("%d\n", n);
        fun(n-1);
        fun(n-1);
    }
}
int main()
{
    fun(3);
    printf("Hello world!\n");
    return 0;
}
