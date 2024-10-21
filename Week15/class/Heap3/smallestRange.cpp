#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Info
{
public:
    int data;
    int rIndex;
    int cIndex;
    Info(int a, int b, int c)
    {
        data = a;
        rIndex = b;
        cIndex = c;
    }
};

class compare
{
public:
    bool operator()(Info *a, Info *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        priority_queue<Info *, vector<Info *>, compare> pq;

        vector<int> ans;

        int maxi = INT_MIN;
        int mini = INT_MAX;

        int totalRows = nums.size();

        for (int row = 0; row < totalRows; row++)
        {
            int element = nums[row][0];
            Info *temp = new Info(element, row, 0);
            pq.push(temp);
            maxi = max(maxi, element);
            mini = min(mini, element);
        }

        int ans_start = mini;
        int ans_end = maxi;

        while (!pq.empty())
        {
            Info *front = pq.top();
            pq.pop();

            int frontData = front->data;
            int front_rIndex = front->rIndex;
            int front_cIndex = front->cIndex;

            mini = frontData;

            if ((maxi - mini) < (ans_end - ans_start))
            {
                ans_start = mini;
                ans_end = maxi;
            }

            int currTotalColumns = nums[front_rIndex].size();

            if (front_cIndex + 1 < currTotalColumns)
            {
                int element = nums[front_rIndex][front_cIndex + 1];
                Info *temp = new Info(element, front_rIndex, front_cIndex + 1);
                maxi = max(maxi, element);
                mini = min(mini, element);
                pq.push(temp);
            }
            else
            {
                break;
            }
        }
        ans.push_back(ans_start);
        ans.push_back(ans_end);
        return ans;
    }
};