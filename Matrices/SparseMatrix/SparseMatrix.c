#include <stdio.h>
#include <stdlib.h>
struct Element
{
    int i; // row no. of the element
    int j; // col no. of the element
    int x; // value to store
};

struct SparseMatrix
{
    int m; // no. of rows in the sparse matrix
    int n; // no. of cols in the sparse matrix
    int num; //no. of non-zero elements in the sparse matrix
    struct Element *ele; // Element pointer to create and array of non-zero elements
};

void CreateSparseMatrix(struct SparseMatrix *s)
{
    int i;
    printf("Enter Dimensions:\n");
    scanf("%d%d",&s->m, &s->n);
    printf("Enter no. of non-zero elements:\n");
    scanf("%d",&s->num);
    s->ele=(struct Element *)malloc(s->num * sizeof(struct Element));
    printf("Enter all the non-zero elements starting with row and column nums:\n");
    for(i=0; i<s->num; i++)
    {
        scanf("%d%d%d",&s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
    }
}

void DisplaySparseMatrix(struct SparseMatrix s)
{
    int i,j,k=0;
    for(i=0; i<s.m; i++)
    {
        for(j=0; j<s.n; j++)
        {
            if(i==s.ele[k].i && j==s.ele[k].j)
            {
                printf("%d ", s.ele[k++].x);
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
    struct SparseMatrix sparse;
    
    printf("Creating a Sparse Matrix");
    CreateSparseMatrix(&sparse);
    printf("Displaying Sparse Matrix:\n");
    DisplaySparseMatrix(sparse);
    return 0;
}