//*********************************************************************************
//***************** 	PERMUTATION 	***************************** LEET CODE
//********************************************************************************
#include <iostream>
#include <conio.h>
#include<vector>
using namespace std;
class Solution
{
private:
    //data member
    vector<vector<int>> ans;
    int index = 0;
    int count= 0;

    //body of solve
    void solve(vector<int> nums, vector<vector<int>> &ans, int index)
    {
            //base case
            if(index >= nums.size())
            {
                ans.push_back(nums);
                count++;
                 return ;
            }

            //for swapping of all index places upto length of nums
            for(int j = index ; j < nums.size() ; j++)
            {
                swap(nums[index] , nums[j]);

                //recursive call
                solve(nums, ans, index+1); //with increased index value

                //backtrack - just to revert the changes
                swap(nums[index] , nums[j]);
            }
    }
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        solve(nums, ans , index);
        return ans;
    }

    //printing the total permutation obtained
    void print()
    {
        cout<<"\n Total permutation of the input-value is :  "<<count;
    }
};
int main()
{
    system("cls");
    Solution ob;
    vector<int> nums = {1,2,3}; 
    cout<<"\n The permutation of the input values are : "<<endl;
    for (vector<int> v : ob.permute(nums))
    {
        for(auto i : v)
            cout << i << " ";
        cout<<endl;
    }
    ob.print();
    return 0;
    getch();
}