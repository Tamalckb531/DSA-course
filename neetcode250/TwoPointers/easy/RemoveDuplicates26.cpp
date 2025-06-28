#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    int shifter = 0;
    int traverser = 0;

    while (shifter < n)
    {
        nums[traverser] = nums[shifter];
        while (shifter < n && nums[traverser] == nums[shifter])
            shifter++;
        traverser++;
    }

    return traverser;
}

int main()
{
    cout << "LeetCode 26. Remove Duplicates from Sorted Array" << endl;
}