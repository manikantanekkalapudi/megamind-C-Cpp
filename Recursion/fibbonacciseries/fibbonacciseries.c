#include <stdio.h>
#include <stdlib.h>

int loop_fib(int n)
{
    int t0 = 0, t1 = 1, s = 0 , i;

    if(n <= 1)
    {
        return n;
    }
    for(i=2; i<=n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int rec_fib(int n)
{
    if(n <= 1)
    {
        return n;
    }

    return rec_fib(n-1) + rec_fib(n-2);
}

int F[10];
int mem_fib(int n)
{
    if(n<=1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if(F[n-2] == -1)
        {
            F[n-2] = mem_fib(n-2);
        }

        if(F[n-1] == -1)
        {
            F[n-1] = mem_fib(n-1);
        }
        F[n] = F[n-1] + F[n-2];
        return F[n-1] + F[n-2];
    }
}


int main()
{
    printf("%d\n", loop_fib(10));
    printf("%d\n", rec_fib(6));
    int i;
    for(i=0; i<10; i++)
    {
        F[i] = -1;
    }

    printf("%d\n", mem_fib(10));
    return 0;
}
