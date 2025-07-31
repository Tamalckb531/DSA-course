#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//? Brute Force -> TC:O(n^2), SC:O(1)
int trap(vector<int> &height)
{
    int n = height.size() - 1;
    int waterTrapped = 0;

    for (int i = 0; i <= n; i++)
    {
        int leftWall = height[i];
        int rightWall = height[i];

        //? Finding max leftWall
        for (int j = 0; j < i; j++)
        {
            leftWall = max(leftWall, height[j]);
        }
        //? Finding max rightWall

        for (int k = i + 1; k <= n; k++)
        {
            rightWall = max(rightWall, height[k]);
        }
        waterTrapped += min(leftWall, rightWall) - height[i];
    }

    return waterTrapped;
}

//? Prefix-Suffix -> TC:O(n), SC:O(n)
int trap(vector<int> &height)
{
    if (height.empty())
        return 0;
    int n = height.size() - 1;
    int waterTrapped = 0;
    vector<int> LeftMax(n + 1);
    vector<int> RightMax(n + 1);

    LeftMax[0] = height[0];
    for (int i = 1; i <= n; i++)
    {
        LeftMax[i] = max(height[i], LeftMax[i - 1]);
    }

    RightMax[n] = height[n];
    for (int i = n - 1; i >= 0; i--)
    {
        RightMax[i] = max(height[i], RightMax[i + 1]);
    }

    for (int i = 0; i <= n; i++)
    {
        int leftWall = LeftMax[i];
        int rightWall = RightMax[i];
        waterTrapped += min(leftWall, rightWall) - height[i];
    }

    return waterTrapped;
}

//? Two pointer -> TC:O(n), SC:O(1)

int trap(vector<int> &height)
{
    if (height.empty())
        return 0;
    int size = height.size();
    int left = 0;
    int right = size - 1;
    int leftMaxWall = height[left];
    int rightMaxWall = height[right];
    int waterTrapped = 0;

    while (left < right)
    {
        if (leftMaxWall < rightMaxWall)
        {
            left++;
            leftMaxWall = max(height[left], leftMaxWall);
            waterTrapped += leftMaxWall - height[left];
        }
        else
        {
            right--;
            rightMaxWall = max(height[right], rightMaxWall);
            waterTrapped += rightMaxWall - height[right];
        }
    }

    return waterTrapped;
}
int main()
{
    cout << "LeetCode 42. Trapping Rain Water" << endl;
}