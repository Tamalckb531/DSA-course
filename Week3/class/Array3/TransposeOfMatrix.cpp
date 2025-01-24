#include <iostream>
using namespace std;

void transposeMatrix(int arr[][3], int rowSize, int colSize)
{
    int ansArray[100][100] = {0};

    //? Initializing the ansArray
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            ansArray[i][j] = arr[j][i];
        }
    }

    //? printing the ansArray
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            cout << ansArray[i][j] << " ";
        }
        cout << endl;
    }
}

//? without making a new array
void transposeMatrix2(int arr[][3], int rowSize, int colSize)
{
    //? swapping array element
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = i; j < colSize; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    //? printing the ansArray
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void transposeMatrixPrac(int arr[][3], int rowSize, int colSize)
{
    //? swap with upper triangle -> getting rid of double swap
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = i; j < colSize; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    //? Printing the array
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "Transpose of Matrix" << endl;
    int arr[3][3]{
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90},
    };

    int rowSize = 3;
    int colSize = 3;

    // transposeMatrix(arr, rowSize, colSize);
    transposeMatrixPrac(arr, rowSize, colSize);
    return 0;
}