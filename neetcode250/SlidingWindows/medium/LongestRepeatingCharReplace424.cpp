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
int main()
{
    cout << "LeetCode 424. Longest Repeating Character Replacement" << endl;
}
