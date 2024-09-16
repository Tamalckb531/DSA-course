#include <bits/stdc++.h>
using namespace std;

unordered_map<int, bool> rowCheck;
unordered_map<int, bool> upperDiagonalCheck;
unordered_map<int, bool> lowerDiagonalCheck;

bool isSafe(int row, int col, vector<vector<char>> &board)
{
    //? rowCheck || upperDiagonalCheck || lowerDiagonalCheck

    if (rowCheck[row])
    {
        return false;
    }

    if (upperDiagonalCheck[row - col])
    {
        return false;
    }

    if (lowerDiagonalCheck[row + col])
    {
        return false;
    }

    return true;
}

void solve(int &ans, vector<vector<char>> &board, int &n, int col)
{

    //? base case
    if (col >= n)
    {
        ans = ans + 1;
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board))
        {
            board[row][col] = 'Q';
            rowCheck[row] = true;
            upperDiagonalCheck[row - col] = true;
            lowerDiagonalCheck[row + col] = true;

            solve(ans, board, n, col + 1);

            //? backtracking
            board[row][col] = '.';
            rowCheck[row] = false;
            upperDiagonalCheck[row - col] = false;
            lowerDiagonalCheck[row + col] = false;
        }
    }
}
int totalNQueens(int n)
{
    int ans;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    int col = 0;
    solve(ans, board, n, col);
    return ans;
}