//****************************************************************************
//**********************	METHOD OVERRIDING	**********************
//****************************************************************************
#include<iostream>
#include<conio.h>
using namespace std;

//base class
class base
{
    public:
    int health;
    int age;
    int colour;
    int getcolour()
        {
            return colour;
        }
};

//derived class
class derived : public base
{
    public: 
        
        int getcolour()
        {
            cout<<"\n derived called \n";
            return colour;
        }
};
int main()
{
    system("cls");
    derived d;
    d.colour = 10;
    cout<<d.getcolour();
    return 0;
    getch();
}

/* output-

*/