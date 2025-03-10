#include <iostream>
#include <algorithm>
using namespace std;

void reverseArray(int arr[], int n)
{
    int l = 0, h = n - 1;

    while (l < h)
    {
        arr[l] = arr[l] ^ arr[h];
        arr[h] = arr[h] ^ arr[l];
        arr[l] = arr[l] ^ arr[h];
        l++;
        h--;
    }
}
void reverseArray2(int arr[], int n)
{
    int l = 0;
    int h = n - 1;

    while (l < h)
    {
        arr[l] = arr[l] ^ arr[h];
        arr[h] = arr[l] ^ arr[h];
        arr[l] = arr[l] ^ arr[h];
        l++;
        h--;
    }
}

int main()
{
    int arr[7] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    // M1. custom reversal using 2-pointer approach
    reverseArray2(arr, n);

    // M2. STL, C++ lib
    // reverse(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}