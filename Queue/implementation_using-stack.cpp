//****************************************************************************
//**********	IMPLEMENTATION OF STACK USING RECURSION	********************
//****************************************************************************
#include<iostream>
#include<conio.h>
#include<stack>
using namespace std;

class queue
{
    public:

    stack<int> s1;

    //push function
    void push(int data)  //O(1)
    {
        s1.push(data);
    }

    //pop function
    int pop() //O(n) 
    {

        if(s1.empty())
        {
            cout<<"\n queue  is emptyy";
            exit(0);
        }

        int val = s1.top();
        s1.pop();

        if(s1.empty())
        {
            return val;
        }
        
        int pop_data = pop();

        s1.push(val);

        return pop_data;
    }

    //front function
    int front()  //O(1)
    {
        int val = s1.top();
        s1.pop();
        if(s1.empty())
        {
            return val;
        }
        
        int front_data = front();
        s1.push(val);
        return front_data;
    }

    void back() //O(1)
    {
        cout<<s1.top();
    }

};

int main()
{
    system("cls");
    queue q;
    cout<<"\npushing 1 2 3 4 5";
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<"\npop "<<q.pop();
    cout<<"\nfront is "<<q.front();
    cout<<"\nback is ";
    q.back();
    return 0;
    getch();
}

/*
pushing 1 2 3 4 5
pop 1
front is 2
back is 5

tc - O(1) for push 
tc - O(n) for pop

sc - O(n) for pop in function call stack
*/
