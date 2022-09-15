//*********************************************************************************
//**********	RAT IN MAIZE	******************** GEEKS FOR GEEKS, CODE STUDIO
//*********************************************************************************
#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
using namespace std;
// body of isSafe just to check whether true or false
bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> &m)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1)
        return true;
    else
        return false;
} 

// body of solve
void solve(vector<vector<int>> &m, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path)
{
    // you have reached x , y

    // base case
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // four choices D | L | R | U

    // D - down
    int newx = x + 1;
    int newy = y;
    if (isSafe(newx, newy, n, visited, m))
    {
        path.push_back('D');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // L - LEFT
    newx = x;
    newy = y - 1;
    if (isSafe(newx, newy, n, visited, m))
    {
        path.push_back('L');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // R - RIGHT
    newx = x;
    newy = y + 1;
    if (isSafe(newx, newy, n, visited, m))
    {
        path.push_back('R');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // U - UP
    newx = x - 1;
    newy = y;
    if (isSafe(newx, newy, n, visited, m))
    {
        path.push_back('U');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}

// body of function call
vector<string> searchMaze(vector<vector<int>> &m, int n)
{
    vector<string> ans;

    // if rat did not start to travel from begining due to '0'
    if (m[0][0] == 0)
        return ans;

    int srcx = 0;
    int srcy = 0;

    // visited matrix to indicate previously visited or not
    vector<vector<int>> visited = m; //if do not make it equal to m, it will throw a segmentation fault
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            visited[i][j] = 0; // initialize all element with zero

    string path = "";
    solve(m, n, ans, srcx, srcy, visited, path);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    system("cls");
    vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

    for (auto i : searchMaze(m, 4))
        cout << i << " ";

    return 0;
    getch();
}

// OUTPUT - DDRDRR DRDDRR