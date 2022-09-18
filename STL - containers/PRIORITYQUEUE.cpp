//****************************************************************************
//**********************	PRIORITY QUEUE	****************************
//****************************************************************************
#include<iostream>
#include<conio.h>
#include<queue>
using namespace std;
int main()
{
    system("cls");

    //creating max heap
    priority_queue <int> maxi;                //syntax of priority queue

    //creating min heap
    priority_queue <int, vector<int>, greater<int> > mini; 

    maxi.push(1);    
    maxi.push(3);    
    maxi.push(5);    
    maxi.push(0);    
    // for (int  i = 0; i < maxi.size(); i++)      //with this syntax only two element print because size always updated with every loop
    int n=maxi.size();
    for (int  i = 0; i < n ; i++)
    {
        cout<<maxi.top()<<"\t";
        maxi.pop();
    }
    cout<<"\n Is it empty or not:"<<maxi.empty();

    cout<<endl;
    mini.push(1);    
    mini.push(3);    
    mini.push(5);    
    mini.push(0);    
    // for (int  i = 0; i < maxi.size(); i++)      //with this syntax only two element print because size always updated with every loop
    int m=mini.size();
    for (int  i = 0; i < m ; i++)
    {
        cout<<mini.top()<<"\t";
        mini.pop();
    }
    cout<<"\n Is it empty or not:"<<mini.empty();


    return 0;
    getch();
}

/*
 --priority queue is the queue constructed in which first element is always greatest
 --once the insertion of element is complete, then 
                                     -if max heap creation is done the it will always provide maximum value from the queue
                                     -if min heap creation is done the it will always provide minimum value from the queue

output - 
5       3       1       0
 Is it empty or not:1
0       1       3       5
 Is it empty or not:1

 */