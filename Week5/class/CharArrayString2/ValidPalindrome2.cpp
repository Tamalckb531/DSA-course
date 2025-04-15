#include <iostream>
using namespace std;

bool checkPalindrome(string str, int left, int right)
{
    while (left <= right)
    {
        if (str[left] != str[right])
        {
            return false;
        }
        else
        {
            left++;
            right--;
        }
    }
    return true;
}

bool validPalindrome(string s)
{
    int len = s.length();
    int left = 0;
    int right = len - 1;
    bool finalAns;

    while (left <= right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else
        {
            bool leftAns = checkPalindrome(s, left + 1, right);  // deleting one left element
            bool rightAns = checkPalindrome(s, left, right - 1); // deleting one right element
            return finalAns = leftAns || rightAns;               // Combining both possible answers
        }
    }

    return true;
}

bool checkPalin(string str, int left, int right)
{
    while (left <= right)
    {
        if (str[left] == str[right])
        {
            left++;
            right--;
        }
        else
        {
            return false;
        }

        return true;
    }
}

//? abccdba

bool validPalindromePractice(string s)
{
    int len = s.length();
    int left = 0;
    int right = len - 1;
    bool ans = true;

    while (left <= right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else
        {
            bool leftAns = checkPalin(s, left + 1, right);
            bool rightAns = checkPalin(s, left, right - 1);
            ans = leftAns || rightAns;
        }
    }
    return ans;
}

int main()
{
    return 0;
}