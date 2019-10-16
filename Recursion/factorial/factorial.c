#include <stdio.h>
#include <stdlib.h>

int fact(int n)
{
    if(n<0)
    {
        printf("Provide a positive input");
    }
    else if(n==0)
    {
        return 1;
    }
    else
    {
        return fact(n-1)*n;
    }
}

int main()
{
    int r;
    r = fact(-5);
    printf("Factorial is: %d\n", r);

    return 0;
}
