//****************************************************************************
//******************************    MAP     *********************************
//****************************************************************************
#include <iostream>
#include <conio.h>
#include <map> //include library.
using namespace std;
int main()
{
    system("cls");

    map<int, string> m; // syntax to declare map
                        // this syntax also print in sorted order
    m[5] = "apple";      // first syntax to assign value
    m[2] = "boat";
    m[4] = "cow";
    m[3] = "kite";
    m[0] = "doctor";
    m[0] = "eicher"; // this is updated for m[0]

    m.insert({6, "fish"});
    m.insert({6, "hike"}); // this not getting update
    m.insert({1, "monalisa"}); // this will getting update because of different key

    cout << "\n before erase-"<<endl;
    for (auto i : m)
    {
        cout << i.first << "\t";  // print the first part present in the element
        cout << i.second << endl; // print the second part present in the element
    }

    cout << "\n checking that 4 is present or not: " << m.count(4); // print the value if yes = 1 and if no = 0 that is present or not

    cout << "\n after erase-"<<endl;
    m.erase(4); // erasing by key

    // map<int, string>::iterator it;       // erasing by iterator
    auto it = m.find(6); // auto keyword is a simple way to declare a variable that has a complicated type
    m.erase(it);

    for (auto i : m)
    {
        cout << i.first << "\t";  // print the first part present in the element
        cout << i.second << endl; // print the second part present in the element
    }

    it = m.find(2); // it me key 2 ka index
    cout << "\n element to be print from key 2:" << endl;
    for (auto i = it; i != m.end(); i++)
        cout << (*i).first << "\t" << (*i).second << endl; // syntax to print element from map via index value

    it = m.find(5); // it me key 2 ka index
    cout << "\n element to be print from key 2:" << endl;
    for (auto i = it; i != m.end(); i++)
        cout << (*i).first << "\t" << (*i).second << endl; // syntax to print element from map via index value

    return 0;
    getch();
}

/*
-- data store in key form which points to a value
-- always store the data in sorted form
-- one key point to one value only, two key can point to same value, but one key cannot point to two value
-- in this case look once a code, here first is key and second is value

output - 
 before erase-
0       eicher
1       monalisa
2       boat
3       kite
4       cow
5       apple
6       fish

 checking that 4 is present or not: 1
 after erase-
0       eicher
1       monalisa
2       boat
3       kite
5       apple

 element to be print from key 2:
2       boat
3       kite
5       apple

 element to be print from key 2:
5       apple
*/