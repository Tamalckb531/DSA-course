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

    int solveUsingDP(int n, vector<int> &dp)
    {
        if (n == 0 || n == 1)
            return n;

        if (dp[n] != -1)
            return dp[n];

        dp[n] = solveUsingDP(n - 1, dp) + solveUsingDP(n - 2, dp);
        return dp[n];
    }

    int fib(int n)
    {
        vector<int> dp(n + 1, -1);
        int ans = solveUsingDP(n, dp);
        return ans;
    }
};

int main()
{
    return 0;
}