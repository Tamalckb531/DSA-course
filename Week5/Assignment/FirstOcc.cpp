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

int strStrPractice(string haystack, string needle)
{
    int haystackSize = haystack.size();
    int needleSize = needle.size();

    int maxTraversal = haystackSize - needleSize; //? if needle in last then first index will be haystackSize - needleSize.

    //? outer loop -> Full haystack traversal
    //? inner loop -> needle traversal for match
    for (int i = 0; i < maxTraversal; i++)
    {
        for (int j = 0; j < needleSize; j++)
        {
            if (needle[j] != haystack[i + j])
                return -1;
            if (j == needleSize - 1)
                return i; //? we are in the last index so needle has been found
        }
    }

    return -1;
}

int main()
{
    return 0;
}