#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solve(vector<int> &coins, int amount)
{

    //? Base case
    if (amount == 0)
        return 0;

    //? Processing
    int minimumCoin = INT_MAX;
    for (auto coin : coins)
    {
        if (coin <= amount)
        {
            int recursionCoinAns = solve(coins, amount - coin);
            if (recursionCoinAns != INT_MAX)
            {
                int usedCoin = 1 + recursionCoinAns;
                minimumCoin = min(minimumCoin, usedCoin);
            }
        }
    }

    return minimumCoin;
}

int solveMem(vector<int> &coins, int amount, vector<int> &dp)
{

    //? Base case
    if (amount == 0)
        return 0;

    //? Memo
    if (dp[amount] != -1)
        return dp[amount];

    //? Processing
    int minimumCoin = INT_MAX;
    for (auto coin : coins)
    {
        if (coin <= amount)
        {
            int recursionCoinAns = solveMem(coins, amount - coin, dp);
            if (recursionCoinAns != INT_MAX)
            {
                int usedCoin = 1 + recursionCoinAns;
                minimumCoin = min(minimumCoin, usedCoin);
            }
        }
    }

    dp[amount] = minimumCoin;
    return dp[amount];
}

int solveTab(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, -1);

    dp[0] = 0;

    for (int amt = 1; amt <= amount; amt++)
    {
        int minimumCoin = INT_MAX;
        for (auto coin : coins)
        {
            if (coin <= amt)
            {
                int recursionCoinAns = dp[amt - coin];
                if (recursionCoinAns != INT_MAX)
                {
                    int usedCoin = 1 + recursionCoinAns;
                    minimumCoin = min(minimumCoin, usedCoin);
                }
            }
        }

        dp[amt] = minimumCoin;
    }

    return dp[amount];
}

int coinChange(vector<int> &coins, int amount)
{

    //? Recursion
    // int ans =  solve(coins, amount);

    // if(ans == INT_MAX) return -1;

    // return ans;

    //? Memoization

    // vector<int> dp(amount+1, -1);
    // int ans =  solveMem(coins, amount, dp);

    // if(ans == INT_MAX) return -1;

    // return ans;

    //? Tabulation

    int ans = solveTab(coins, amount);

    if (ans == INT_MAX)
        return -1;

    return ans;
}

int main()
{
    return 0;
}