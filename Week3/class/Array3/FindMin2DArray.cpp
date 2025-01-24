#include <iostream>
#include <climits>
using namespace std;

int searchIn2D(int arr[][4], int rowSize, int colSize)
{
    int minValue = INT_MAX;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            minValue = min(arr[i][j], minValue);
        }
    }

    return minValue;
}

int searchIn2DPrac(int arr[][4], int rowSize, int colSize)
{

    int minVal = INT_MAX;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            if (arr[i][j] < minVal)
                minVal = arr[i][j];
        }
    }
    return minVal;
}

int main()
{

    // vector<vector<int>> arr(4, vector<int>(3, 0));

    // int rowSize = arr.size();
    // int colSize = arr[0].size();

    int arr[3][4]{
        {-11, 2, 3, 4},
        {11, 22, 33, -44},
        {12, 21, 32, 45},
    };

    int rowSize = 3;
    int colSize = 4;

    int ans = searchIn2DPrac(arr, rowSize, colSize);

    cout << "ans is: " << ans << endl;

    return 0;
}