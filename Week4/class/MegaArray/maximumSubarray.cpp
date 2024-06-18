#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int ans = INT_MIN;
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];      // get the sum
        ans = max(ans, sum); // compare
        // kadane's logic of dropping the sum to zero for -ve sum
        if (sum < 0)
            sum = 0;
    }

    return ans;
}

int main()
{
    return 0;
}