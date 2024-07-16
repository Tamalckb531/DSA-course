#include <iostream>
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

int main()
{
    return 0;
}