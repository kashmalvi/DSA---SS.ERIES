//****************************************************************************
//**********	AMBIGUITY	********************
//****************************************************************************
#include <iostream>
#include <conio.h>
using namespace std;
class A
{
public:
    void fun()
    {
        cout << "\n A";
    }
};
class B 
{
public:
    void fun()
    {
        cout << "\n B";
    }
};
class C : public B, public A
{
public:
    void fun()
    {
        cout << "\n C";
    }
};
int main()
{
    system("cls");
    C ob;
    ob.A::fun(); //syntax to call fun of parent class A
    ob.B::fun(); //syntax to call fun of parent class B
    ob.fun();
    return 0;
    getch();
}

/*
Ambiguity resolved

o/p -
     A
     B
     C

*/