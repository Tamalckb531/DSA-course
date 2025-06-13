#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool rowCheck(vector<vector<char>> &board)
{
    for (int row = 0; row < 9; row++)
    {
        unordered_set<char> seen;
        for (int j = 0; j < 9; j++)
        {
            if (board[row][j] == '.')
                continue;
            if (seen.count(board[row][j]))
                return false;
            seen.insert(board[row][j]);
        }
    }
    return true;
}
bool colCheck(vector<vector<char>> &board)
{
    for (int col = 0; col < 9; col++)
    {
        unordered_set<char> seen;
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == '.')
                continue;
            if (seen.count(board[i][col]))
                return false;
            seen.insert(board[i][col]);
        }
    }
    return true;
}
bool boxCheck(vector<vector<char>> &board)
{
    for (int box = 0; box < 9; box++)
    {
        unordered_set<char> seen;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int row = (box / 3) * 3 + i;
                int col = (box % 3) * 3 + j;

                if (board[row][col] == '.')
                    continue;
                if (seen.count(board[row][col]))
                    return false;
                seen.insert(board[row][col]);
            }
        }
    }

    return true;
}

bool isValidSudoku(vector<vector<char>> &board)
{
    bool row = rowCheck(board);
    bool col = colCheck(board);
    bool box = boxCheck(board);

    return row && col && box;
}

//! This solution need to be studied
bool bitMaskValid(vector<vector<char>> &board)
{
    int rows[9] = {0};
    int cols[9] = {0};
    int squares[9] = {0};

    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            if (board[r][c] == '.')
                continue;

            int val = board[r][c] - '1';

            //? checking seen
            if ((rows[r] & (1 << val)) || (cols[c] & (1 << val)) ||
                (squares[(r / 3) * 3 + (c / 3)] & (1 << val)))
            {
                return false;
            }

            //? making seen
            rows[r] |= (1 << val);
            cols[c] |= (1 << val);
            squares[(r / 3) * 3 + (c / 3)] |= (1 << val);
        }
    }

    return true;
}

int main()
{
    cout << "LeetCode 36. Valid Sudoku" << endl;
}

//? check