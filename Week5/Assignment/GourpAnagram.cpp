#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<vector<string>> groupAnagramsMethod1(vector<string> &strs)
{
    map<string, vector<string>> stringMap;

    // first: map all the value with there sorted string as a key

    for (auto str : strs)
    {
        string sortStr = str;
        sort(sortStr.begin(), sortStr.end());
        stringMap[sortStr].push_back(str);
    }

    // second: iterate the map and store the values in answer

    vector<vector<string>> ans;
    for (auto it = stringMap.begin(); it != stringMap.end(); it++)
    {
        ans.push_back(it->second);
    }

    return ans;
}

int main()
{
}