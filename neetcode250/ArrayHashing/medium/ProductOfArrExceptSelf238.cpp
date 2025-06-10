#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> productExceptSelf(vector<int> &nums)
{
    int size = nums.size();

    vector<int> rightProd(nums.size(), 1);
    vector<int> leftProd(nums.size(), 1);
    vector<int> ans(nums.size(), 1);

    leftProd[0] = 1;
    rightProd[size - 1] = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        leftProd[i] = leftProd[i - 1] * nums[i - 1];
    }

    for (int i = size - 2; i >= 0; i--)
    {
        rightProd[i] = rightProd[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < nums.size(); i++)
    {
        ans[i] = leftProd[i] * rightProd[i];
    }

    return ans;
}

int main()
{
    cout << "LeetCode: Encode and Decode Strings" << endl;
}