#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
                return {i, j};
        }
    }
    return {};
}

int main()
{
    cout << "LeetCode 1. Two Sum" << endl;
}