#include <iostream>
#include <queue>
using namespace std;

class MedianFinder
{
public:
    //? for num > median : minHeap && num < median : maxHeap

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        //? 3 cases

        //* case 1 :
        if (maxHeap.size() == minHeap.size())
        {
            if (num > findMedian())
            {
                minHeap.push(num);
            }
            else
            {
                maxHeap.push(num);
            }
        }

        //* case 2 :
        if (maxHeap.size() > minHeap.size())
        {
            if (num > findMedian())
            {
                minHeap.push(num);
            }
            else
            {
                //? maxHeap is indistributed, so we need to pop an element from it and insert in the minHeap
                int element = maxHeap.top();
                maxHeap.pop();
                minHeap.push(element);

                maxHeap.push(num);
            }
        }

        //* case 3 :
        if (maxHeap.size() < minHeap.size())
        {
            if (num > findMedian())
            {
                //? minHeap is undistributed, so we need to pop an element from it and insert in the maxHeap
                int element = minHeap.top();
                minHeap.pop();
                maxHeap.push(element);

                minHeap.push(num);
            }
            else
            {
                maxHeap.push(num);
            }
        }
    }

    double findMedian()
    {
        if (maxHeap.size() == 0 && minHeap.size() == 0)
        {
            return 0;
        }
        else if (maxHeap.size() == minHeap.size())
        {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else if (maxHeap.size() > minHeap.size())
        {
            return maxHeap.top();
        }
        else if (maxHeap.size() < minHeap.size())
        {
            return minHeap.top();
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    return 0;
}