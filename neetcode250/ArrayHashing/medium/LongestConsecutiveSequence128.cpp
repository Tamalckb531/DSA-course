#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> numberSet(nums.begin(), nums.end()); //? insert all elements of nums in numberset
    int maxConsecutive = 0;

    for (auto num : numberSet)
    {
        if (numberSet.find(num - 1) == numberSet.end())
        {
            //? Can't find so prev so new consequence
            int length = 1;
            while (numberSet.find(num + length) != numberSet.end())
            {
                length++;
            }
            maxConsecutive = max(length, maxConsecutive);
        }
    }

    return maxConsecutive;
}

int main()
{
    cout << "LeetCode 128. Longest Consecutive Sequence" << endl;
}

//? check