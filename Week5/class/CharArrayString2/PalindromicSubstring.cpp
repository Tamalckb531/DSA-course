#include <iostream>
using namespace std;

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

int main()
{
    return 0;
}