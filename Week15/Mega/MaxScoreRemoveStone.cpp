#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
    //? Push the initial state in a maxHeap -> get the top two (as they are bigger ones), decrease them by one, increase the score count and insert those two state again if they greater than 0

public:
    int maximumScore(int a, int b, int c)
    {
        //? step 1: pushing the initial state in a maxHeap

        priority_queue<int, vector<int>> maxHeap;

        maxHeap.push(a);
        maxHeap.push(b);
        maxHeap.push(c);

        //? step 2 : get top two and process

        int score = 0;

        while (maxHeap.size() > 1)
        { //? condition will work on at least two non-zero pile condition
            int pile1 = maxHeap.top();
            maxHeap.pop();

            int pile2 = maxHeap.top();
            maxHeap.pop();

            pile1--;
            pile2--;
            score++;

            if (pile1 > 0)
                maxHeap.push(pile1);
            if (pile2 > 0)
                maxHeap.push(pile2);
        }

        return score;
    }
};