#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solveRec(int n, int k)
    {
        if (n == 1)
            return k;
        if (n == 2)
            return k * k;

        int ans = (k - 1) * (solveRec(n - 1, k) + solveRec(n - 2, k));
        return ans;
    }

    int solveMem(int n, int k, vector<int> &dp)
    {
        if (n == 1)
            return k;
        if (n == 2)
            return k * k;
        if (dp[n] != -1)
            return dp[n];

        dp[n] = (k - 1) * (solveMem(n - 1, k, dp) + solveMem(n - 2, k, dp));
        return dp[n];
    }

    int solveTab(int n, int k)
    {
        vector<int> dp(n + 1, 0);

        dp[1] = k;
        dp[2] = k * k;

        for (int i = 3; i <= n; i++)
        {
            dp[i] = (k - 1) * (dp[i - 1] + dp[i - 2]);
        }

        return dp[n];
    }

    int solveTabSO(int n, int k)
    {

        int prev2 = k;
        int prev1 = k * k;

        for (int i = 3; i <= n; i++)
        {
            int curr = (k - 1) * (prev1 + prev2);

            //? shifting
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int countWays(int n, int k)
    {
        //? ------- Recursion -------
        // return solveRec(n,k);

        //? ------- Memoization -------
        // vector<int> dp(n+1, -1);
        // return solveMem(n,k,dp);

        //? ------- Tabulation -------
        return solveTab(n, k);

        //? ------- Space Optimized -------
        return solveTabSO(n, k);
    }
};

int main()
{
    return 0;
}