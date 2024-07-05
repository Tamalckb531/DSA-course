#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPlacementPossible(vector<int> &stalls, int totalCow, int minimumDistance)
{
    int cowCount = 1;
    int cowPos = stalls[0];

    // first cow is placed

    for (int i = 1; i < stalls.size(); i++)
    {

        int nextCowPosDistance = stalls[i] - cowPos;

        if (nextCowPosDistance >= minimumDistance)
        {
            // place the next cow
            cowCount++;
            cowPos = stalls[i];
        }

        // all cow is placed
        if (cowCount == totalCow)
            return true;
    }

    return false; // all cow isn't placed
}

int solve(int n, int k, vector<int> &stalls)
{
    // Write your code here
    sort(stalls.begin(), stalls.end());
    int totalCow = k;

    int start = 0;
    int end = stalls[n - 1] - stalls[0];
    int mid = start + (end - start) / 2;

    int ans = -1;

    while (start <= end)
    {
        if (isPlacementPossible(stalls, totalCow, mid))
        {
            ans = mid;
            start = mid + 1; // to get the max minimunDistance
        }
        else
        {
            end = mid - 1; // Distance can't place cow or larger than max -> search for less
        }
        mid = start + (end - start) / 2;
    }

    return ans;
}

int main()
{
    return 0;
}
