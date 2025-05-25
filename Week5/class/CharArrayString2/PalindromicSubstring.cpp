#include <iostream>
using namespace std;

//? check

int expandAroundCenter(string s, int i, int j)
{
    int count = 0;

    while (i >= 0 && j < s.length() && s[i] == s[j])
    {
        count++;
        i--;
        j++;
    }

    return count;
}
int countSubstrings(string s)
{
    int totalCount = 0;

    for (int center = 0; center < s.length(); center++)
    {
        // odd count -> both pointer in same center
        int i = center;
        int j = center;
        int oddCount = expandAroundCenter(s, i, j);

        // even count -> one pointer is ahead of another pointer
        i = center;
        j = center + 1;
        int evenCount = expandAroundCenter(s, i, j);

        totalCount = totalCount + oddCount + evenCount;
    }

    return totalCount;
}

//? to find how many sequences of s from center is palindrome
int expandAroundCenterPractice(string s, int i, int j)
{
    int count = 0;

    while (i >= 0 && j < s.length() && s[i] == s[j])
    {
        //? is a substr palindrome sequence
        count++;
        i--;
        j++; //? expanding for more matched sequences
    }

    return count;
}

int countSubstringsPractice(string s)
{
    int totalCount = 0;

    //? every char of s string can be a center
    for (int center = 0; center < s.length(); center++)
    {
        //? finding odd sequences
        int i = center;
        int j = center;
        int oddCount = expandAroundCenterPractice(s, i, j);

        //? finding even sequences
        i = center;
        j = center + 1;
        int evenCount = expandAroundCenterPractice(s, i, j);

        totalCount = totalCount + oddCount + evenCount;
    }

    return totalCount;
}

int main()
{
    return 0;
}