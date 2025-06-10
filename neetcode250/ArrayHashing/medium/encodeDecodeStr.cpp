#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string encode(vector<string> &strs)
{
    string ans = "";
    for (auto str : strs)
    {
        ans = ans + str + "*";
    }
    return ans;
}

vector<string> decode(string s)
{
    vector<string> ans;
    string temp = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '*')
        {
            ans.push_back(temp);
            temp = "";
        }
        else
        {
            temp += s[i];
        }
    }

    return ans;
}

int main()
{
    cout << "LeetCode: Encode and Decode Strings" << endl;
}