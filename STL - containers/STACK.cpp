//****************************************************************************
//********************************	STACK	**********************************
//****************************************************************************
#include<iostream>
#include<conio.h>
#include<stack>
using namespace std;
int main()
{
    system("cls");

    stack <string> a,s;
    a.push("apple");
    a.push("boat");
    s.push("APPLE");
    s.push("BOAT");

    cout<<"\n top element is :"<<s.top();

    s.pop();                                //jo aakhri me gaya tha wo phele nikal jayega
    cout<<"\n top element is :"<<s.top();
    
    a.swap(s);                              //to swap two stack object must be needed to swap values of whole container 
    cout<<"\n top element is :"<<a.top();
    cout<<"\n top element is :"<<s.top();

    return 0;
    getch();
}

/*
 --it is the concept of last in first out
 --it is like column , ek ke upper ek

output - 
 top element is :BOAT
 top element is :APPLE
 top element is :APPLE
 top element is :boat

 */