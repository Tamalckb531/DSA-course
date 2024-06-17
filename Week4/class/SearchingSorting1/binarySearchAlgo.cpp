#include <iostream>
#include <vector>
#include <algorithm>
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
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = 9;
    int target = 70;
    int target2 = 700;

    bool ans = binary_search(arr, arr + n, target);
    bool ans2 = binary_search(arr, arr + n, target2);
    cout << ans << endl;
    cout << ans2 << endl;
    return 0;
}