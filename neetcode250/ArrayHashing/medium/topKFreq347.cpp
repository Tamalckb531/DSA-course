#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    //! Bucket sort approach from Neetcode

    unordered_map<int, int> count;
    vector<vector<int>> freq(nums.size() + 1);

    //? Count freq first
    for (auto num : nums)
    {
        count[num]++;
    }

    //? store each number as bucket by using their frequency as their index
    for (auto elem : count)
    {
        freq[elem.second].push_back(elem.first);
    }

    //? Retrieve the bucket from last to get the most freq element first
    vector<int> ans;
    for (int i = freq.size() - 1; i >= 0; i--)
    {
        for (auto num : freq[i])
        {
            //? as the bucket might have multiple elem -> like multi elem has same freq
            if (k == 0)
                return ans;
            ans.push_back(num);
            k--;
        }
    }

    return ans;
}

int main()
{
    cout << "LeetCode 347. Top K Frequent Elements" << endl;
}