#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class MinStack
{
public:
    //? v.back() return the last value of vector, so it acts like the last in first out method of stack

    vector<pair<int, int>> v;
    MinStack()
    {
    }

    void push(int val)
    {
        if (v.empty())
        {
            v.push_back({val, val});
            return;
        }

        v.push_back({val, v.back().second < val ? v.back().second : val});
    }

    void pop()
    {
        v.pop_back();
    }

    int top()
    {
        return v.back().first;
    }

    int getMin()
    {
        return v.back().second;
    }
};