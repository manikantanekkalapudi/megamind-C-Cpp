#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Created inside stack
    int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};

    //Array of pointers created inside stack
    int *b[3];

    //Double pointer to implement 2D Array in Heap
    int **c;

    int i, j;

    //These individual arrays are created in heap
    b[0] = (int *)malloc(3*sizeof(int));
    b[1] = (int *)malloc(3*sizeof(int));
    b[2] = (int *)malloc(3*sizeof(int));

    //rows are created in heap
    c = (int **)malloc(3*sizeof(int *));
    //Arrays are created in heap as well
    c[0] = (int *)malloc(3*sizeof(int));
    c[1] = (int *)malloc(3*sizeof(int));
    c[2] = (int *)malloc(3*sizeof(int));

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
