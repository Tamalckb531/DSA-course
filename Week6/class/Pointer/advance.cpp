#include <iostream>
using namespace std;

// void solve(int arr[], int size)
// {
//     //? in function, array pass as a pointer. Not as an array. So arr is a pointer here
//     cout << sizeof(arr) << endl; //? size would be 8
// }

int main()
{
    // int arr[] = {10, 20, 30, 40, 50};
    // int size = 5;

    // solve(arr, size);

    //? Double Pointer

    // int a = 5;
    // int *b = &a;
    // int **c = &b;

    // cout << **c << endl;

    //? Stack and Heap memory

    //* stack memory
    // int a = 5;
    // cout << a << endl;

    //* heap memory
    // int *p = new int;
    // / *p = 5;
    // cout << *p << endl;
    // delete p;

    //* 1d array
    // int *ptr = new int[5];
    // ptr[0] = 1;
    // ptr[1] = 2;
    // ptr[2] = 3;
    // cout << ptr[0] << ptr[1] << ptr[2] << endl;

    //* 2d array
    int **ptr = new int *[4];

    // 4 -> row count
    // 3 -> col count

    for (int i = 0; i < 4; i++)
    {
        // each pointer allocated with 1d array
        ptr[i] = new int[3];
    }

    // taking input

    cout << "Give the input : " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "Row : " << i << endl;
        for (int j = 0; j < 3; j++)
        {
            cin >> ptr[i][j];
        }
    }

    // printing array

    cout << endl
         << "Printing the 2D Array : " << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << ptr[i][j] << ' ';
        }
        cout << endl;
    }

    // cleaning

    for (int i = 0; i < 4; i++)
    {
        delete[] ptr[i];
    }

    return 0;
}