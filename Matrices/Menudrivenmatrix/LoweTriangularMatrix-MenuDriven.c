#include <stdio.h>
#include<stdlib.h>
struct LowerTriangularMatrix
{
    int *A;
    int n;
};

void Set(struct LowerTriangularMatrix *m, int i, int j, int x)
{
    if(i >= j)
    {
        m->A[i*(i-1)/2+j-1] = x;
    }
}

void Create(struct LowerTriangularMatrix *m){
    int x, i=0, j=0;
    printf("Enter all the elements:\n");

    for(i=1; i<=m->n; i++)
    {
        for(j=1; j<=m->n; j++)
        {
            scanf("%d", &x);
            Set(&m, i, j, x);
        }
    }
    printf("\n\n");
}

int Get(struct LowerTriangularMatrix m, int i, int j)
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

void Display(struct LowerTriangularMatrix m)
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
    struct LowerTriangularMatrix mat;
    int i,j,x, choice;
    printf("Enter Dimension fo the matrix: ");
    scanf("%d", &mat.n);

    mat.A = (int *)malloc(mat.n*(mat.n-1)/2*sizeof(int));

    do
    {
        printf("1. Create Array");
        printf("2. Set");
        printf("3. Get");
        printf("4. Display");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Create(&mat);
            break;
        case 2:
            Set(&mat, 1, 0, 5);
            break;
        case 3:
            printf("%d", Get(mat, 3, 3));
            break;
        case 4:
            Display(mat);
            break;
        default:
            break;
        }
    }while (choice<5);

}