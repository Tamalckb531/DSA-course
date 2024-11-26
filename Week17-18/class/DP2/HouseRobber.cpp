#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int index)
    {
        if (index >= nums.size())
            return 0;

        int include = nums[index] + solve(nums, index + 2);
        int exclude = 0 + solve(nums, index + 1);

        return max(include, exclude);
    }

    int solveMem(vector<int> &nums, int index, vector<int> &dp)
    {
        if (index >= nums.size())
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int include = nums[index] + solveMem(nums, index + 2, dp);
        int exclude = 0 + solveMem(nums, index + 1, dp);

        dp[index] = max(include, exclude);

        return dp[index];
    }

    int solveTab(vector<int> &nums)
    {
        int n = nums.size();

        //? create dp array
        vector<int> dp(n + 2, -1);

        //? base case analysis
        dp[n] = 0;
        dp[n + 1] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            int include = nums[i] + dp[i + 2];
            int exclude = 0 + dp[i + 1];
            dp[i] = max(include, exclude);
        }

        return dp[0];
    }

    int solveTabSO(vector<int> &nums)
    {
        int n = nums.size();

        int next1 = 0;
        int next2 = 0;
        int curr;

        for (int i = n - 1; i >= 0; i--)
        {
            int include = nums[i] + next2;
            int exclude = 0 + next1;
            curr = max(include, exclude);

            //? shifting
            next2 = next1;
            next1 = curr;
        }

        return curr;
    }

    int rob(vector<int> &nums)
    {
        //? recursion
        // return solve(nums,0);

        //? Memoization
        // int n = nums.size();
        // vector<int> dp(n+1 , -1);
        // return solveMem(nums, 0, dp);

        //? Tabulation
        // return solveTab(nums);

        //? space optimization
        return solveTabSO(nums);
    }
};