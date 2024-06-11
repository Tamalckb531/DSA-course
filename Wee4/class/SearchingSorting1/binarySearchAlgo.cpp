#include <iostream>
#include <vector>
using namespace std;
int search(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;
    // int mid = (start+end)/2;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (nums[mid] == target)
            return mid;
        else if (target > nums[mid])
            start = mid + 1;
        else if (target < nums[mid])
            end = mid - 1;
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    return 0;
}