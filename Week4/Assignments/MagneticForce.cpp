#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isBallPlaced(vector<int> &position, int size, int minimumForce, int totalBall)
{
    int ballCount = 1;
    int ballPos = position[0]; //? first ball placed

    for (int i = 1; i < size; i++)
    {
        int nextBallPosDistance = position[i] - ballPos;

        if (nextBallPosDistance >= minimumForce)
        {
            ballCount++;
            ballPos = position[i];
        }

        if (ballCount == totalBall)
            return true;
    }

    return false;
}

int maxDistance(vector<int> &position, int m)
{
    int totalBall = m;
    int n = position.size();
    sort(position.begin(), position.end());

    //? search space on positions
    int start = 0;
    int end = position[n - 1] - position[0];
    int mid = start + (end - start) / 2;
    int ans = 0;

    while (start <= end)
    {
        if (isBallPlaced(position, n, mid, totalBall))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    return ans;
}