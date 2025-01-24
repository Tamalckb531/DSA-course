#include <iostream>
using namespace std;

bool searchIn2D(int arr[][4], int rowSize, int colSize, int target)
{
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            if (arr[i][j] == target)
            {
                return true;
            }
        }
    }

    return false;
}

bool searchIn2DPrac(int arr[][4], int rowSize, int colSize, int target)
{
    for (int row = 0; row < rowSize; row++)
    {
        for (int col = 0; col < colSize; col++)
        {
            if (arr[row][col] == target)
                return true;
        }
    }

    return false;
}

int main()
{

    // vector<vector<int>> arr(4, vector<int>(3, 0));

    // int rowSize = arr.size();
    // int colSize = arr[0].size();

    int arr[3][4]{
        {1, 2, 3, 4},
        {11, 22, 33, 44},
        {12, 21, 32, 45},
    };

    int rowSize = 3;
    int colSize = 4;
    int target = 33;

    bool ans = searchIn2DPrac(arr, rowSize, colSize, target);

    cout << "ans is: " << ans << endl;

    return 0;
}