#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution
{
public:
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

    bool solveMem(vector<int> &nums, int target, int index, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (target < 0 || index == nums.size())
            return false;

        if (dp[target][index] != -1)
            return dp[target][index];

        int include = solve(nums, target - nums[index], index + 1);
        int exclude = solve(nums, target, index + 1);

        dp[target][index] = include || exclude;

        return dp[target][index];
    }

    bool solveTab(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<bool>> dp(target + 1, vector<bool>(n + 1, 0));

        for (int col = 0; col <= n; col++)
            dp[0][col] = true;

        for (int t = 1; t <= target; t++)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                bool include = 0;
                if (t - nums[i] >= 0)
                    include = dp[t - nums[i]][i + 1];
                bool exclude = dp[t][i + 1];

                dp[t][i] = include || exclude;
            }
        }

        return dp[target][0];
    }

    bool solveTabSO(vector<int> &nums, int target)
    {
        int n = nums.size();

        vector<int> curr(target + 1, 0);
        vector<int> next(target + 1, 0);

        for (int col = 0; col <= n; col++)
            next[0] = true;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int t = 1; t <= target; t++)
            {
                bool include = 0;
                if (t - nums[i] >= 0)
                {
                    include = next[t - nums[i]];
                }
                bool exclude = next[t];
                curr[t] = include || exclude;
            }
            next = curr;
        }

        return next[target];
    }

    bool canPartition(vector<int> &nums)
    {
        //? ---------- Recursion ----------
        // int sum = accumulate(nums.begin(), nums.end(), 0);
        // if((sum % 2) != 0) return false; // odd sum

        // int target = sum >> 1; // sum/2;

        // return solve(nums, target, 0);

        //? ---------- Memoization ----------
        // int n = nums.size();
        // int sum = accumulate(nums.begin(), nums.end(), 0);
        // if((sum % 2) != 0) return false; // odd sum

        // int target = sum >> 1; // sum/2;

        // vector<vector<int>> dp(target+1, vector<int>(n+1, -1));

        // return solveMem(nums, target, 0, dp);

        //? ---------- Tabulation ----------
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum % 2) != 0)
            return false; // odd sum

        int target = sum >> 1; // sum/2;
        return solveTab(nums, target);
    }
};