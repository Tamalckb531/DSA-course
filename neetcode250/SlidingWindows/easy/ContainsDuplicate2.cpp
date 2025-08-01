#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//? Brute Force: TC:O(n^2), SC:O(1);
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    int size = nums.size();

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (nums[i] == nums[j] && abs(i - j) <= k)
                return true;
        }
    }

    return false;
}

//? Sliding Window: TC:O(n), SC:O(k);
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_set<int> window;

    for (int i = 0; i < nums.size(); i++)
    {
        if (window.count(nums[i]))
            return true;
        window.insert(nums[i]);

        //? Sliding the window by deleting the i-k th value from the nums array
        if (window.size() > k)
            window.erase(nums[i - k]);
    }

    return false;
}
int main()
{
    cout << "LeetCode 219. Contains Duplicate II" << endl;
}