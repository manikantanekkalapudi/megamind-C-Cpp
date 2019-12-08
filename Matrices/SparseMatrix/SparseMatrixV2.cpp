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

    // Operator overloading is used to create read() and display() and add()
    SparseMatrix operator+(SparseMatrix &s);
    // Below function is read as istream returns reference(&) operator extraction(operator>>)
    friend istream & operator>>(istream &is, SparseMatrix &s);
    friend ostream & operator<<(ostream &os, SparseMatrix &s);
    

};

SparseMatrix SparseMatrix::operator+(SparseMatrix &s)
{
    int i, j, k;
    if(m!=s.m || n!=s.n)
    {
        return SparseMatrix(0,0,0);
    }
    SparseMatrix *sum = new SparseMatrix(m, n ,num+s.num);
    i=j=k=0;
    while(i<num && j<s.num)
    {
        if(s.ele[i].i < s.ele[j].i)
        {
            sum->ele[k++] = s.ele[i++];
        }
        else if(s.ele[i].i > s.ele[j].i)
        {
            sum->ele[k++] = s.ele[j++];
        }
        else
        {
            if(s.ele[i].j > s.ele[j].j)
            {
                sum->ele[k++] = s.ele[i++];
            }
            else if(s.ele[i].j > s.ele[j].j)
            {
                sum->ele[k++] = s.ele[j++];
            }
            else
            {
                sum->ele[k] = ele[i];
                sum->ele[k++].x = ele[i++].x + s.ele[j++].x;
            }
        }    
    }
    for(;i<num;i++)
    {
        sum->ele[k++] = ele[i];
    }
    for(;j<s.num;j++)
    {
        sum->ele[k++] = s.ele[j];
    }
    sum->num = k;

    return *sum;
}
istream & operator>>(istream &is, SparseMatrix &s)
{
    cout<<"Enter non-zero elements\n";
    for(int i=0; i<s.num; i++)
    {
        cin>>s.ele[i].i>>s.ele[i].j>>s.ele[i].x;
    }
    return is;
}

ostream & operator<<(ostream &os, SparseMatrix &s)
{
    int k=0;
    for(int i=0; i<s.m; i++)
    {
        for(int j=0; j<s.n; j++)
        {
            if(s.ele[k].i == i && s.ele[k].j == j)
            {
                cout<<s.ele[k++].x<<" ";
            }else
            {
                cout<<"0 ";
            }
            
        }
        cout<<endl;
    }
    return os;
}


int main()
{
    SparseMatrix s1(5,5,5);
    SparseMatrix s2(5,5,5);
    
    cin>>s1;
    cin>>s2;

    SparseMatrix sum=s1+s2;

    cout<<"First Matrix\n"<<s1;
    cout<<"Second Matrix\n"<<s2;
    cout<<"Sum Matrix\n"<<sum;
    return 0;
}