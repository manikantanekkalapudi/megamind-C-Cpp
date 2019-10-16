#include <stdio.h>
#include<stdlib.h>
struct UpperTriangularMatrix
{
    int *A;
    int n;
};

void Set(struct UpperTriangularMatrix *m, int i, int j, int x)
{
    if(i >= j)
    {
        m->A[i*(i-1)/2+j-1] = x;
    }
}

int Get(struct UpperTriangularMatrix m, int i, int j)
{
    if(i >= j)
    {
        return m.A[i*(i-1)/2+j-1];
    }
    else
    {
        return 0;
    }
    
}

void Display(struct UpperTriangularMatrix m)
{
    int i, j;

    for(i=1; i<=m.n; i++)
    {
        for(j=1; j<=m.n; j++)
        {
            if(i >= j)
            {
                printf("%d ", m.A[i*(i-1)/2+j-1]);
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
    struct UpperTriangularMatrix mat;
    int i,j,x;
    printf("Enter Dimension fo the matrix: ");
    scanf("%d", &mat.n);

    mat.A = (int *)malloc(mat.n*(mat.n-1)/2*sizeof(int));

    printf("Enter all the elements:\n");

    for(i=1; i<=mat.n; i++)
    {
        for(j=1; j<=mat.n; j++)
        {
            scanf("%d", &x);
            Set(&mat, i, j, x);
        }
    }
    
    printf("\n\n");
     
    Display(mat);
}