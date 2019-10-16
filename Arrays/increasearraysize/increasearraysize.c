#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p,*q;
    int i;

    p = (int *)malloc(5*sizeof(int));

    p[0]=1; p[1]=3; p[2]=4; p[3]=5; p[4]=12;

    for(i=0; i<5; i++)
    {
        printf("%d\n",p[i]);
    }

    q = (int *)malloc(10*sizeof(int));

    for(i=0; i<10; i++)
    {
        q[i] = p[i];
    }

    for(i=0; i<10; i++)
    {
        printf("%d\n",p[i]);
    }

    free(p);

    p = q;

    q = NULL;

    return 0;
}
