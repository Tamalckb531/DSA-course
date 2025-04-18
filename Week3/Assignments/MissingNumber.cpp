#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int SortAndIndexElemCompare(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i != nums[i])
            return i;
    }
    return nums.size();
}

int BitwiseXORMethod(vector<int> &nums)
{
    int ans = 0;

    // XOR all element of the array
    for (int i = 0; i < nums.size(); i++)
    {
        ans ^= nums[i];
    }

    // XOR all range value
    for (int i = 0; i <= nums.size(); i++)
    {
        ans ^= i;
    }

    return ans;
}

int BitWiseXORMethodPrac(vector<int> &nums)
{
    int missingNum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        missingNum ^= nums[i];
    }

    for (int i = 0; i <= nums.size(); i++)
    {
        missingNum ^= i;
    }

    return missingNum;
}

int main()
{
    return 0;
}