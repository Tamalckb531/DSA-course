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
int main()
{
    cout << "LeetCode 42. Trapping Rain Water" << endl;
}