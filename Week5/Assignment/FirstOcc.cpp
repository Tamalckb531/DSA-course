#include <iostream>
using namespace std;

int strStr(string haystack, string needle)
{
    int haystackSize = haystack.size();
    int needleSize = needle.size();

    // if the niddle is in the end of haystack than we only need to find the first index of niddle
    int maxHayStackTraverse = haystackSize - needleSize;

    for (int i = 0; i <= maxHayStackTraverse; i++)
    {
        for (int j = 0; j < needleSize; j++)
        {
            // full needle checking
            if (needle[j] != haystack[i + j])
            {
                break;
            }

            // reached the end of needle
            if (j == needleSize - 1)
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    return 0;
}