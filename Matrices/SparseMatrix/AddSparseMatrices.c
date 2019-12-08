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

struct SparseMatrix * addSparseMatrices(struct SparseMatrix *s1, struct SparseMatrix *s2)
{
    struct SparseMatrix *sum;
    int i, j, k;
    i=j=k=0;

    sum = (struct SparseMatrix *)malloc(sizeof(struct SparseMatrix));
    sum->ele = (struct Element *)malloc(s1->num+s2->num*(sizeof(struct Element)));
    if(s1->m != s2->m || s1->n != s2->n)
    {
        printf("Dimensions of the two matrices doesn't match! Enter same dimension for both matrices");
        return sum = NULL;
    }
    while(i<s1->num && j<s2->num)
    {
        if(s1->ele[i].i < s1->ele[j].i)
        {
            sum->ele[k++] = s1->ele[i++];
        }
        else if(s1->ele[i].i > s1->ele[j].i)
        {
            sum->ele[k++] = s2->ele[i++];
        }
        else
        {
            if(s1->ele[i].j < s1->ele[j].j)
            {
                sum->ele[k++] = s1->ele[i++];
            }
            else if(s1->ele[i].j > s1->ele[j].j)
            {
                sum->ele[k++] = s2->ele[i++];
            }
            else
            {
                sum->ele[k] = s1->ele[i];
                sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
            }
            
        }

    }
    for(;i<s1->num; i++)
    {
        sum->ele[k++]=s1->ele[i];
    }

    for(;j<s2->num; j++)
    {
        sum->ele[k++]=s2->ele[j];
    }

    sum->m=s1->m;
    sum->n=s1->n;
    sum->num = k;
    return sum;
}

int main()
{
    struct SparseMatrix sparse1, sparse2, *sum;
    
    printf("Creating a Sparse Matrices\n");
    CreateSparseMatrix(&sparse1);
    CreateSparseMatrix(&sparse2);

    sum = addSparseMatrices(&sparse1, &sparse2);
    if(sum != NULL)
    {
        printf("Displaying Sparse Matrix1:\n");
        DisplaySparseMatrix(sparse1);
        printf("Displaying Sparse Matrix2:\n");
        DisplaySparseMatrix(sparse2);
        printf("Displaying Sum Matrix:\n");
        DisplaySparseMatrix(*sum);
    }
    return 0;
}