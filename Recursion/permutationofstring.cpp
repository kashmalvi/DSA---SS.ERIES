//****************************************************************************
//********** 	PERMUTATION OF STRING	******************** CODE STUDIO
//****************************************************************************
#include <iostream>
#include <conio.h>
#include <vector>
#include<algorithm> //for unique words present in vector
using namespace std;
int cnt = 0;
void solve(string s, vector<string> &ans, int index)
{
    // base case
    if (index >= s.size())
    {
        ans.push_back(s);
        return;
    }

    // for swapping of all index places upto length of nums
    for (int j = index; j < s.size(); j++)
    {
        swap(s[index], s[j]);

        // recursive call
        solve(s, ans, index + 1); // with increased index value

        // backtrack - just to revert the changes
        swap(s[index], s[j]);
    }
}
vector<string> uniquePrem(string &s)
{

    vector<string> ans;
    int index = 0;
    solve(s, ans, index);
    sort(ans.begin(),ans.end()); //to sort the vector in lexicographically increasing order
    ans.erase( unique( ans.begin(), ans.end() ), ans.end() ); //to erase the duplicate present in vector
    cnt = ans.size(); //to know how much element are present in vector after erasing duplicates
    return ans;
}
int main()
{
    system("cls");
    string s = {"abcc"};
    cout << "\n The permutation of all string are as follows : " << endl;
    for (auto i : uniquePrem(s))
        cout << i << endl;
    cout << "\n Total permutation of input string is :" << cnt;
    return 0;
    getch();
}

/*
try different test cases but do not repeat duplicates, below are test cases with output
1 - abba    ->  6
2 - abcc    ->  12
3 - cccb    ->  4
4 - aac     ->  3
*/