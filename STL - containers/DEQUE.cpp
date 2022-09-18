//****************************************************************************
//**********    LEARN DEQUE / DOUBLE ENDED QUEUE	********************
//****************************************************************************
#include<iostream>
#include<conio.h>
#include<deque>
using namespace std;
int main()
{
    system("cls");

    deque<int> d;
    d.push_front(2);            //insert value at front in deque
    d.push_front(1);
    d.push_front(0);
    d.push_back(3);
    d.push_back(4);
    d.push_back(5);
    d.push_back(6);             //element are sorted when inserting new element 

    cout<<"\n Maximum size of deque is: "<<d.max_size();
    cout<<"\n elements in the deque is: ";
    for(int i:d)
        cout<<i<<"\t";

    cout<<"\n size of deque is: "<<d.size();
    cout<<"\n empty or not: "<<d.empty();

    // d.erase(d.begin() , d.begin()+2);       //syntax to erase some element in the deque, from front if two then write '+2', if all then write end()
    d.erase(d.end()-2 , d.end());              //syntax to erase some element in the deque, from back 
    cout<<"\n elements in the deque is: ";
    for(int i:d)
        cout<<i<<"\t";
    cout<<"\n size of deque is: "<<d.size();

    d.clear();                              //to delete all element from the deque
    cout<<"\n size of deque is: "<<d.size()<<endl;
    cout<<"\n Maximum size of deque is: "<<d.max_size();        //maximum size still remains same untill and unless object not deleted
    return 0;
    getch();
}

/*
output - 

 Maximum size of deque is: 2305843009213693951
 elements in the deque is: 0    1       2       3       4       5       6
 size of deque is: 7
 empty or not: 0
 elements in the deque is: 0    1       2       3       4
 size of deque is: 5
 size of deque is: 0

 Maximum size of deque is: 2305843009213693951

 */