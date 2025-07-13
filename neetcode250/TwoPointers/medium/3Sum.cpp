#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    //? Sort nums
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    for (int i = 0; i < nums.size(); i++)
    {
        //? Any number greater than 0 means the right of them are also greater than 0. So no need to check.
        if (nums[i] > 0)
            break;
        //? Reducing similar numbers
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int l = i + 1, r = nums.size() - 1;
        while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum > 0)
                r--;
            else if (sum < 0)
                l++;
            else
            {
                res.push_back({nums[i], nums[l], nums[r]});
                l++;
                r--;
                while (l < r && nums[l] == nums[l - 1])
                {
                    l++;
                }
            }
        }
    }

    return res;
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
            break;
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1, right = nums.size() - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum < 0)
                left++;
            else if (sum > 0)
                right--;
            else
            {
                ans.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;
                while (left < right && nums[left] == nums[left - 1])
                {
                    left++;
                }
            }
        }
    }

    return ans;
}

int main()
{
    cout << "LeetCode 15. 3Sum" << endl;
}