#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{

    //? Store all value in a map with there frequency -> take a minHeap and store the map values in a pair where the sorting should be with the freq -> in Heap, pop the top if size got more than k as the top will be least freq -> store the value of k element in heap in a ans vector and return it.

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        //? step 1:
        unordered_map<int, int> freqMap; //? it will store in value,freq format

        for (auto num : nums)
            freqMap[num]++;

        //? step 2:

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto pairVal : freqMap)
        {
            minHeap.push({pairVal.second, pairVal.first}); //? second on top as we need to sort according to least in top format
            if (minHeap.size() > k)
            {
                minHeap.pop(); //? least got pop
            }
        }

        //? step 3:

        vector<int> ans;
        while (!minHeap.empty())
        {
            auto [freq, value] = minHeap.top();
            minHeap.pop();
            ans.push_back(value);
        }

        return ans;
    }
};