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

int linearSearchPractice(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int main()
{
    cout << "Linear Search! " << endl
         << endl;

    int arr[5] = {10, 20, 30, 40, 50};
    int size = 5;
    int target = 35;

    // int index = linearSearch(arr, size, target);
    int index = linearSearchPractice(arr, size, target);

    // cout << index;
    cout << index;

    cout << endl;
    return 0;
}