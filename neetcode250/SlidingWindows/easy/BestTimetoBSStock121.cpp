#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//? Brute Force: TC:O(n^2), SC:O(1);
int maxProfit(vector<int> &prices)
{

    int maxProfit = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i + 1; j < prices.size(); j++)
        {
            int profit = prices[j] - prices[i];
            maxProfit = max(maxProfit, profit);
        }
    }

    return maxProfit;
}

//? Two pointer -> TC:O(n), SC:O(1)
//* Here we just need to get stuck in the lowest price

int maxProfit(vector<int> &prices)
{
    int low = 0;  //? This will get stuck in the lowest price while traversing
    int high = 1; //? This will traverse
    int maxProfit = 0;

    while (high < prices.size())
    {
        if (prices[high] > prices[low])
            maxProfit = max((prices[high] - prices[low]), maxProfit);
        else
            low = high; //? Getting stuck in low logic
        high++;
    }

    return maxProfit;
}
int main()
{
    cout << "LeetCode 121. Best Time to Buy and Sell Stock" << endl;
}