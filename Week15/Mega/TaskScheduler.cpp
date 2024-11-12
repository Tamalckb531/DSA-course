#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution
{
    //? make a freqMap for all task and store them on a maxHeap -> schedule task maintaining the constrain of n, push the new task and count the time
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        //? step 1 -> Make a freqMap for all task and store them on a maxHeap
        unordered_map<char, int> freq;
        for (auto task : tasks)
            freq[task]++;

        priority_queue<pair<int, char>, vector<pair<int, char>>> maxHeap;

        for (auto e : freq)
            maxHeap.push({e.second, e.first});

        //? step 2 -> Schedule task maintaining the constrain of n, push the new task and count the time
        //* A task can come after n cycle. Including the first count it will be n+1, that's why we mantain the n+1 cycle state
        //* storing the new freq in a temp as we need the new entry in heap, only more than 0 freq will enter the temp
        //* if cycle that means idle time. So we adding this to the time

        int time = 0;
        while (!maxHeap.empty())
        {
            int cycle = n + 1;
            vector<pair<int, char>> temp;

            while (cycle > 0 && !maxHeap.empty())
            {
                auto [freq, task] = maxHeap.top();
                maxHeap.pop();
                freq--;
                time++;
                cycle--;
                // push remaining tasks
                temp.push_back({freq, task});
            }

            for (auto leftTask : temp)
            {
                if (leftTask.first > 0)
                    maxHeap.push(leftTask);
            }

            // adding idle time
            if (!maxHeap.empty())
                time += cycle;
        }
        return time;
    }
};