#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Array
{
    // int pointer for the Array of integer type
    // int *A;
    int *A;
    int size;
    int length;
};

void DisplayArrayElements(struct Array arr)
{
    int i;
    printf("\nElements are:\n");
    for(i=0; i<arr.length; i++)
    {
        printf("%d\n",arr.A[i]);
    }
}

void Append(struct Array *arr, int element)
{
    //Check if the length of the elements in array is less than size of the array
    if(arr->length<arr->size)
    {
        //Insert element at the end of the array elements. Increment the length
        arr->A[arr->length++] = element;
    }

}

void Insert(struct Array *arr, int index, int element)
{
    int i;

    if(index>=0 && index<=arr->length)
    {
        for(i=arr->length; i>index; i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = element;
        arr->length++;
    }

}

int Delete(struct Array *arr, int index)
{
    int i;

    if(index >=0 && index <arr->length)
    {
        int x = arr->A[index];
        for(i=index; i<arr->length-1;i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

int LinearSearch(struct Array arr, int key)
{
    int i;

    for(i=0; i<arr.length; i++)
    {
        if(arr.A[i] == key)
        {
            return i;
        }
    }
    return -1;
}

void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int LinearSearch_transposition(struct Array *arr, int key)
{
 int i;

    for(i=0; i<arr->length; i++)
    {
        if(arr->A[i] == key)
        {
            swap(&arr->A[i], &arr->A[i-1]);
            return i;
        }
    }
    return -1;
}

int LinearSearch_movetohead(struct Array *arr, int key)
{
 int i;

    for(i=0; i<arr->length; i++)
    {
        if(arr->A[i] == key)
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length-1;

    while(l<=h)
    {
        mid = (l+h)/2;
        if(key == arr.A[mid])
        {
            return mid;
        }
        else if(key < arr.A[mid])
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



int RecurciveBinarySearch(int a[], int l, int h, int key)
{
    int mid;

    if(l<=h)
    {
        mid = (l+h)/2;
        if(key == a[mid])
        {
            return mid;
        }
        else if(key < a[mid])
        {
           return RecurciveBinarySearch(a, l, mid-1, key);
        }
        else
        {
            return RecurciveBinarySearch(a, mid+1, h, key);
        }
    }
    return -1;
}

int Get(struct Array arr, int index)
{
    if(index>=0 && index<arr.length)
    {
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array *arr, int index, int x)
{
    if(index>=0 && index<arr->length)
    {
        arr->A[index] = x;
    }
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    int i;
    for(i=0; i<arr.length; i++)
    {
        if(arr.A[i]>max)
        {
            max = arr.A[i];
        }
    }
    return max;
}


int Min(struct Array arr)
{
    int min = arr.A[0];
    int i;
    for(i=0; i<arr.length; i++)
    {
        if(arr.A[i]<min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

int Sum(struct Array arr)
{
    int total = 0;
    int i;
    for(i=0; i<arr.length; i++)
    {
        total += arr.A[i];
    }
    return total;
}

float Avg(struct Array arr)
{
    return (float)Sum(arr)/arr.length;
}


void LeftShift_Reverse(struct Array *arr)
{
    int *B;
    int i,j;

    B = (int *)malloc(sizeof(arr->length*sizeof(int)));

    for(i=0,j=arr->length-1; i<arr->length; i++, j--)
    {
        B[j] = arr->A[i];
    }

    for(i=0; i<arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}

void LeftShift_Reverse2(struct Array *arr)
{
    int i,j;
    int temp;
    for(i=0, j=arr->length-1; i<j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

bool isSorted(struct Array *arr, int length)
{
    int i;
    for(i=0; i<length-1; i++)
    {
        if(arr->A[i]>arr->A[i+1])
        {
            return false;
        }
    }
    return true;
}

void insertsort(struct Array *arr, int ele)
{
    int i=arr->length-1 ;
    if(arr->length == arr->size)
    {
        return;
    }
    while(i>=0 && arr->A[i]>ele)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = ele;
    arr->length++;

}

void rearrange_posandneg(struct Array *arr)
{
    int i=0, j= arr->length-1;

    while(i<j)
    {
        while(arr->A[i]<0)
        {
            i++;
        }
        while(arr->A[j]>=0)
        {
            j--;
        }
        if(i<j)
        {
            swap(&arr->A[i], &arr->A[j]);
        }
    }
}

struct Array* MergeArrays(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i=j=k=0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }
    for(;i<arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }

    for(;j<arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    return arr3;
}


struct Array* SetUnion(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i=j=k=0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if(arr2->A[j]<arr1->A[i])
        {
            arr3->A[k++] = arr2->A[j++];
        }
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }

    for(;j<arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;

    return arr3;
}


struct Array* SetIntersection(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i=j=k=0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            i++;
        }
        else if(arr2->A[j]<arr1->A[i])
        {
            j++;
        }
        else if(arr2->A[j] == arr1->A[i])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;

    return arr3;
}


struct Array* SetDifference(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i=j=k=0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if(arr2->A[j]<arr1->A[i])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    for(;i<arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;

    return arr3;
}



int main()
{
    //Creating the object of struct Array
    struct Array arr1;
    int choice, index, element;

    printf("Enter size of the Array: \n");
    scanf("%d", &arr1.size);

    arr1.A = (int *)malloc(arr1.size*sizeof(int));

    do
    {
        printf("Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice:\n");
        scanf("%d", &choice);


        switch(choice)
        {
            case 1: printf("Enter element and index for Insert operation: ");
                scanf("%d%d", &element, &index);
                Insert(&arr1,1, 12);
                break;

            case 2: printf("Enter element to delete: ");
                scanf("%d", &element);
                Delete(&arr1, 1);
                break;

            case 3:  printf("Enter element to search: ");
                scanf("%d", &element);
                index = LinearSearch(arr1, 22);
                if(index == -1)
                {
                    printf("Element not found!");
                }
                else
                {
                    printf("Element found at %d", index);
                }
                break;

            case 4:  printf("Sum of all elements: %d", Sum(arr1));
                break;

            case 5: DisplayArrayElements(arr1);
        }
    } while(choice < 6);


    return 0;

}
