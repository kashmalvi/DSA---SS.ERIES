//****************************************************************************
//******************	IMPLEMENTATION OF STACK 	**************************
//****************************************************************************
#include <iostream>
#include <conio.h>
using namespace std;

// creating a data structure  of stack type
class stack
{
    // properties
public:
    int *arr;
    int top;
    int size;
    // behaviour
    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "\n stack over flow";
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "\n stack under flow";
        }
    }
    int peek()//gettop
    {
        if (top >= 0)
            return arr[top];
        else
        {
            cout << "\n stack is empty\n";
            return -1;
        }
    }
    bool isEmpty()
    {
        if(top == -1)
            return 1;
        else    
            return 0;
    }
};

int main()
{
    system("cls");
    stack st(5);
    cout<<"\n Peek element of stack is - "<<st.peek()<<endl;

    st.push(22);
    st.push(59);
    st.push(45);
    cout<<"\n Peek element of stack is - "<<st.peek()<<endl;
    st.pop();
    cout<<"\n Peek element of stack is - "<<st.peek()<<endl;
    st.pop();
    cout<<"\n Peek element of stack is - "<<st.peek()<<endl;
    st.pop();
    cout<<"\n Peek element of stack is - "<<st.peek()<<endl; 
    if(st.isEmpty())
        cout<<"\n stack is empty";
    else
        cout<<"\n stack is not empty";
    return 0;
    getch();
}