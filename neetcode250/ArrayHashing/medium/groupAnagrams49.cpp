#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> map;
    vector<vector<string>> ans;

    for (string str : strs)
    {
        string key = str;
        sort(key.begin(), key.end());
        map[key].push_back(str);
    }

    for (auto entry : map)
    {
        ans.push_back(entry.second);
    }

    return ans;
}

int main()
{
    cout << "LeetCode 49. Group Anagrams" << endl;
}