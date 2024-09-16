#include <bits/stdc++.h>
using namespace std;

//? Traverse the board -> find the empty cell -> create a 1-9 loop for digit -> check digit is safe and place that -> call recursive to see if the next digits are placing -> if not than remove the digit from board else return true
//? If the digit loop end that means no digit is placed for the prev incorrect digit: return false -> if the traverse completed that means every digit placed well: return true
//? isSafe -> do rowCheck with 0-8 loop -> do colCheck same -> do block check by the formula : newRow = (3 * (row / 3)) + (k / 3) ; newCol = (3 * (col / 3)) + (k % 3);

bool isSafe(int digit, int row, int col, vector<vector<char>> &board)
{
    //? rowCheck || colCheck || 3*3 box check
    int n = board.size();

    //? rowCheck
    for (int k = 0; k < n; k++)
    {
        if (board[k][col] == digit)
        {
            return false;
        }
    }

    //? colCheck
    for (int k = 0; k < n; k++)
    {
        if (board[row][k] == digit)
        {
            return false;
        }
    }

    //? 3*3 box check
    for (int k = 0; k < n; k++)
    {
        int newRow = (3 * (row / 3)) + (k / 3);
        int newCol = (3 * (col / 3)) + (k % 3);
        if (board[newRow][newCol] == digit)
        {
            return false;
        }
    }

    return true;
}

bool solve(vector<vector<char>> &board)
{

    //? traverse the board
    int n = board.size();
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (board[row][col] == '.')
            {
                for (char digit = '1'; digit <= '9'; digit++)
                {
                    if (isSafe(digit, row, col, board))
                    {
                        board[row][col] = digit;
                        bool isSolved = solve(board);
                        if (isSolved)
                        {
                            return true;
                        }
                        else
                        {
                            board[row][col] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
}