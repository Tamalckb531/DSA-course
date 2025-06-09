#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void countNumbers(vector<int> &nums)
{
    int zero = 0;
    int one = 0;

    for (auto num : nums)
    {
        if (num == 0)
            zero++;
        if (num == 1)
            one++;
    }

    int index = 0;
    while (zero && index < nums.size())
    {
        nums[index++] = 0;
        zero--;
    }
    while (one && index < nums.size())
    {
        nums[index++] = 1;
        one--;
    }
    while (index < nums.size())
    {
        nums[index++] = 2;
    }
}
void DutchNationalFlag(vector<int> &nums)
{
    //? Just push zero in left and two in right while traversing through the entire array
    int left = 0;
    int traverse = 0;
    int right = nums.size() - 1;

    while (traverse <= right)
    {
        if (nums[traverse] == 0)
        {
            swap(nums[left++], nums[traverse++]);
        }
        else if (nums[traverse] == 2)
        {
            swap(nums[right--], nums[traverse]);
        }
        else
            traverse++;
    }
}

void sortColors(vector<int> &nums)
{
    countNumbers(nums);
    DutchNationalFlag(nums);
}

int main()
{
    cout << "LeetCode 75. Sort Colors" << endl;
}