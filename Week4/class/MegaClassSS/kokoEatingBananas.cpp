#include <iostream>
#include <vector>
using namespace std;

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