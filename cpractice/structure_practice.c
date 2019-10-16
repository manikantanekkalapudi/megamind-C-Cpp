#include <stdio.h>
#include <stdlib.h>

struct Rectangle
{
    int length;
    int breadth;
};

void initilize(struct Rectangle *r, int l, int b)
{
    r -> length = l;
    r -> breadth = b;
}

int area(struct Rectangle r)
{
    return r.length * r.breadth;
}

void changeLenght(struct Rectangle *r, int l)
{
    r -> length = l;
}
int main()
{
    printf("Hello world!\n");
    struct Rectangle r;
    initilize(&r, 5, 10);
    printf("Area: %d\n", area(r));
    changeLenght(&r, 20);
    printf("Area: %d\n", area(r));

    return 0;
}
