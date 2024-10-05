#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeQueue(queue<int> &q1)
    {
        vector<int> ans;
        queue<int> q2;

        int half = q1.size() / 2;

        while (half--)
        {
            int element = q1.front();
            q1.pop();
            q2.push(element);
        }

        int size = q2.size();
        while (size--)
        {
            int element1 = q2.front();
            q2.pop();
            ans.push_back(element1);

            int element2 = q1.front();
            q1.pop();
            ans.push_back(element2);
        }

        return ans;
    }
};

int main()
{
    return 0;
}