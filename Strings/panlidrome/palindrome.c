// Panlindrome is not a palindrome
#include <stdio.h>
#include <string.h>
void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int main()
{
    int l =0;
    char A[] = "palindrome";
    int h = strlen(A)-1;

    while(h>l)
    {
        if(A[l++] != A[h--])
        {
            printf("%s is not a palindrome!", A);
            return 0;
        }
    }
    printf("%s is a palindrome!", A);


}