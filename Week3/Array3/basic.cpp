#include <iostream>
using namespace std;

int main()
{
    cout << "This is 2D array : " << endl;

    //? declaring and traversal of 2D array
    int arr[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90},
    };

    // int arr[3][2] = {10, 20};

    // cout << arr[2][1] << endl;

    //? RowWise Traversal
    // int rowSize = 3;
    // int colSize = 3;
    // for (int rowIn = 0; rowIn < rowSize; rowIn++)
    // {
    //     for (int colIn = 0; colIn < colSize; colIn++)
    //     {
    //         cout << arr[rowIn][colIn] << " ";
    //     }
    //     cout << endl;
    // }

    //? Column wise Traversal
    // int rowSize = 3;
    // int colSize = 3;
    // for (int colIn = 0; colIn < colSize; colIn++)
    // {
    //     for (int rowIn = 0; rowIn < rowSize; rowIn++)
    //     {
    //         cout << arr[rowIn][colIn] << " ";
    //     }
    //     cout << endl;
    // }

    //? Diagonal Traversal
    // int rowSize = 3;
    // int colSize = 3;
    // for (int rowIn = 0; rowIn < rowSize; rowIn++)
    // {
    //     for (int colIn = 0; colIn < colSize; colIn++)
    //     {
    //         if (rowIn == colIn)
    //         {

    //             cout << arr[rowIn][colIn] << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    //? Anti-Diagonal Traversal
    // int rowSize = 3;
    // int colSize = 3;
    // for (int rowIn = 0; rowIn < rowSize; rowIn++)
    // {
    //     for (int colIn = 0; colIn < colSize; colIn++)
    //     {
    //         if (rowIn + colIn == rowSize - 1)
    //         {
    //             cout << arr[rowIn][colIn] << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    //? Input taking

    return 0;
}