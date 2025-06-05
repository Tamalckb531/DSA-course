#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

//? Hashmap solution -> TC O(n), SC O(n)
int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> majorityMap;

    for (auto num : nums)
    {
        majorityMap[num]++;
    }

    int maxCount = INT_MIN;
    int number = -1;
    for (auto node : majorityMap)
    {
        if (node.second > maxCount)
        {
            maxCount = node.second;
            number = node.first;
        }
    }

    return number;
}

//? Boyer-Moore Voting Algorithm -> TC O(n), SC O(1)
int majorityElement(vector<int> &nums)
{
    int candidate = nums[0];
    int count = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (candidate != nums[i])
        {
            count--;
            if (count == 0)
            {
                candidate = nums[i];
                count = 1;
            }
        }
        else
            count++;
    }

    return candidate;
}

int main()
{
    cout << "LeetCode 169. Majority Element" << endl;
}