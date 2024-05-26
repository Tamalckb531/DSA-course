#include <iostream>
using namespace std;

int maxNum(int arr[], int size)
{
    int max = INT32_MIN;
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int arr[5] = {10, 59, -59, 98, 78};
    int size = 5;

    int maxi = maxNum(arr, size);
    cout << maxi << endl;
    return 0;
}