#include <iostream>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t)
{
    int freqTable[256] = {0};

    // counting the character of s
    for (int i = 0; i < s.length(); i++)
    {
        freqTable[s[i]]++;
    }

    // counting the character of t
    for (int i = 0; i < t.length(); i++)
    {
        freqTable[t[i]]--;
    }

    // checking if any character index have any character left
    for (int i = 0; i < 256; i++)
    {
        if (freqTable[i] != 0)
            return false;
    }

    return true;
}

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

    for (auto pair : mapping)
    {
        if (pair.second != 0)
            return false;
    }

    return true;
}

int main()
{
    return 0;
}