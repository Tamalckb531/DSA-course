#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &triangle, int row, int col)
{

    if (row == triangle.size() - 1)
    {
        return triangle[row][col];
    }

    int leftVal = triangle[row][col] + solve(triangle, row + 1, col);
    int rightVal = triangle[row][col] + solve(triangle, row + 1, col + 1);

    return min(leftVal, rightVal);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    return solve(triangle, 0, 0);
}