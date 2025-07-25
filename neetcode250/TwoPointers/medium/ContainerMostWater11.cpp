#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxArea(vector<int> &height)
{
    int left = 0;
    int right = height.size() - 1;
    int maxarea = INT_MIN;

    while (left < right)
    {
        maxarea = max(maxarea, (min(height[left], height[right]) * (right - left)));

        if (height[left] <= height[right])
            left++;
        else
            right--;
    }

    return maxarea;
}
int main()
{
    cout << "LeetCode 11. Container With Most Water" << endl;
}