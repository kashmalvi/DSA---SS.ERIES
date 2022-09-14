
//****************************************************************************************************
//*************************** 45. SUBSEQUENCES OF STRING	**************************CODE STUDIO****
//***************************************************************************************************
#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;

void print(vector<string> &ans);

// body of solve function
void solve(string str, string output, int index, vector<string> &ans)
{
    // base case
    if (index >= str.length())
    {
        if (output.length() > 0)
        {   
            ans.push_back(output); // assigning values of output to vector-ans
        }
        return;
    }

    // exclude call
    solve(str, output, index + 1, ans);

    // include call
    int element = str[index];  // assign value of vector to output via element(new int)
    output.push_back(element); // from here we are getting the value in the output vector
    solve(str, output, index + 1, ans);
}

vector<string> subsequences(string str)
{

    vector<string> ans;  // return the 2-d vector which contains value
    string output = ""; // to get the output but do not include whitespace it is case sensitive
    int index = 0;       // represent the index on which operation performs

    // function which performs operation with any name, say solve
    solve(str, output, index, ans);
    print(ans);
    return ans;
}

// to print the values how exclude and include funcion assign to ans-vector
void print(vector<string> &ans)
{
    cout << "\n Element stored in ans vector be like :  ";
    
        for (auto i : ans )
            cout << i << " ";
    
}

int main()
{
    system("cls");
    string str{"abc"};
    vector<string> v = subsequences(str); // function call of class by object
    return 0;
    getch();
}

// STRING BASED CODE

//h.w - try to do this question by bit manipulation