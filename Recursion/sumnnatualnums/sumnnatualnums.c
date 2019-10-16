#include <stdio.h>
#include <stdlib.h>

int sumnums(int n)
{
    if(n<=0)
    {
        return n;
    }
    else
    {
        return sumnums(n-1)+n;
    }
}

int Isum(int n)
{
    int s = 0;
    int i;

    for(i=0; i<=n; i++)
    {
        s += i;
    }

    return s;
}

int main()
{
    int r;

    r = sumnums(5);
    printf("%d\n", r);
    r = Isum(5);
    printf("%d\n", r);
    return 0;
}
