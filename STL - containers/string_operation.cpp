//****************************************************************************
//**********	OPERATIONS IN STRING	**************************************
//****************************************************************************

//string is a type of container

#include<iostream>
#include<conio.h>
using namespace std;
string operation(string s)
{
    cout<<"\n\n the given string is : ";
    for(auto i: s)
        cout<<i;
    
    cout<<"\n reverse of the string is : ";
    string :: reverse_iterator itr;
    for(itr = s.rbegin() ; itr!=s.rend() ; itr++)
        cout<<*itr;

    cout<<"\n\n to get only first word of string : "; 
    string :: iterator it; 
    for(it = s.begin() ; it != s.begin()+4 ; it++)
        cout<<*it;
    
    cout<<"\n to get only the last word : ";
    for(itr = s.rbegin() ; itr != s.rbegin()+9 ; itr++)
        cout<<*itr;

    cout<<"\n to get the string except first and last text : ";
    for (it = s.begin()+5 ; it != s.end()-10 ; it++)
        cout<<*it;
    
    // cout<<"\n to get the string except first and last text : "; //not possible with two iterator 
    // for (it = s.begin()+5 , itr=s.end()-10; it < itr ; it++)
    //     cout<<*it;

    cout<<"\n\n size of the string is : "<<s.size();
    cout<<"\n capacity of the string is : "<<s.capacity();

    s.push_back('k');

    cout<<"\n size of the string is : "<<s.size();
    cout<<"\n capacity of the string is : "<<s.capacity();//dynamically double the capacity

    cout<<"\nlength of the string : "<<s.length();
    cout<<"\nmax_size of the string : "<<s.max_size();

    cout<<"\n after resize the string become :";
    s.resize(15);
    for(it = s.begin() ; it != s.end() ; it++)
        cout<<*it;
    
    s.shrink_to_fit();
    cout<<"\n capacity of the string after make it fit : "<<s.capacity();

    cout<<"\n checking whether the string is empty or not : "<<s.empty();

    cout<<"\n\n clearing the string in the space :";
    s.clear(); //single syntax to erase whole syntax
    cout<<"\n size of the string is : "<<s.size();
    cout<<"\n now can enter any string in the old string : ";
    s = { "make it possible"};
    cout<<"\n size of new string is : "<<s.size();
    s.shrink_to_fit();
    cout<<"\n capacity of the string is : "<<s.capacity();

    cout<<"\n replacing '@' in front and '#' at end of the string : ";
    s.front()='@';
    s.back()='#';
    for(auto i:s)
        cout<<i;
    cout<<"\n capacity of the string is : "<<s.capacity();

    
}
int main()
{
    system("cls");
    string s{"test book is so beautiful"};
    // cout<<"\n enter any string to operate:";
    // getline(cin , s);
    cout<<"\n after operation perform the output is :";
    operation(s);
    return 0;
    getch();
}

/*
output - 
 after operation perform the output is :    

 the given string is : test book is so beautiful
 reverse of the string is : lufituaeb os si koob tset     

 to get only first word of string : test
 to get only the last word : lufituaeb
 to get the string except first and last text : book is so

 size of the string is : 25
 capacity of the string is : 25
 size of the string is : 26
 capacity of the string is : 50
length of the string : 26
max_size of the string : 4611686018427387903
 after resize the string become :test book is so
 capacity of the string after make it fit : 15
 checking whether the string is empty or not : 0

 clearing the string in the space :
 size of the string is : 0
 now can enter any string in the old string :
 size of new string is : 16
 capacity of the string is : 16
 replacing '@' in front and '#' at end of the string : @ake it possibl#
 capacity of the string is : 16
*/