#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int start = 0;
    int end = row * col - 1;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        int rowIndex = mid / col;
        int colIndex = mid % col;

        int element = matrix[rowIndex][colIndex];

        if (element == target)
        {
            return 1;
        }

        if (element < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return 0;
}

bool searchMatrixPractice(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int start = 0;
    int end = row * col - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        int rowIndex = mid / col;
        int colIndex = mid % col;

        int element = matrix[rowIndex][colIndex];

        if (element == target)
            return 1;
        else if (element < target)
            start = mid + 1;
        else
            end = mid - 1;

        mid = start + (end - start) / 2;
    }

    return -1;
}

int main()
{
    return 0;
}