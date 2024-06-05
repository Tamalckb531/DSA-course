
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

int main()
{
    int n;
    int arr[] = {1, 3, 5, 3, 3};
    n = sizeof(arr) / sizeof(int);
    findMissing(arr, n);
    return 0;
}