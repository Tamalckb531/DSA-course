#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//? TC:0(n)
//? SC:0(n)
void rotate(vector<int> &nums, int k)
{
    vector<int> temp;
    int n = nums.size() - 1;
    k = k % nums.size();

    for (int i = n - k + 1; i <= n; i++)
    {
        temp.push_back(nums[i]);
    }

    for (int i = 0; i <= n - k; i++)
    {
        temp.push_back(nums[i]);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = temp[i];
    }
}

//? TC: O(n)
//? SC: O(1)
void rotate(vector<int> &nums, int k)
{
    int n = nums.size() - 1;
    k %= n + 1;

    reverse(nums, 0, n);
    reverse(nums, 0, k - 1);
    reverse(nums, k, n);
}

void reverse(vector<int> &nums, int start, int end)
{
    while (start < end)
    {
        swap(nums[start++], nums[end--]);
    }
}
int main()
{
    cout << "LeetCode 189. Rotate Array" << endl;
}