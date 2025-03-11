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

bool isCowPlacementPossible(vector<int> &stalls, int totalCows, int stallSize, int minimumDis)
{
    int cowCount = 1;
    int cowPos = stalls[0]; //? first cow placed

    for (int i = 1; i < stallSize; i++)
    {

        int nextCowPlacementDistance = stalls[i] - cowPos;

        if (nextCowPlacementDistance >= minimumDis)
        {
            //? can place the cow
            cowCount++;
            cowPos = stalls[i]; //? newly cow placement position
        }

        if (cowCount == totalCows)
            return true; //? all cow placed
    }

    return false; //? all cow not placed
}

int aggressiveCows(vector<int> &stalls, int k)
{

    int totalCows = k;
    int n = stalls.size();
    sort(stalls.begin(), stalls.end()); //? sorted as we need the max distance for bianry search

    //? search space for stall
    int start = 0;
    int end = stalls[n - 1] - stalls[0]; //? max distance
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        if (isCowPlacementPossible(stalls, totalCows, n, mid))
        {
            ans = mid;
            start = mid + 1; //? search for the max
        }
        else
        {
            //? cow not placeed for over distance
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return ans;
}

int main()
{
    return 0;
}
