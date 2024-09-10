#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, int index, int step, int &ans)
{

    if (index == nums.size() - 1)
    {
        ans = min(ans, step);
        return;
    }
    if (index >= nums.size())
        return;

    for (int jump = 1; jump <= nums[index]; jump++)
    {
        solve(nums, index + jump, step + 1, ans);
    }
}

bool canJump(vector<int> &nums)
{
    int step = 0;
    int ans = INT_MAX;
    solve(nums, 0, step, ans);
    return ans;
}