#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        int currentElem = arr[i];
        if (currentElem == target)
        {
            return i + 1;
        }
    }
    return -1;
}

int main()
{
    cout << "Linear Search! " << endl
         << endl;

    int arr[5] = {10, 20, 30, 40, 50};
    int size = 5;
    int target = 93;

    int index = linearSearch(arr, size, target);

    cout << index;

    cout << endl;
    return 0;
}