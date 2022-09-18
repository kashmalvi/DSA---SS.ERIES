//****************************************************************************
//********************************	QUEUE  	**********************************
//****************************************************************************
#include<iostream>
#include<conio.h>
#include<queue>
using namespace std;
int main()
{
    system("cls");

    queue <string> a,s;
    a.push("apple");
    a.push("boat");
    s.push("APPLE");
    s.push("BOAT");

    cout<<"\n top element is :"<<s.front();

    s.pop();                                //jo phele gaya tha wo phele nikal jayega
                                            // yaha per SAPNA nikal gaya phele ab baaki ke element bache hai
    cout<<"\n top element is :"<<s.front();
    
    a.swap(s);                              //to swap two queue object must be needed to swap values of whole container 
    cout<<"\n top element is :"<<a.front();
    cout<<"\n top element is :"<<s.front();

    return 0;
    getch();
}

/*
 --it is the concept of FIRST in first out
 --it is like line/row , ek ke piche dusra

 output - 
 top element is :APPLE
 top element is :BOAT
 top element is :BOAT
 top element is :apple
*/