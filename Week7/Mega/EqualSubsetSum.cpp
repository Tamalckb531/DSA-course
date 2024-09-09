#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &nums, int target, int index)
{
    if (target == 0)
        return true;
    if (target < 0 || index == nums.size())
        return false;

    int include = solve(nums, target - nums[index], index + 1);
    int exclude = solve(nums, target, index + 1);

    return include || exclude;
}
bool canPartition(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if ((sum % 2) != 0)
        return false; // odd sum

    int target = sum >> 1; // sum/2;

    return solve(nums, target, 0);
}