
//**************************************************************************************
//***************************   78.	SUBSET	*******************************LEET CODE****
//**************************************************************************************
#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;

class Solution 
{
private:
    // data member
    vector<vector<int>> ans; // return the 2-d vector which contains value
    int cnt=0;

    // body of solve function
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
    {
        // base case
        if (index >= nums.size())
        {
            cnt++;
            ans.push_back(output); // assigning values of output to vector-ans
            return;
        }

        // exclude call
        solve(nums, output, index + 1, ans);

        // include call
        int element = nums[index]; // assign value of vector to output via element(new int)
        output.push_back(element); // from here we are getting the value in the output vector
        solve(nums, output, index + 1, ans);
    }

public:
    
    // member function
    vector<vector<int>> subsets(vector<int> &nums)
    {

        vector<int> output; // to get the output
        int index = 0;      // represent the index on which operation performs

        // function which performs operation with any name, say solve
        solve(nums, output, index, ans);
        return ans;
    }

    // to print the values how exclude and include funcion assign to ans-vector
    void print(vector<vector<int>> &num)
    {
        cout << "\n Element stored in ans vector be like :  ";
        for (vector<int> v : num) // here it is the syntax to print the 2D-vector with 'auto' keyword
        {
            for (auto i : v)
                cout << i << " ";
        }
    }

    // to know the size of ans-vector
    int sizeofans()
    {
        return cnt;
    }
};

int main()
{
    system("cls");
    Solution ob; // creating an object of class Solution
    vector<int> nums{1, 2, 3};
    vector<vector<int>> v = ob.subsets(nums); // function call of class by object
    ob.print(v);
    cout<<"\n the total outcomes of the given input :  "<<ob.sizeofans();
    return 0;
    getch();
}

//INTEGER BASED CODE

//h.w - try to do this question by bit manipulation