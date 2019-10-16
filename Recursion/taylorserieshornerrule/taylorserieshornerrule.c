#include <stdio.h>
#include <stdlib.h>

double e(int x, int n)
{
    static double s = 1;
    if(n == 0)
    {
        return s;
    }
    else
    {
        s = 1 + x * s/n;
        return e(x, n-1);
    }
}

int main()
{
    printf("%1f\n", e(3,10));
    return 0;
}
