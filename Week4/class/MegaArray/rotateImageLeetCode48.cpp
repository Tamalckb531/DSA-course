#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int nrows = matrix.size();
    int ncols = matrix[0].size();

    //? traspose the matrix: row <--> col
    for (int i = 0; i < nrows; i++)
    {
        for (int j = i; j < ncols; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    //? rotate the matrix with reverse:
    for (int i = 0; i < nrows; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

void rotatePractice(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int columns = matrix[0].size();

    //? transpose the matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = i; j < columns; j++)
        {
            //? j starting from i as we swaping
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    //? reverse each array inside matrix
    for (int i = 0; i < rows; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    return 0;
}