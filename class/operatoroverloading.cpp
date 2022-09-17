//****************************************************************************
//******************	OPERATOR OVERLOADING	**************************
//****************************************************************************
#include<iostream>
#include<conio.h>
using namespace std;
class A
{
    public:
       int a;
       int b;

    int operator+ (A &obj) //operator overloading only done with the keyword operator
    {
        int val3;
        val3 = this->a * obj.a; //here can be done any arithematic operation 
        return val3;
    }

    void operator () ()
    {
        cout<<"\n operator()  called with value of a "<<this->a;

    }
};
int main()
{
    system("cls");
    A obj1, obj2;
    obj1.a = 30;
    obj2.a = 20;

    cout<<"output:"<<obj1 + obj2; ///syntax of operator overloading 

    obj1 () ;
    obj2 ();
    return 0;
    getch();
}

/*
o/p -> output:600
        operator()  called with value of a 30
         operator()  called with value of a 20

so with the help of operator overloading we can make changes as we want 

home_work - try operator overloading with new, delete keywords
*/