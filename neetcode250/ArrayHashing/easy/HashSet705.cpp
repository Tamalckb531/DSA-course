#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class MyHashSet
{
private:
    vector<int> data;

public:
    MyHashSet()
    {
    }

    void add(int key)
    {
        if (find(data.begin(), data.end(), key) == data.end())
        {
            data.push_back(key);
        }
    }

    void remove(int key)
    {
        auto it = find(data.begin(), data.end(), key);

        if (it != data.end())
        {
            data.erase(it);
        }
    }

    bool contains(int key)
    {
        auto it = find(data.begin(), data.end(), key);
        return it != data.end();
    }
};

int main()
{
    cout << "LeetCode 705. Design HashSet" << endl;
}