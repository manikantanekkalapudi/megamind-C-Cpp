#include <stdio.h>
#include <stdlib.h>

// nCr

int fact(int n)
{
    if(n == 0)
    {
        return 1;
    }
    return fact(n-1) * n;
}

int nCr(int n, int r)
{
    int num, den;

    num = fact(n);
    den = fact(r) * fact(n-r);

    return num/den;
}

int rec_nCr(int n, int r)
{
    if(r == 0 || n == r)
    {
        return 1;
    }
    else
    {
    return rec_nCr(n-1, r-1) + rec_nCr(n-1, r);
    }
}
int main()
{
    printf("%d\n", nCr(4,2));
    printf("%d\n", rec_nCr(4,2));
    return 0;
}
