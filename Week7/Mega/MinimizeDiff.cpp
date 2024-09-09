#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &mat, int &target, int sum, int row)
{
    if (row == mat.size())
        return abs(target - sum);

    int ans = INT_MAX;
    for (int col = 0; col < mat[row].size(); col++)
    {
        int element = mat[row][col];
        int recursionAns = solve(mat, target, sum + element, row + 1);
        ans = min(ans, recursionAns);
    }

    return ans;
}

int minimizeTheDifference(vector<vector<int>> &mat, int target)
{
    return solve(mat, target, 0, 0);
}