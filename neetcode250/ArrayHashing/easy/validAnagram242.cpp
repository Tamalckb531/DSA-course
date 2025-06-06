#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t)
{
    unordered_map<char, int> mapping;

    for (int i = 0; i < s.length(); i++)
    {
        mapping[s[i]]++;
    }
    for (int i = 0; i < t.length(); i++)
    {
        mapping[t[i]]--;
    }

    for (auto map : mapping)
    {
        if (map.second != 0)
            return false;
    }

    return true;
}

int main()
{
    cout << "LeetCode 242. Valid Anagram" << endl;
}