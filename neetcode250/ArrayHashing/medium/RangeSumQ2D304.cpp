#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class NumMatrix
{
private:
    vector<vector<int>> mt;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        for (auto arr : matrix)
        {
            vector<int> temp;
            for (auto elem : arr)
            {
                temp.push_back(elem);
            }
            mt.push_back(temp);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int ans = 0;
        for (int i = row1; i <= row2; i++)
        {
            for (int j = col1; j <= col2; j++)
            {
                ans += mt[i][j];
            }
        }

        return ans;
    }
};

//? Prefix sum for optimization
class NumMatrix
{
private:
    vector<vector<int>> prefixSum;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        prefixSum = vector<vector<int>>(rows, vector<int>(cols, 0));

        for (int row = 0; row < rows; row++)
        {
            prefixSum[row][0] = matrix[row][0];
            for (int col = 1; col < cols; col++)
            {
                prefixSum[row][col] = prefixSum[row][col - 1] + matrix[row][col];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int res = 0;
        for (int row = row1; row <= row2; row++)
        {
            if (col1 > 0)
            {
                res += prefixSum[row][col2] - prefixSum[row][col1 - 1];
            }
            else
            {
                res += prefixSum[row][col2];
            }
        }
        return res;
    }
};

int main()
{
    cout << "LeetCode 304. Range Sum Query 2D - Immutable" << endl;
}