#include <stdio.h>
#include <stdlib.h>
struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n; //no. of non-zero elements
    struct Term *terms;
};

void create(struct Poly *p)
{
    int i;
    printf("No. of non-zero elements: ");
    scanf("%d", p->n);
    p->terms = (struct Term*)malloc(p->n*sizeof(struct Term));

    printf("Enter terms:\n");
    for(i=0; i<p->n;i++)
    {
        scanf("%d%d",&p->terms[i].coeff, &p->terms[i].exp);
    }
}

void display(struct Poly p)
{
    int i;
    printf("Displaying the polynomial: ");
    for(i=0; i<p.n; i++)
    {
        printf("%dx%d",p.terms[i].coeff, p.terms[i].exp);
    }
    printf("\n");
}

int main()
{
    struct Poly p1;
    create(&p1);
    display(p1);    
}