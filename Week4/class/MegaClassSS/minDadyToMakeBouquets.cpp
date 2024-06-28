#include <iostream>
#include <vector>
using namespace std;

bool canMakeBouquet(vector<int> &bloomDay, int bouquet, int flower, int day)
{
    int count = 0;

    for (int i = 0; i < bloomDay.size(); i++)
    {

        // flower bloomed so can be use to make a bouquet
        if (bloomDay[i] <= day)
        {
            count++;
        }

        // got enough flower to make a bouquet
        if (count == flower)
        {
            bouquet--;
            count = 0; // to start counting flower again to make another bouquet after this one
            if (bouquet == 0)
                break; // made all the the required bouquet
        }

        // flower is not bloomed
        if (bloomDay[i] > day)
        {
            count = 0; // as this flower is not adjacent
        }
    }

    return bouquet == 0; // If all bouquet making done than it will return true.
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    long long int bouquet = m;
    long long int flower = k;
    long long int flowerReq = bouquet * flower;
    int totalFlower = bloomDay.size();

    if (totalFlower < flowerReq)
        return -1;

    int start = *min_element(bloomDay.begin(), bloomDay.end());
    int end = *max_element(bloomDay.begin(), bloomDay.end());
    int day = start + (end - start) / 2;
    int ans = 0;

    while (start <= end)
    {
        if (canMakeBouquet(bloomDay, bouquet, flower, day))
        {
            ans = day;
            end = day - 1;
        }
        else
        {
            start = day + 1;
        }

        day = start + (end - start) / 2;
    }

    return ans;
}

int main()
{
    return 0;
}