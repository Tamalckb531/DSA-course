#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    // track individual word ka count
    unordered_map<string, int> map;
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> ans;

        for (int i = 0; i < words.size(); i++)
        {
            map[words[i]]++;
        }

        int wordLength = words[0].length();

        // offset logic -> start -> 0,1,2,    < wrdLength
        for (int offset = 0; offset < wordLength; offset++)
        {

            unordered_map<string, int> visited;
            int count = 0;

            for (int i = offset; i + wordLength <= s.length(); i = i + wordLength)
            {
                string substr = s.substr(i, wordLength);

                if (map.find(substr) == map.end())
                {
                    // invalid string
                    visited.clear();
                    count = 0;
                }
                else
                {
                    // valid string
                    visited[substr]++;
                    count++;

                    // GAME CHANGER - removal
                    while (visited[substr] > map[substr])
                    {
                        string temp = s.substr(i - (count - 1) * wordLength, wordLength);
                        visited[temp]--;
                        count--;
                    }
                    // GAME CHANGER

                    if (count == words.size())
                    {
                        ans.push_back(i - (count - 1) * wordLength);
                    }
                }
            }
        }
        return ans;
    }
};