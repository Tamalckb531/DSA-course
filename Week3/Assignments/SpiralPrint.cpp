#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> ans;

    int total = row * col;
    int count = 0;

    // Index Initialize
    int startingCol = 0;
    int startingRow = 0;
    int endingCol = col - 1;
    int endingRow = row - 1;

    while (count < total)
    {

        // Printing the starting row
        for (int i = startingCol; i <= endingCol && count < total; i++)
        {
            ans.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;

        // Printing the ending col
        for (int i = startingRow; i <= endingRow && count < total; i++)
        {
            ans.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;

        // Printing the ending row
        for (int i = endingCol; i >= startingCol && count < total; i--)
        {
            ans.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;

        // Printing the starting col
        for (int i = endingRow; i >= startingRow && count < total; i--)
        {
            ans.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;
    }

    return ans;
}

int main()
{
    cout << endl;
    return 0;
}