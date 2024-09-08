#include <bits/stdc++.h>
using namespace std;

//? take each coin -> get it's recursive Possibility total coin -> add the coin in used -> compare it with it's siblings and store in miniCoinAns
//? CONSTRAINS : Don't need to call recursion if coin is greater than amount -> If all possibility is bigger than amount that it's recursionAns will be INT_MAX, So don't add it up.

int solve(vector<int> &coins, int amount)
{

    //? Base case
    if (amount == 0)
        return 0;

    //? Processing
    int minimumAns = INT_MAX;
    for (auto coin : coins)
    {
        if (coin <= amount)
        {
            int recursionAns = solve(coins, amount - coin);
            if (recursionAns != INT_MAX)
            {
                int usedCoin = 1 + recursionAns;
                minimumAns = min(minimumAns, usedCoin);
            }
        }
    }

    return minimumAns;
}

int coinChange(vector<int> &coins, int amount)
{
    int ans = solve(coins, amount);

    if (ans == INT_MAX)
        return -1;

    return ans;
}