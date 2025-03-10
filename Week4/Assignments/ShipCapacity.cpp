#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

bool isPossibleToShip(vector<int> &weights, int capacity, int totalPackages, int totalDays)
{
    int weightSum = 0;
    int day = 1; //? adding weight from day 1

    for (int i = 0; i < totalPackages; i++)
    {
        if (weights[i] > capacity)
            return false;

        if (weightSum + weights[i] > capacity)
        {
            day++;                  //? need to send that package in next day
            weightSum = weights[i]; //? first weight allocation to that day

            if (day > totalDays)
                return false; //? less capaciy, more day
        }
        else
        {
            weightSum += weights[i];
        }
    }

    return true; //? all days can be covered with that capacity
}

int shipWithinDays(vector<int> &weights, int days)
{
    int totalPackages = weights.size();
    int totalDays = days;

    //? search space on total weights
    int start = 0;
    int end = accumulate(weights.begin(), weights.end(), 0);
    int mid = start + (end - start) / 2; //? at most weight for each day
    int ans = 0;

    while (start <= end)
    {
        if (isPossibleToShip(weights, mid, totalPackages, totalDays))
        {
            ans = mid;
            end = mid - 1; //? we need the least weight capacity
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }

    return ans;
}