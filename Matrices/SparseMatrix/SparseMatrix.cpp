#include <iostream>
using namespace std;
class Element
{
    public:
    int i; // row no. of the element
    int j; // col no. of the element
    int x; // value to store
};

class SparseMatrix
{
    private:
    int m; // no. of rows in the sparse matrix
    int n; // no. of cols in the sparse matrix
    int num; //no. of non-zero elements in the sparse matrix
    Element *ele; // Element pointer to create and array of non-zero elements

    public:
    // Parameterized Constructor
    SparseMatrix(int m , int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new Element[this->num];
    }

    ~SparseMatrix()
    {
        delete [] ele;
    }

    void read()
    {
        cout<<"Enter non-zero elements\n";
        for(int i=0; i<num; i++)
        {
            cin>>ele[i].i>>ele[i].j>>ele[i].x;
        }

    }

    void display()
    {
        int k=0;
        cout<<"Enter non-zero elements\n";
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(ele[k].i == i && ele[k].j == j)
                {
                    cout<<ele[k++].x<<" ";
                }else
                {
                    cout<<"0 ";
                }
                
            }
            cout<<endl;
        }
    }
};

int main()
{
    SparseMatrix s1(5,5,5);
    s1.read();
    s1.display();
    return 0;
}