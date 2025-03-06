#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

//? make a search space from 0 to max in piles for speed -> Do binary search on that -> validate the speed, if validate than store and compute for less speed -> if no validate than increase the speed

//? Validate speed : Get the sum of total hour needed to complete each piles with the speed -> if it's less or equal to h than speed valid.

bool validateSpeed(int speed, vector<int> &piles, int hour)
{
    long long totalHours = 0;

    for (int i = 0; i < piles.size(); i++)
    {
        totalHours += ceil(piles[i] / (double)speed);
    }

    return totalHours <= hour;
}

int minEatingSpeedPractice(vector<int> &piles, int h)
{
    int start = 1;
    auto it = max_element(piles.begin(), piles.end());
    int end = *it;
    int mid = start + (end - start) / 2;
    int minimumSpeed = -1;

    while (start <= end)
    {
        int speed = mid;
        if (validateSpeed(speed, piles, h))
        {
            minimumSpeed = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }

    return minimumSpeed;
}

bool speedValidator(vector<int> &piles, int hour, int speed)
{
    long long int totalHour = 0;

    for (int i = 0; i < piles.size(); i++)
    {
        totalHour += ceil(piles[i] / (double)speed);
    }

    return totalHour <= hour;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int start = 1;
    auto it = max_element(piles.begin(), piles.end());
    int end = *it;
    int mid = start + (end - start) / 2;
    int ans = 0;

    while (start <= end)
    {
        int speed = mid;

        if (speedValidator(piles, h, speed))
        {
            ans = speed;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }

    return ans;
}

int main()
{
    return 0;
}