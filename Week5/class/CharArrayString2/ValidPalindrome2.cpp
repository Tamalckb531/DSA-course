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

int main()
{
    return 0;
}