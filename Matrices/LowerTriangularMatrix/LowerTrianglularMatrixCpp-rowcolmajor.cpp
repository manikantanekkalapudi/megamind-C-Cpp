#include<iostream> 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;

class LowerTriangularMatrix
{
    private:
    int n; // Dimension for the (n*n) matrix
    int *A;
    
    public:
    LowerTriangularMatrix(int n)
    {
        this->n = n;
        A = new int[n]; // Declaring the 1D array to store the diagonal elements of Diagonal Matrix
    }

    void Set_rowmajor(int i, int j, int x);
    int Get_rowmajor(int i, int j);
    void Set_colmajor(int i, int j, int x);
    int Get_colmajor(int i, int j);
    void Display_rowmajor();
    void Display_colmajor();
    int GetDimension(){ return n;}
    //Destructor
    ~LowerTriangularMatrix()
    {
        delete []A;
    }

};

void LowerTriangularMatrix::Set_rowmajor(int i, int j, int x)
{
    if(i >= j)
    {
        A[i*(i-1)/2+j-1] = x;
    }
}

int LowerTriangularMatrix::Get_rowmajor(int i, int j)
{
    if(i >= j)
    {
        return A[i*(i-1)/2+j-1];
    }
    else
    {
        return 0;
    }
}

void LowerTriangularMatrix::Display_rowmajor()
{ 
    int i, j;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i >= j)
            {
                cout<<A[i*(i-1)/2+j-1]<<" ";
            }
            else
            {
               cout<<"0 ";
            }
        }
        cout<<endl;
    }
}


void LowerTriangularMatrix::Set_colmajor(int i, int j, int x)
{
    if(i >= j)
    {
        A[n*(j-1)-(j-2)*(j-1)/2+i-j]  = x;
    }
}

int LowerTriangularMatrix::Get_colmajor(int i, int j)
{
    if(i >= j)
    {
        return A[n*(j-1)-(j-2)*(j-1)/2+i-j];
    }
    else
    {
        return 0;
    }
}


void LowerTriangularMatrix::Display_colmajor()
{ 
    int i, j;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i >= j)
            {
                cout<<A[n*(j-1)-(j-2)*(j-1)/2+i-j]<<" ";
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
    // Get dimensions from the user input
    int d;
    cout<<"Enter the dimenion of the matrix: ";
    cin>>d;
    //Creating Matrix object
    LowerTriangularMatrix low_tri(4);

    //Setting diagonal values for the matrix using 1D array
    low_tri.Set_rowmajor(1,1,3);
    low_tri.Set_rowmajor(2,1,5);
    low_tri.Set_rowmajor(2,2,7);
    low_tri.Set_rowmajor(3,1,9);
    low_tri.Set_rowmajor(3,2,1);
    low_tri.Set_rowmajor(3,3,3);
    low_tri.Set_rowmajor(4,1,5);
    low_tri.Set_rowmajor(4,2,7);
    low_tri.Set_rowmajor(4,3,9);
    low_tri.Set_rowmajor(4,4,1);

    // low_tri.Display_colmajor(); 
    low_tri.Display_rowmajor();
    cout<<"Dimension: "<<low_tri.GetDimension();

    return 0;
}