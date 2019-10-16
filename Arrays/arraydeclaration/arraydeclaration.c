#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[5] = {1,2,3,4,5};
    int *P;
    int i;

    P = (int *)malloc(5*sizeof(int));
    P[0] = 3;
    P[1] = 5;
    P[2] = 7;
    P[3] = 9;
    P[4] = 11;

    for(i=0; i<5; i++)
    {
        printf("A: %d\n", A[i]);
        printf("P: %d\n", P[i]);
    }
    return 0;
}
