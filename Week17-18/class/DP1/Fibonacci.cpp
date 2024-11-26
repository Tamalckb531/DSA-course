#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solveUsingRec(int n)
    {
        //? base case:
        if (n == 0 || n == 1)
            return n;

        int ans = solveUsingRec(n - 1) + solveUsingRec(n - 2);
        return ans;
    }

    int solveUsingMemo(int n, vector<int> &dp)
    {
        if (n == 0 || n == 1)
            return n;

        if (dp[n] != -1)
            return dp[n];

        dp[n] = solveUsingMemo(n - 1, dp) + solveUsingMemo(n - 2, dp);
        return dp[n];
    }

    int solveUsingTabulation(int n)
    {
        //? create dp array
        vector<int> dp(n + 1, -1);

        //! safe check
        if (n == 0)
            return 0; // as it will create a run time error for dp[1] access

        //? base case analysis
        dp[0] = 0;
        dp[1] = 1;

        //? check parameter and make a reverse loop without taking the base case -> write the rec logic inside as a array based logic
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 2] + dp[i - 1];
        }

        return dp[n];
    }

    int fib(int n)
    {
        // vector<int>dp(n+1,-1);
        // int ans = solveUsingMemo(n,dp);
        // return ans;

        int ans = solveUsingTabulation(n);
        return ans;
    }
};

int main()
{
    return 0;
}