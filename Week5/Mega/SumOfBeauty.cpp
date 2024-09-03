#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

int beautySum(string s)
{
    //? FLOW : Get the substrings -> get the min and max freq for each and find the beauty -> sum-up all beauty -> return it
    int beautySumFreq = 0;
    unordered_map<char, int> subStrMap;

    //? STEP 1: Get the substring -> two loop needed for finding substring
    for (int i = 0; i < s.size(); i++)
    {
        subStrMap.clear(); // a new substring a new mapping
        for (int j = i; j < s.size(); j++)
        {
            char &ch = s[j];
            subStrMap[ch]++; // adding up the frequency for a char in map

            //? STEP 2: get the min and max freq for each and find the beauty

            int maximum = INT_MIN;
            int minimum = INT_MAX;

            for (auto eachChar : subStrMap)
            {
                maximum = max(eachChar.second, maximum);
                minimum = min(eachChar.second, minimum);
            }

            int beauty = maximum - minimum;
            beautySumFreq += beauty;
        }
    }
    return beautySumFreq;
}

int main()
{
    return 0;
}
