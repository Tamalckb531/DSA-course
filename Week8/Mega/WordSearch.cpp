#include <bits/stdc++.h>
using namespace std;

//? Just like rate in maze : Traverse whole array to find the first word -> check if it has the other words as neighbour by solve -> if so then return true or return false
//? solve function : store the char in temp -> mark visited -> recursive call to found the up, down, left, right direction words -> backtracking for new word search -> return true when the word index reach word size -> return false when row, col out of bound, board char don't match word char, board row,col is visited

bool solve(vector<vector<char>> &board, string &word, int row, int col, int index)
{

    if (index == word.size())
        return true;

    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[index] || board[row][col] == '$')
    {
        return false;
    }

    char temp = board[row][col];
    board[row][col] = '$'; // visited;

    bool result = solve(board, word, row - 1, col, index + 1)     // up
                  || solve(board, word, row + 1, col, index + 1)  // down
                  || solve(board, word, row, col + 1, index + 1)  // right
                  || solve(board, word, row, col - 1, index + 1); // left

    board[row][col] = temp; // backtracking / unvisited

    return result;
}

bool exist(vector<vector<char>> &board, string word)
{
    int index = 0;
    for (int row = 0; row < board.size(); row++)
    {
        for (int col = 0; col < board[0].size(); col++)
        {
            if (solve(board, word, row, col, index))
            {
                return true;
            }
        }
    }
    return false;
}