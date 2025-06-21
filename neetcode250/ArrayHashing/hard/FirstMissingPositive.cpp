#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//? Brute Force : TC: O(nlogn) SC: O(1) or O(n) depending on sorting algo
int firstMissingPositive(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int missing = 1;
    for (auto num : nums)
    {
        if (num > 0 && missing == num)
            missing++;
    }
    return missing;
}

//? Cycle Sort: TC: O(n) SC: O(1)
int firstMissingPositive(vector<int> &nums)
{
    int range = nums.size();
    int i = 0;

    while (i < range)
    {
        int num = nums[i];
        if (num <= 0 || num > range)
        {
            i++;
            continue;
        }

        int index = num - 1; //? Number is 1 based but index is 0 based. So this gives the index-number mapping index of that num

        if (num != nums[index])
        {
            swap(nums[i], nums[index]);
        }
        else
        {
            i++;
        }
    }

    for (int i = 0; i < range; i++)
    {
        if (nums[i] != i + 1)
            return i + 1;
    }

    return range + 1;
}

int main()
{
    cout << "LeetCode 41. First Missing Positive" << endl;
}

//? check