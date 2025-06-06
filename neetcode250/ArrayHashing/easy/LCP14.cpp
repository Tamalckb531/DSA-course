#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string ans = "";
    char ch = '*';

    if (strs.size() == 1)
        return strs[0];

    for (int i = 0; i <= 200; i++)
    {
        for (auto str : strs)
        {
            if (str == "")
                return "";
            if (i < str.length())
            {
                if (ch != '*' && ch != str[i])
                    return ans;
                ch = str[i];
            }
            else
            {
                return ans;
            }
        }
        ans.push_back(ch);
        ch = '*';
    }
    return ans;
}

int main()
{
    cout << "LeetCode 14. Longest Common Prefix" << endl;
}