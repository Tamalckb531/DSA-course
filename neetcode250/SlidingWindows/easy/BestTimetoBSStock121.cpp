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
int main()
{
    cout << "LeetCode 121. Best Time to Buy and Sell Stock" << endl;
}