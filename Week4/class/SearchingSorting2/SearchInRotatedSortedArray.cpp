#include <iostream>
#include <vector>
using namespace std;

int pivotFinder(vector<int> &nums, int start, int end)
{
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        //? one element edge case:
        if (start == end)
            return start;

        //? mid is the pivot
        if (mid + 1 <= end && nums[mid] > nums[mid + 1])
            return mid;

        //? mid is in the right
        else if (nums[mid] < nums[start])
            end = mid - 1;

        //? mid is in the left
        else
            start = mid + 1;

        mid = start + (end - start) / 2;
    }

    return -1;
}

int binarySearch(vector<int> &nums, int start, int end, int target)
{
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (nums[mid] == target)
            return mid;
        else if (target > nums[mid])
            start = mid + 1;
        else
            end = mid - 1;
        mid = start + (end - start) / 2;
    }

    return -1;
}

int searchPractice(vector<int> &nums, int target)
{
    int end = nums.size() - 1;
    int pivotIndex = pivotFinder(nums, 0, end);

    //? target in 0 to pivotIndex range
    if (target >= nums[0] && target <= nums[pivotIndex])
        return binarySearch(nums, 0, pivotIndex, target);

    //? target in pivotIndex+1 to end range
    if (pivotIndex + 1 <= end && target >= nums[pivotIndex + 1] && target <= nums[end])
        return binarySearch(nums, pivotIndex + 1, end, target);

    return -1;
}
int main()
{
    return 0;
}