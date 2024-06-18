#include <iostream>
#include <vector>
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

int main()
{
    return 0;
}