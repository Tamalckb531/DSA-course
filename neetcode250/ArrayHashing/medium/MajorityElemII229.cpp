#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//? Boyer-Moore's Voting Algo -> SC:O(1)
vector<int> majorityElement(vector<int> &nums)
{
    int candidate1 = 0;
    int count1 = 0;
    int candidate2 = 0;
    int count2 = 0;

    //? Find potential candidates
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == candidate1)
            count1++;
        else if (nums[i] == candidate2)
            count2++;
        else if (count1 == 0)
        {
            candidate1 = nums[i];
            count1 = 1;
        }
        else if (count2 == 0)
        {
            candidate2 = nums[i];
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    //? Verify if their count satisfy n/3
    count1 = 0;
    count2 = 0;
    vector<int> ans;
    int n = nums.size();

    for (auto num : nums)
    {
        if (num == candidate1)
            count1++;
        else if (num == candidate2)
            count2++;
    }

    if (count1 > n / 3)
        ans.push_back(candidate1);
    if (count2 > n / 3)
        ans.push_back(candidate2);

    return ans;
}

//? Brute Force -> SC:O(n)
vector<int> majorityElement(vector<int> &nums)
{
    unordered_map<int, int> hash;
    vector<int> ans;

    for (int num : nums)
    {
        hash[num]++;
    }

    int times = nums.size() / 3;

    for (auto hs : hash)
    {
        if (hs.second > times)
        {
            ans.push_back(hs.first);
        }
    }

    return ans;
}
int main()
{
    cout << "LeetCode 229. Majority Element II" << endl;
}

//? check