//****************************************************************************
//**********	MIN COST TO CLIMB STAIRS	********************
//****************************************************************************
/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.
*/
#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;


// //using top-down approach --> recursion + memoisation----------------------------
// int solve(int n, vector<int> &cost, vector<int>&dp){
//     //step 2 --> initialising the base case
//     if(n==0)
//         dp[0] = cost[0];
//     if(n==1)
//         dp[1] = cost[1];

//     //checking if value is available in dp or not
//     if(dp[n]!=-1)
//         return dp[n];
//     //step 3 --> recursive call
//     dp[n] = min(solve(n-1, cost, dp), solve(n-2, cost, dp)) + cost[n];
//     return dp[n];
// }

// int minCostofClimb(vector<int> &cost){
//     int n = cost.size();
//     //step 1 -  creating a dp array to store obtained value
//     vector<int> dp(n+1, -1);
//     int ans = min(solve(n-1, cost, dp), solve(n-2, cost, dp));
//     return ans;
// }
// //tc - O(n)
// //sc - O(n) to store values + O(n) for recursive call = O(n)
// //-------------------------------------------------------------------------------


// //using bottom up approach --> tabulation----------------------------------------
// int solve(int n, vector<int>&cost){
//     //step 1 --> creating a dp vector
//     vector<int> dp(n+1);
//     //step 2 --> initialising the base case
//     dp[0] = cost[0];
//     dp[1] = cost[1];

//     //step 3 -->
//     for(int i=2; i<n; i++){
//         dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
//     }
//     return min(dp[n-1], dp[n-2]);
// }

// int minCostofClimb(vector<int> &cost){
//     int n = cost.size();
//     return solve(n, cost);
// }
// //tc - O(n)
// //sc - O(n)
// //-------------------------------------------------------------------------------


//using space optimisation approach----------------------------------------------
int minCostofClimb(vector<int>&cost){
    int n = cost.size();
    //initialising base case
    int prev2 = cost[0];
    int prev1 = cost[1];

    //handling the case if there is any 
    if(n == 0)
        return prev2;

    for(int i=2; i<n; i++){
        int curr = min(prev1, prev2) + cost[i];
        prev2 = prev1;
        prev1 = curr;
    }
    return min(prev1, prev2);

}
//tc - O(n)
//sc - O(1)
//-------------------------------------------------------------------------------

//------------------------MAIN FUNCTION------------------------------------------
int main()
{
    vector<int> cost{10,15,20};
    cout<<minCostofClimb(cost);
    return 0;
} 

/*
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6

Input: cost = [10,15,20]
Output: 15

*/