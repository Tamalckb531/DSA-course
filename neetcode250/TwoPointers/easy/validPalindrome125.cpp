#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool validChar(char &ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        return true;
    return false;
}

bool isPalindrome(string s)
{
    int start = 0;
    int end = s.size() - 1;
    char st, ed;
    while (start < end)
    {
        st = s[start];
        ed = s[end];
        if (!validChar(st))
        {
            start++;
        }
        else if (!validChar(ed))
        {
            end--;
        }
        else if (tolower(st) == tolower(ed))
        {
            start++;
            end--;
        }
        else
            return false;
    }
    return true;
}

int main()
{
    cout << "LeetCode 125. Valid Palindrome" << endl;
}