#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int binarySearchRec(int arr[], int s, int e, int target)
{
    //? base case
    if (s > e)
        return -1;

    //? processing
    int mid = (s + e) / 2;

    if (arr[mid] == target)
        return mid;

    //? recursive call
    if (target > arr[mid])
    {
        return binarySearchRec(arr, mid + 1, e, target);
    }
    else
    {
        return binarySearchRec(arr, s, mid - 1, target);
    }
}

int main()
{

    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int size = 7;

    int target = 60;

    int ans = binarySearchRec(arr, 0, size - 1, target);

    cout << "Binary search with recursion result : " << ans << endl;
    return 0;
}