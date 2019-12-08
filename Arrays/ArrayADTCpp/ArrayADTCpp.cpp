#include<iostream> 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;

class Array
{
    // Declaring the private variables and method under private access modifier
    private:
        // int pointer for the Array of integer type
        int *A;
        int size; // final size of the array or max elements that an array can hold
        int length; // no. of elements that are currently in the array
        void swap(int *x, int *y);
    
    // Declaring the public constructor to the Array class and destructor method for the same
    public:
        // Array class constructor
        Array()
        {
            size = 10; // size of the array is fixed to 10 elements
            length = 0; // initial length is set to zero
            A = new int[size]; // Array is declared with size of 10 elements
        }
        // parameterized constructor for Array class
        Array(int sz)
        {
            size = sz; //size of the Array is taken as an input to the constructor using 'sz'
            length = 0; // initial length is set to zero
            A = new int[size]; // Array is declared with the given size
        }
        // Destructor to delete the Array object
        ~Array()
        {
            delete []A;
        }

// Defining all the functions for the Array class
void DisplayArrayElements(); // displays all the elements
void Append(int element); // add an element at the end of the array if length < size
void Insert(int index, int element); // inserts a given element at a given index in the array
int Delete(int index); // deletes the element at a given index
int LinearSearch(int key); // searches for an element in the array sequentially and returns the index
int LinearSearch_transposition(int key); // searches for an element in the array sequentially and if element is found it returns the index, it'll move it one step towards head
int LinearSearch_movetohead(int key); // searches for an element in the array sequentially and if element is found it returns the index, it'll move it to head
int BinarySearch(int key); // searches the sorted array by dividing the array into two halves at each step
//int RecurciveBinarySearch(int a[], int l, int h, int key);
int Get(int index); // gets index of an element
void Set(int index, int x); // set the value at an index to the given element
int Max(); // max value in the array
int Min(); // min value in the array
int Sum(); // sum of all the elements in the array
float Avg(); // avg of all the elements in the array
void LeftShift_Reverse(); 
void LeftShift_Reverse2();
bool isSorted(int length); // checks if the array is sorted 
void insertsort(int ele);
void rearrange_posandneg();
Array* MergeArrays(Array arr2);
Array* SetUnion(Array arr2);
Array* SetIntersection(Array arr2);
Array* SetDifference(Array arr2);

};


void Array::DisplayArrayElements()
{
    int i;
    cout<<"\nElements are:\n";
    for(i=0; i<length; i++)
    {
        cout<<" "<<A[i]<<"\n";
    }
}

void Array::Append(int element)
{
    //Check if the length of the elements in array is less than size of the array
    if(length<size)
    {
        //Insert element at the end of the array elements. Increment the length
        A[length++] = element;
    }

}

void Array::Insert(int index, int element)
{
    int i;

    if(index>=0 && index<=length)
    {
        for(i=length; i>index; i--)
        {
            A[i] = A[i-1];
        }
        A[index] = element;
        length++;
    }

}

int Array::Delete(int index)
{
    int i;

    if(index >=0 && index <length)
    {
        int x = A[index];
        for(i=index; i<length-1;i++)
        {
            A[i] = A[i+1];
        }
        length--;
        return x;
    }
    return 0;
}

int Array::LinearSearch(int key)
{
    int i;

    for(i=0; i<length; i++)
    {
        if(A[i] == key)
        {
            return i;
        }
    }
    return -1;
}

void Array::swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int Array::LinearSearch_transposition(int key)
{
 int i;

    for(i=0; i<length; i++)
    {
        if(A[i] == key)
        {
            swap(&A[i], &A[i-1]);
            return i;
        }
    }
    return -1;
}

int Array::LinearSearch_movetohead(int key)
{
 int i;

    for(i=0; i<length; i++)
    {
        if(A[i] == key)
        {
            swap(&A[i], &A[0]);
            return i;
        }
    }
    return -1;
}

int Array::BinarySearch(int key)
{
    int l, mid, h;
    l = 0;
    h = length-1;

    while(l<=h)
    {
        mid = (l+h)/2;
        if(key == A[mid])
        {
            return mid;
        }
        else if(key < A[mid])
        {
            h = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    return -1;
}



// int Array::RecurciveBinarySearch(int a[], int l, int h, int key)
// {
//     int mid;

//     if(l<=h)
//     {
//         mid = (l+h)/2;
//         if(key == a[mid])
//         {
//             return mid;
//         }
//         else if(key < a[mid])
//         {
//            return RecurciveBinarySearch(a, l, mid-1, key);
//         }
//         else
//         {
//             return RecurciveBinarySearch(a, mid+1, h, key);
//         }
//     }
//     return -1;
// }

int Array::Get(int index)
{
    if(index>=0 && index<length)
    {
        return A[index];
    }
    return -1;
}

void Array::Set(int index, int x)
{
    if(index>=0 && index<length)
    {
        A[index] = x;
    }
}

int Array::Max()
{
    int max = A[0];
    int i;
    for(i=0; i<length; i++)
    {
        if(A[i]>max)
        {
            max = A[i];
        }
    }
    return max;
}


int Array::Min()
{
    int min = A[0];
    int i;
    for(i=0; i<length; i++)
    {
        if(A[i]<min)
        {
            min = A[i];
        }
    }
    return min;
}

int Array::Sum()
{
    int total = 0;
    int i;
    for(i=0; i<length; i++)
    {
        total += A[i];
    }
    return total;
}

float Array::Avg()
{
    return (float)Sum()/length;
}


void Array::LeftShift_Reverse()
{
    int *B;
    int i,j;

    B = (int *)malloc(sizeof(length*sizeof(int)));

    for(i=0,j=length-1; i<length; i++, j--)
    {
        B[j] = A[i];
    }

    for(i=0; i<length; i++)
    {
        A[i] = B[i];
    }
}

void Array::LeftShift_Reverse2()
{
    int i,j;
    int temp;
    for(i=0, j=length-1; i<j; i++, j--)
    {
        swap(&A[i], &A[j]);
    }
}

bool Array::isSorted(int length)
{
    int i;
    for(i=0; i<length-1; i++)
    {
        if(A[i]>A[i+1])
        {
            return false;
        }
    }
    return true;
}


void Array::insertsort(int ele)
{
    int i=length-1 ;
    if(length == size)
    {
        return;
    }
    while(i>=0 && A[i]>ele)
    {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = ele;
    length++;

}

void Array::rearrange_posandneg()
{
    int i=0, j= length-1;

    while(i<j)
    {
        while(A[i]<0)
        {
            i++;
        }
        while(A[j]>=0)
        {
            j--;
        }
        if(i<j)
        {
            swap(&A[i], &A[j]);
        }
    }
}

Array* Array::MergeArrays(Array arr2)
{
    int i, j, k;
    i=j=k=0;

    Array *arr3 = new Array(length+arr2.length);

    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
        {
            arr3->A[k++] = A[i++];
        }
        else
        {
            arr3->A[k++] = arr2.A[j++];
        }
    }
    for(;i<length; i++)
    {
        arr3->A[k++] = A[i];
    }

    for(;j<arr2.length; j++)
    {
        arr3->A[k++] = arr2.A[j];
    }
    arr3->length = length + arr2.length;
    arr3->size = 10;
    return arr3;
}


Array* Array::SetUnion(Array arr2)
{
    int i, j, k;
    i=j=k=0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
        {
            arr3->A[k++] = A[i++];
        }
        else if(arr2.A[j]<A[i])
        {
            arr3->A[k++] = arr2.A[j++];
        }
        else
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    for(;i<length; i++)
    {
        arr3->A[k++] = A[i];
    }

    for(;j<arr2.length; j++)
    {
        arr3->A[k++] = arr2.A[j];
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;

    return arr3;
}


Array* Array::SetIntersection(Array arr2)
{
    int i, j, k;
    i=j=k=0;

    struct Array *arr3 = new Array(length+arr2.length);

    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
        {
            i++;
        }
        else if(arr2.A[j]<A[i])
        {
            j++;
        }
        else if(arr2.A[j] == A[i])
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;

    return arr3;
}


Array* Array::SetDifference(Array arr2)
{
    int i, j, k;
    i=j=k=0;

    struct Array *arr3 = new Array(length+arr2.length);

    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
        {
            arr3->A[k++] = A[i++];
        }
        else if(arr2.A[j]<A[i])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    for(;i<length; i++)
    {
        arr3->A[k++] = A[i];
    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;

    return arr3;
}



int main()
{
    //Creating the object of struct Array
    Array *arr1;
    int choice, sz, x;
    int index, element;

    cout<<"Enter size of the Array: \n";
    cin>>sz;

    arr1=new Array(sz);

    do
    {
        cout<<"Menu\n";
        cout<<"1. Insert\n";
        cout<<"2. Delete\n";
        cout<<"3. Search\n";
        cout<<"4. Sum\n";
        cout<<"5. Display\n";
        cout<<"6. Exit\n";

        cout<<"Enter your choice:\n";
        cin>>choice;


        switch(choice)
        {
            case 1: cout<<"Enter element and index for Insert operation: ";
                cin>>element>>index;
                arr1->Insert(element,index);
                break;

            case 2: cout<<"Enter element to delete: ";
                cin>>element;
                x = arr1-> Delete(element);
                break;

            case 3:  cout<<"Enter element to search: ";
                cin>>element;
                index = arr1->LinearSearch(element);
                if(index == -1)
                {
                    cout<<"Element not found!";
                }
                else
                {
                    cout<<"Element found at "<<index;
                }
                break;

            case 4:  cout<<"Sum of all elements: "<<arr1->Sum();
                break;

            case 5: arr1->DisplayArrayElements();
        }
    } while(choice < 6);


    return 0;

}
