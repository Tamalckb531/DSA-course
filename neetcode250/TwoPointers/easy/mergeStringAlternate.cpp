#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string mergeAlternately(string word1, string word2)
{
    int w1 = 0;
    int w2 = 0;

    int ws1 = word1.size();
    int ws2 = word2.size();

    string ans = "";

    while (w1 < ws1 && w2 < ws2)
    {
        ans.push_back(word1[w1]);
        ans.push_back(word2[w2]);
        w1++;
        w2++;
    }

    while (w1 < ws1)
    {
        ans.push_back(word1[w1]);
        w1++;
    }
    while (w2 < ws2)
    {
        ans.push_back(word2[w2]);
        w2++;
    }

    return ans;
}

int main()
{
    cout << "LeetCode 1768. Merge Strings Alternately" << endl;
}