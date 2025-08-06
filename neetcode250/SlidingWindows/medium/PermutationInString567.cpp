#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//? Hash Table: TC:O(s1.size() * s2.size()), SC:O(1)
// bool checkInclusion(string s1, string s2)
// {
//     unordered_map<char, int> s1Count;

//     for (auto s : s1)
//     {
//         s1Count[s]++;
//     }

//     int left = 0;
//     int right = s1.size() - 1;

//     while (right < s2.size())
//     {
//         unordered_map<char, int> window;

//         for (int i = left; i <= right; i++)
//         {
//             window[s2[i]]++;
//         }

//         if (window == s1Count)
//             return true;

//         left++;
//         right++;
//     }

//     return false;
// }

//? Sliding Window: TC:O(n), SC:O(1)
bool checkInclusion(string s1, string s2)
{
    if (s1.size() > s2.size())
        return false;

    int n = s1.size();
    int m = s2.size();

    unordered_map<char, int> s1Count;
    unordered_map<char, int> window;

    for (auto s : s1)
    {
        s1Count[s]++;
    }

    for (int i = 0; i < n; i++)
    {
        window[s2[i]]++;
    }
    if (window == s1Count)
        return true;

    int left = 0;

    for (int right = n; right < m; right++)
    {
        window[s2[left]]--;
        if (window[s2[left]] == 0)
            window.erase(s2[left]);

        window[s2[right]]++;

        if (window == s1Count)
            return true;
        left++;
    }

    return false;
}
int main()
{
    cout << checkInclusion("ab", "eidbaooo") << endl;
    cout << "LeetCode 567. Permutation in String" << endl;
}
