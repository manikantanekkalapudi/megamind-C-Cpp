#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

class Stack
{
private:
    Node *Top; //Top pointer to the LinkedList
public:
    Stack(){Top = NULL;};
    void push(int x);
    int pop();
    int length();
    int peek(int index);
    void display();
    int isEmpty();
    int isFull();
    int stackTop();
    ~Stack();
};


void Stack::push(int x)
{
    Node *p = new Node;
    if(p == NULL)
    {
        cout<<"\nStack Overflow!\n";
    }
    else
    {
        p->data = x;
        p->next = Top;
        Top = p;       
    }
    
}

int Stack::pop()
{
    int x = -1;
    Node *p = Top;
    if(Top == NULL)
    {
        cout<<"\nStack Underflow!\n";
        return -1;
    }
    else
    {
        Top = Top->next;
        x = p->data;
        delete p;    
    }
    return x;
}

void Stack::display()
{
    Node * p = Top;

    while (p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int Stack::length()
{
    Node *p = Top;
    int len = 0;
    while(p != NULL)
    {
        len += 1;
        p = p->next;
    }
    return len;
}

int Stack::peek(int index)
{
    Node *p = Top;
    if(p == NULL || index > length() || index < 1)
    {
        return -1;
    }
    else
    {
        for(int i=0; i<index-1; i++)
        {
            p = p->next;
        }
        return p->data;
    }
}

int Stack::isEmpty()
{
    if(Top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int Stack::isFull()
{
    Node *p = new Node;

    if(p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int Stack::stackTop()
{
    return Top->data;    
}


Stack::~Stack()
{
    Node *p = Top;
    for(int i=length(); i<=0; i--)
    {
        Top = Top->next;
        delete p;
    }
    cout<<"Stack is deleted!\n";
}

int main()
{
    Stack st;
    st.push(5);
    st.push(8);
    st.push(2);
    st.push(7);
    st.display();
    // cout<<"Popped value: "<<st.pop()<<"\n";
    st.display();
    cout<<"Peeked value: "<<st.peek(2)<<"\n";
    cout<<"isEmpty: "<<st.isEmpty()<<"\n";
    cout<<"isFull: "<<st.isFull()<<"\n";
    cout<<"stackTop: "<<st.stackTop()<<"\n";
    // st.~Stack();
}