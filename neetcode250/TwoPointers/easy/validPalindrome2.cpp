#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string &s, int left, int right, bool skipped)
{
    while (left < right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else
        {
            if (skipped)
                return false;
            return checkPalindrome(s, left + 1, right, true) || checkPalindrome(s, left, right - 1, true);
        }
    }
    return true;
}

bool validPalindrome(string s)
{
    int start = 0;
    int end = s.size() - 1;
    return checkPalindrome(s, start, end, false);
}

int main()
{
    cout << "LeetCode 680. Valid Palindrome II" << endl;
}