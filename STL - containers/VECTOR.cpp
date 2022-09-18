//****************************************************************************
//**********	MEMBER FUNCTION OF VECTOR	********************
//****************************************************************************
#include<iostream>
#include<conio.h>
#include<array>
#include<vector>        //vector library
using namespace std;
int main()
{
    system("cls");
    array <int, 4> ar;              //it is static array i.e., not so much use 
    vector <int> v;                 //it is dynamic so easily extend the memory
    cout<<endl<<v.capacity();       //print capacity of vector 

    v.push_back(1);
    cout<<"\n\n after entering any no. in vector v :";
    cout<<endl<<"capacity: "<<v.capacity();       //print capacity of vector  
    cout<<endl<<"size: "<<v.size();              //print size of vector 

    v.push_back(5);
    cout<<"\n\n after entering any no. in vector v :";
    cout<<endl<<"capacity: "<<v.capacity();       //print capacity of vector  
    cout<<endl<<"size: "<<v.size();              //print size of vector 

    v.push_back(7);
    cout<<"\n\n after entering any no. in vector v :";
    cout<<endl<<"capacity: "<<v.capacity();       //print capacity of vector  
    cout<<endl<<"size: "<<v.size();              //print size of vector
    cout<<"\n is vector v is empty or not:"<<v.empty();

    vector <int> a(5, 1); //initializing 1 , five times
    cout<<"\n front element in vector a: "<<a.front();
    cout<<"\n last  element in vector a: "<<a.back();
    cout<<endl<<"capacity: "<<a.capacity();       //print capacity of vector  
    cout<<endl<<"size: "<<a.size();              //print size of vector
    cout<<"\n all present element in the vector a is :";
    for(int i : a)                              //another syntax to print array , vector , list
        cout<<i;

    v.clear();
    cout<<"\n\n after clearing all values from vector v:";
    cout<<endl<<"capacity"<<v.capacity();       //print capacity of vector  
    cout<<endl<<"size:"<<v.size();              //print size of vector
    cout<<"\n is vector v is empty or not:"<<v.empty(); 


    return 0;
    getch();
}

/* 
--it is more efficient than any static array 
--when element to be insert more than the size the automatically a vector is created with double the memory 
  of old and copies all element to new vector and delete the old vector 

output - 
 after entering any no. in vector v :
capacity: 1
size: 1

 after entering any no. in vector v :
capacity: 2
size: 2

 after entering any no. in vector v :
capacity: 4
size: 3
 is vector v is empty or not:0       
 front element in vector a: 1        
 last  element in vector a: 1
capacity: 5
size: 5
 all present element in the vector a is :11111

 after clearing all values from vector v:
capacity4
size:0
 is vector v is empty or not:1
 
*/