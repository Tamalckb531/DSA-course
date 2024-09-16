#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> &ans, string digits, string &output, int index, unordered_map<char, string> &mapping)
{
    int n = digits.length();
    if (index >= n)
    {
        ans.push_back(output);
        return;
    }

    char digit = digits[index];
    string mappedString = mapping[digit];

    for (char ch : mappedString)
    {
        output.push_back(ch);

        solve(ans, digits, output, index + 1, mapping);

        output.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    unordered_map<char, string> mapping;
    vector<string> ans;

    if (digits.length() == 0)
        return ans;

    mapping['2'] = "abc";
    mapping['3'] = "def";
    mapping['4'] = "ghi";
    mapping['5'] = "jkl";
    mapping['6'] = "mno";
    mapping['7'] = "pqrs";
    mapping['8'] = "tuv";
    mapping['9'] = "wxyz";

    int index = 0;
    string output = "";

    solve(ans, digits, output, index, mapping);
    return ans;
}