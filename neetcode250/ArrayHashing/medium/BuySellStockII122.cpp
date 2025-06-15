#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int profit = 0;
    for (int i = 0; i < prices.size() - 1; i++)
    {
        if (prices[i + 1] > prices[i])
            profit += prices[i + 1] - prices[i];
    }
    return profit;
}
int main()
{
    cout << "LeetCode 122. Best Time to Buy and Sell Stock II" << endl;
}

//? check