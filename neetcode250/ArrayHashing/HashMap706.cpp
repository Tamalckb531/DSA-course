#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class MyHashMap
{
private:
    vector<int> data;

public:
    MyHashMap() : data(1000001, -1) {}

    void put(int key, int value)
    {
        data[key] = value;
    }

    int get(int key)
    {
        return data[key];
    }

    void remove(int key)
    {
        data[key] = -1;
    }
};

int main()
{
    cout << "LeetCode 706. Design HashMap" << endl;
}