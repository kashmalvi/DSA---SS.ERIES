//****************************************************************************
//***************************** SET	*************************************
//****************************************************************************
#include<iostream>
#include<conio.h>
#include<set>               //set library
using namespace std;
int main()
{
    system("cls");
    
    set <int> s;
    
    s.insert(5);
    s.insert(4);
    s.insert(4);        //jayega to ek hi baar, or size bhi ni badega
    s.insert(4);        //jayega to ek hi baar, or size bhi ni badega
    s.insert(0);
    s.insert(7);
    s.insert(1);        //elements are sorted automatically after insertion
    cout<<"\n size of set s is : "<<s.size()
        <<"\n elements are :"; 
    for(int i : s)
        cout<<i<<"\t";
        
    cout<<"\n elements are :";
    s.erase(s.begin());             //if want to delete first element
    for(int i : s)
        cout<<i<<"\t";

    cout<<"\n elements are :";
    set<int> :: iterator it;
    it=s.find(4);             //to delete any element find the index value with find() with iterator to store  
    s.erase(it);             //if want to delete any element from between , use the index value with help iterator
    for(int i : s)
        cout<<i<<"\t";

    cout<<"\n 5 is present or not in the set:"<<s.count(5);
    set<int> :: iterator itr=s.find(5);
    
    cout<<"\n printing value from "<<*itr<<" is: ";
    for( it=itr ; it != s.end() ; it++)             //agar iterator ko end tak chalan hai to use kre '!='  
    {
        cout<<*it<<"\t";
    }
    

    return 0;
    getch();
}

/*

- in set, it always store only unique element, which means if 5 baar agar 4 daal diya to 4 ek hi baar dalega
- isme modification nahi hoti hai, we have two choice either insert or delete
- always return the element in sorted order
- its complexity of insert, find, erase, count is O(log n),  because of binary search tree if you understand
    but size, begin, end, empty is O(1)


output -
 size of set s is : 5
 elements are :0        1       4       5       7
 elements are :1        4       5       7        
 elements are :1        5       7
 5 is present or not in the set:1
 printing value from 5 is: 5    7

*/