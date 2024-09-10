#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &nums, int index)
{

    if (index == nums.size() - 1)
        return true;
    if (index >= nums.size())
        return false;
    if (nums[index] == 0)
        return false;

    bool recAns = false;
    for (int jump = 1; jump <= nums[index]; jump++)
    {
        recAns = recAns || solve(nums, index + jump);
    }
    return recAns;
}

bool canJump(vector<int> &nums)
{
    return solve(nums, 0);
}