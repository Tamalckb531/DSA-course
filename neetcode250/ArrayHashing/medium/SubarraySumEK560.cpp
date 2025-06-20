#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//? TC : O(n^3); SC : O(1)
int subarraySum(vector<int> &nums, int k)
{
    int total = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            int count = 0;
            for (int m = i; m <= j; m++)
            {
                count += nums[m];
            }
            if (count == k)
                total++;
        }
    }
    return total;
}

//? TC : O(n^2); SC : O(1)
int subarraySum(vector<int> &nums, int k)
{
    int total = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if (sum == k)
                total++;
        }
    }
    return total;
}

//? TC: O(n); SC: O(n)

//! Explanation : we set sum 0 count to 1 in previous of loop -> now if we add and add the num until k, the diff will be 0 and that will return us 1 from prefixSum which is count of one subarray, that's how we can get sub array from the start -> now lets say, we encountered a currSum of x before so if diff comes x that means from the start point to x currSum, we have a reducible array and the after reduce point to currPoint is gonna be a subArray of sum k

int subarraySum(vector<int> &nums, int k)
{
    int res = 0, currSum = 0;
    unordered_map<int, int> prefixSums;
    prefixSums[0] = 1;

    for (int num : nums)
    {
        currSum += num;
        int diff = currSum - k;
        res += prefixSums[diff];
        prefixSums[currSum]++;
    }
    return res;
}
int main()
{
    cout << "LeetCode 560. Subarray Sum Equals K" << endl;
}

//? check