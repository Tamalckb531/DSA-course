#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool isPalindrome(string &s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

string longestPalindrome(string s)
{
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            if (isPalindrome(s, i, j))
            {
                string t = s.substr(i, j - i + 1);
                ans = t.size() > ans.size() ? t : ans;
            }
        }
    }

    return ans;
}

bool isPalindrome(string &s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

string longestPalindrome(string s)
{
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            if (isPalindrome(s, i, j))
            {
                string palSubStr = s.substr(i, j - i + 1);
                ans = palSubStr.size() > ans.size() ? palSubStr : ans; //? storing the longest palindromic sub string
            }
        }
    }

    return ans;
}

int main()
{
}