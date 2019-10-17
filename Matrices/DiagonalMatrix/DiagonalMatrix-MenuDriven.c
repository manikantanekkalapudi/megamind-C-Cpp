#include <stdio.h>
#include<stdlib.h>

struct DiagonalMatrix
{
    int *A;
    int n;
};


void Create(struct DiagonalMatrix *m, int n)
{
    int i;
    printf("Enter all the elements: ");
    for(i=0; i<=n; i++)
    {
        scanf("%d", &m->A[i]);
    }
}

int Get(struct DiagonalMatrix m, int i, int j)
{

    if(i == j)
    {
        return m.A[i];
    }
    else
    {
        return 0;
    }
    
}

void Set(struct DiagonalMatrix *m, int i, int j, int x)
{
    if(i == j)
    {
        m->A[i] = x;
    }
}


void Display(struct DiagonalMatrix m)
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
    struct DiagonalMatrix mat;
    int i,j,x, choice;
    printf("Enter Dimension fo the matrix: ");
    scanf("%d", &mat.n);

    mat.A = (int *)malloc(mat.n*(mat.n-1)/2*sizeof(int));
    
    do
    {
        printf("\n1. Create Array\n");
        printf("2. Set\n");
        printf("3. Get\n");
        printf("4. Display\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Create(&mat, mat.n);
            break;
        case 2:
            printf("Enter row number: ");
            scanf("%d", &i);
            printf("Enter col number: ");
            scanf("%d", &j);
            printf("Enter element to be entered: ");
            scanf("%d", &x);
            Set(&mat, i, j, x);
            break;
        case 3:
            printf("Enter row number: ");
            scanf("%d", &i);
            printf("Enter col number: ");
            scanf("%d", &j);
            printf("%d", Get(mat, i, j));
            break;
        case 4:
            Display(mat);
            break;
        }
    }while (choice<5);
    

}