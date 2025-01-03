#include <iostream>
#include <climits>
using namespace std;

// int maxNum(int arr[], int size)
// {
//     int max = INT32_MIN;
//     for (int i = 0; i < size; i++)
//     {
//         if (max < arr[i])
//         {
//             max = arr[i];
//         }
//     }
//     return max;
// }

int maxNum(int arr[], int size)
{
    int maxi = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (maxi < arr[i])
            maxi = arr[i];
    }
    return maxi;
}

int minNum(int arr[], int size)
{
    int mini = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (mini > arr[i])
            mini = arr[i];
    }
    return mini;
}

int main()
{
    int arr[5] = {10, 159, 59, 98, 178};
    int size = 5;

    int maxi = maxNum(arr, size);
    int mini = minNum(arr, size);
    cout << maxi << endl;
    cout << mini << endl;
    return 0;
}