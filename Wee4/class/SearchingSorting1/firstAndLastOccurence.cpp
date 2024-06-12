#include <iostream>
#include <vector>
using namespace std;

void findFirstOccurence(vector<int> &nums, int n, int target, int &firstPosition)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (nums[mid] == target)
        {
            firstPosition = mid;
            end = mid - 1;
        }
        else if (target > nums[mid])
        {
            start = mid + 1;
        }
        else if (target < nums[mid])
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }
}

void findLastOccurence(vector<int> &nums, int n, int target, int &lastPosition)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (nums[mid] == target)
        {
            lastPosition = mid;
            start = mid + 1;
        }
        else if (target > nums[mid])
        {
            start = mid + 1;
        }
        else if (target < nums[mid])
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int n = nums.size();

    int firstPosition = -1;
    findFirstOccurence(nums, n, target, firstPosition);

    int lastPosition = -1;
    findLastOccurence(nums, n, target, lastPosition);

    vector<int> temp;

    temp.push_back(firstPosition);
    temp.push_back(lastPosition);

    return temp;
}

int main()
{
    return 0;
}