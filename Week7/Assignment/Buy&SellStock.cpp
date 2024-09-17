#include <bits/stdc++.h>
using namespace std;
void profitFinder(vector<int> &prices, int &minPrice, int &maxProfit, int i)
{

    if (i == prices.size())
        return;

    int todayPrice = prices[i];
    if (todayPrice < minPrice)
        minPrice = todayPrice;
    int todayProfit = todayPrice - minPrice;
    if (todayProfit > maxProfit)
        maxProfit = todayProfit;

    profitFinder(prices, minPrice, maxProfit, i + 1);
}

int maxProfit(vector<int> &prices)
{
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;
    int dayIndex = 0;

    profitFinder(prices, minPrice, maxProfit, dayIndex);
    return maxProfit;
}