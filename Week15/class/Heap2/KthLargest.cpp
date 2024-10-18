#include <iostream>
#include <queue>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }

        for (int i = k; i < nums.size(); i++)
        {
            int element = nums[i];

            if (element > pq.top())
            {
                pq.pop();
                pq.push(element);
            }
        }

        int ans = pq.top();
        return ans;
    }
};