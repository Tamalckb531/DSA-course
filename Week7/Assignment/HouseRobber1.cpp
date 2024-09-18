#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int index)
{

    if (index >= nums.size())
        return 0;

    int robAmt1 = nums[index] + solve(nums, index + 2); //? loot the first skip the adjacent
    int robAmt2 = 0 + solve(nums, index + 1);           //? skip the first loot the adjacent

    return max(robAmt1, robAmt2);
}

int rob(vector<int> &nums)
{
    return solve(nums, 0);
}

int main()
{
    return 0;
}