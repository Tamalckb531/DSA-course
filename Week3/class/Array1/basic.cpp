#include <iostream>
using namespace std;

void solve(int num[], int size)
{
    for (int i = 0; i < size; i++)
    {
        num[i] = num[i] + 10;
    }
}

int main()
{
    cout << "Array 1!" << endl;

    /*
        //? creation
        int arr[10];
        int brr[] = {1, 2, 3, 4, 5};

        cout << brr[1] << endl;
        cout << arr[5] << endl;
        cout << arr[101] << endl; // will print garbage value
    */

    /*
        //? fill

        int arr[4];

        fill(arr, arr + 4, 23);

        cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << endl;

    */

    /*

    //? input taking

    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    */

    //? Functions in array

    int arr[5] = {0};
    int size = 5;

    solve(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}