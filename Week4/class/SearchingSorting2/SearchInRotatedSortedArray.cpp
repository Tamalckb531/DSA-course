#include <iostream>
#include <vector>
using namespace std;

int getPivotIndex(vector<int> &arr)
{
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        // edge case for one element
        if (start == end)
        {
            return start;
        }
        // if mid is the pivot
        if (mid + 1 < n && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        // if mid is in the right side
        else if (arr[start] > arr[mid])
        {
            end = mid - 1;
        }
        // if mid is in the left side
        else
        {
            start = mid + 1;
        }

        // mid update
        mid = start + (end - start) / 2;
    }

    return -1;
}

int binarySearch(int start, int end, vector<int> &arr, int target)
{
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    return -1;
}

int search(vector<int> &nums, int target)
{
    // Step 1: get the pivot
    int pivotIndex = getPivotIndex(nums);

    // Step 2: find the target
    int n = nums.size();

    // if target left side of pivot
    if (target >= nums[0] && target <= nums[pivotIndex])
    {
        int targetIndex = binarySearch(0, pivotIndex, nums, target);
        return targetIndex;
    }

    // if target right side of pivot
    if (pivotIndex + 1 < n && target >= nums[pivotIndex + 1] && target <= nums[n - 1])
    {
        int targetIndex = binarySearch(pivotIndex + 1, n - 1, nums, target);
        return targetIndex;
    }
    return -1;
}

int main()
{
    return 0;
}