#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<char>> &matrix, int i, int j, int &row, int &col, int &maxi)
{

    //? base case
    if (i >= row || j >= col)
        return 0;

    //? traversal
    int right = solve(matrix, i, j + 1, row, col, maxi);
    int diagonal = solve(matrix, i + 1, j + 1, row, col, maxi);
    int down = solve(matrix, i + 1, j, row, col, maxi);

    //? solution
    if (matrix[i][j] == '1')
    {
        //? 1 means it can make a square and can count for the upper diagonal 1
        int ans = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, ans);
        return ans;
    }
    else
    {
        //? 0 means it can't make a square if there is a upper diagonal 1
        return 0;
    }
}

int maximalSquare(vector<vector<char>> &matrix)
{
    int i = 0;
    int j = 0;
    int row = matrix.size();
    int col = matrix[0].size();
    int maximum = 0;
    int ans = solve(matrix, i, j, row, col, maximum);
    cout << ans << endl;
    return maximum * maximum;
}

int main()
{
    return 0;
}