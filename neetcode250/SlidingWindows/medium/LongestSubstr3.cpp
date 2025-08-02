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

//? Sliding window : TC:O(n), SC:O(s.size())
int lengthOfLongestSubstring(string s)
{
    int ans = 0;
    unordered_set<char> charSet;
    int left = 0;

    for (int right = 0; right < s.size(); right++)
    {
        while (charSet.find(s[right]) != charSet.end())
        {
            charSet.erase(s[left]); //? removing from scratch to duplicate to maintain sub str
            left++;                 //? sliding the window of sub string
        }
        charSet.insert(s[right]);
        ans = max(ans, (right - left + 1));
    }

    return ans;
}
int main()
{
    cout << "LeetCode 3. Longest Substring Without Repeating Characters" << endl;
}
