
#include <iostream>
#include <vector>
using namespace std;

void findMissing(int *arr, int n)
{
    // visiting array element with -ve them
    for (int arrayIndex = 0; arrayIndex < n; arrayIndex++)
    {
        int elementIndex = abs(arr[arrayIndex]);

        if (arr[elementIndex - 1] > 0)
        {
            arr[elementIndex - 1] *= -1;
        }
    }

    // Now all positive numbers are non-visited, which means their index are missing elements.
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            cout << i + 1 << " ";
        }
    }

    cout << endl;
}

void findMissingPrac(int *arr, int n)
{
    //? make all elementIndex element negative
    //? we will count index from 1 as per range
    for (int i = 0; i < n; i++)
    {
        int elementIndex = abs(arr[i]);
        if (arr[elementIndex - 1] > 0)
            arr[elementIndex - 1] *= -1;
    }

    //? now check which element is still positive and return it's index (with add 1 we counting index from 1)
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            cout << i + 1 << " ";
    }

    cout << endl;
}

int main()
{
    int n;
    int arr[] = {3, 3, 3, 3, 3};
    n = sizeof(arr) / sizeof(int);
    findMissingPrac(arr, n);
    return 0;
}