#include <iostream>
#include <climits>
using namespace std;

void printEven(int arr[], int size, int index)
{
    //? base case
    if (index == size)
        return;
    //? Processing
    if (arr[index] % 2 == 0)
    {
        cout << arr[index] << endl;
    }
    //? Recursive call
    printEven(arr, size, index + 1);
}

int main()
{

    int arr[] = {20, 21, 30, 31, 50, 51};
    int size = 6;
    int index = 0;
    printEven(arr, size, index);

    cout << endl
         << "maximum" << endl;
    return 0;
}