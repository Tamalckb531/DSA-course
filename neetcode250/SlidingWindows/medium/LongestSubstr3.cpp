#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//? Brute Force: TC:O(n^2), SC:O(n)
int lengthOfLongestSubstring(string s)
{
    int longestSubstr = 0;

    for (int i = 0; i < s.length(); i++)
    {
        unordered_set<char> charSet;
        for (int j = i; j < s.length(); j++)
        {
            if (charSet.find(s[j]) != charSet.end())
            {
                break;
            }
            charSet.insert(s[j]);
        }
        longestSubstr = max(longestSubstr, (int)charSet.size());
    }

    return longestSubstr;
}
int main()
{
    cout << "LeetCode 3. Longest Substring Without Repeating Characters" << endl;
}