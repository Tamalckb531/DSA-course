#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//? Brute Force: TC:O(n^2), SC:O(m)
int characterReplacement(string s, int k)
{
    int maxLength = 0;

    for (int i = 0; i < s.size(); i++)
    {
        unordered_map<char, int> frequency;
        int maxFrequency = 0;

        for (int j = i; j < s.size(); j++)
        {
            int subStrLen = j - i + 1;
            frequency[s[j]]++;
            maxFrequency = max(maxFrequency, frequency[s[j]]);
            int needToChange = subStrLen - maxFrequency;
            if (needToChange <= k)
                maxLength = max(subStrLen, maxLength);
        }
    }

    return maxLength;
}

//? Sliding window: TC:O(n), SC:O(m)
int characterReplacement(string s, int k)
{
    unordered_map<char, int> frequency;
    int maxLength = 0;

    int left = 0;
    int maxFrequency = 0;

    for (int r = 0; r < s.size(); r++)
    {
        frequency[s[r]]++;
        maxFrequency = max(maxFrequency, frequency[s[r]]);

        int subStrLen = r - left + 1;
        int needToChange = subStrLen - maxFrequency;

        while (needToChange > k)
        {
            frequency[s[left]]--;
            left++;
            subStrLen = r - left + 1;
            needToChange = subStrLen - maxFrequency;
        }

        maxLength = max(maxLength, subStrLen);
    }

    return maxLength;
}
int main()
{
    cout << "LeetCode 424. Longest Repeating Character Replacement" << endl;
}
