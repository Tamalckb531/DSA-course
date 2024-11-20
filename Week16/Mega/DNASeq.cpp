#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{

    //? The question ask to return the repeated sequence of 10th in an DNA
    //? We taking a map to store the count of all 10th sub-string freq via sliding the index window and storing subStr with more than one appearance and returning it.

public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<string, int> seqFreq;
        vector<string> ans;

        if (s.size() < 10)
            return {};

        //? sliding window loop for 10 sequence
        for (int i = 0; i <= s.size() - 10; i++)
        {
            string currentTenthSeq = s.substr(i, 10);
            seqFreq[currentTenthSeq]++;
        }

        for (auto &[subString, freq] : seqFreq)
        {
            if (freq > 1)
                ans.push_back(subString);
        }

        return ans;
    }
};