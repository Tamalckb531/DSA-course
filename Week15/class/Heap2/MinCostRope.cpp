#include <iostream>
#include <queue>
using namespace std;

//? first insert all rope length in a min heap ->
//? join two top and add there cost ->
//? push the joined length in the min heap again ->
//? Do this until there is only one value in the heap and return the totalCost

class Solution
{
public:
    long long minCost(vector<long long> &arr)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq; //? min heap for minimum cost

        for (auto i : arr)
        {
            pq.push(i);
        }

        long long cost = 0;

        while (pq.size() != 1)
        {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();

            long long totalLength = first + second;

            cost += totalLength;

            pq.push(totalLength);
        }

        return cost;
    }
};