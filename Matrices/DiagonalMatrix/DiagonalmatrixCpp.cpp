#include<iostream> 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;

class DiagonalMatrix
{
    private:
    int n; // Dimension for the (n*n) matrix
    int *A;

    public:
    DiagonalMatrix(int n)
    {
        this->n = n;
        A = new int[n]; // Declaring the 1D array to store the diagonal elements of Diagonal Matrix
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    
    //Destructor
    ~DiagonalMatrix()
    {
        delete []A;
    }

};

void DiagonalMatrix::Set(int i, int j, int x)
{
    if(i == j)
    {
        A[i-1] = x;
    }
}

int DiagonalMatrix::Get(int i, int j)
{
    if(i == j)
    {
        return A[i-1];
    }
    else
    {
        return 0;
    }
}

void DiagonalMatrix::Display()
{ 
    int i, j;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i == j)
            {
                cout<<A[i]<<" ";
            }
            else
            {
               cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    //Creating Matrix object
    DiagonalMatrix d(4);

    //Setting diagonal values for the matrix using 1D array
    d.Set(1,1,3);
    d.Set( 2,2,5);
    d.Set(3,3,7);
    d.Set(4,4,9);

    d.Display();

    return 0;
}