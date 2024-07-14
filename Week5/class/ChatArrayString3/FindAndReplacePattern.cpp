#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void normalize(string &str)
{
    char start = 'a';
    unordered_map<char, char> mapping;

    // mapping the string character with normal alphabet serially
    for (int i = 0; i < str.length(); i++)
    {
        char strChar = str[i];
        if (mapping.find(strChar) == mapping.end())
        {
            // if not found in mapping
            mapping[strChar] = start;
            start++;
        }
    }

    // Getting the mappedChar of string and replacing the string character with it -> now new string is normalized
    for (int i = 0; i < str.length(); i++)
    {
        char mappedCharacter = mapping[str[i]];
        str[i] = mappedCharacter;
    }
}

vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{
    vector<string> ans;

    // step A: pattern normalize
    normalize(pattern);

    // step B: Get each word and normalize them -> check with pattern -> if matched than store them
    for (int i = 0; i < words.size(); i++)
    {
        string currWord = words[i];
        normalize(currWord);
        if (currWord == pattern)
        {
            ans.push_back(words[i]);
        }
    }

    return ans;
}

int main()
{
    return 0;
}