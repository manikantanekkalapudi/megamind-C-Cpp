#include <stdio.h>

struct Matrix
{
    int A[10];
    int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
    if(i == j)
    {
        m->A[i-1] = x;
    }
}

int Get(struct Matrix m, int i, int j)
{
    if(i == j)
    {
        return m.A[i-1];
    }
    else
    {
        return 0;
    }
    
}

void Display(struct Matrix m)
{
    int i, j;

    for(i=0; i<m.n; i++)
    {
        for(j=0; j<m.n; j++)
        {
            if(i == j)
            {
                printf("%d ", m.A[i]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix mat;
    mat.n=4; //4*4 matrix

    //Setting diagonal values for the matrix using 1D array
    Set(&mat, 1,1,3);
    Set(&mat, 2,2,5);
    Set(&mat, 3,3,7);
    Set(&mat, 4,4,9);

    printf("%d\n", Get(mat, 1,1));
     
    Display(mat);
}