#include <iostream>
#include <vector>
using namespace std;

// Given a sorted array arr[] of size N, some elements of array are moved to either of the adjacent positions, i.e, arr[i] may be present at arr[i-1] i.e arr[i] can only be swapped with either arr[i+1] or arr[i-1]. The task is to search for an element in this array.

// Input arr[] = {10,3,40,20,60,80,70}, key = 40
// Output : 2

int binary_search(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid + 1] == target)
        {
            return mid + 1;
        }
        if (arr[mid - 1] == target)
        {
            return mid - 1;
        }

        // left
        if (arr[mid] > target)
        {
            end = mid - 2;
        }
        // right
        else
        {
            start = mid + 2;
        }

        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{

    int arr[] = {10, 3, 40, 20, 60, 80, 70};
    int size = 7;

    int target = 80;

    int targetIndex = binary_search(arr, size, target);
    cout << "Target Index in this nearly sorted array is: " << targetIndex << endl;

    return 0;
}