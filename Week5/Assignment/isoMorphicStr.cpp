#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

bool isIsomorphic(string s, string t)
{
    int hash[256] = {0};
    bool istCharsMapped[256] = {0};

    for (int i = 0; i < s.size(); i++)
    {
        if (hash[s[i]] == 0 && istCharsMapped[t[i]] == 0)
        {
            hash[s[i]] = t[i];
            istCharsMapped[t[i]] = true;
        }
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (char(hash[s[i]]) != t[i])
        {
            return false;
        }
    }

    return true;
}

void normalizer(string &str)
{
    unordered_map<char, char> mapping;
    char start = 'a';

    for (int i = 0; i < str.length(); i++)
    {
        char strChar = str[i];
        if (mapping.find(strChar) == mapping.end())
        {
            mapping[strChar] = start;
            start++;
        }
    }

    for (int i = 0; i < str.length(); i++)
    {
        char strChar = str[i];
        str[i] = mapping[strChar];
    }
}

bool isIsomorphic(string s, string t)
{

    normalizer(s);
    normalizer(t);

    return s == t;
}

int main()
{
    return 0;
}