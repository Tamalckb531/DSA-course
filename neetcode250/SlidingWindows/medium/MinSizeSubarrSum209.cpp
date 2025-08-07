#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//? Sliding Window: TC:O(n), SC:O(1)
int minSubArrayLen(int target, vector<int> &nums)
{
    int left = 0;
    int size = nums.size();
    int minLen = INT_MAX;
    int sum = 0;

    for (int right = 0; right < size; right++)
    {
        sum += nums[right];
        while (sum >= target)
        {
            minLen = min(minLen, right - left + 1);
            sum -= nums[left++];
        }
    }

    if (minLen == INT_MAX)
        return 0;

    return minLen;
}

int main()
{
    cout << "LeetCode 209. Minimum Size Subarray Sum" << endl;
}
