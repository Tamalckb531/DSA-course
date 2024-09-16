#include <bits/stdc++.h>
using namespace std;

//? Always starts with ( -> open is always greater than close -> open and close should end up making 2*n that is the base case

void solve(vector<string> &ans, string &output, int n, int open, int close)
{
    //? base case
    if (open + close == 2 * n)
    {
        ans.push_back(output);
        return;
    }

    //? restricted recursive call
    if (open < n)
    {
        output.push_back('(');
        solve(ans, output, n, open + 1, close);
        output.pop_back();
    }
    if (close < open)
    {
        output.push_back(')');
        solve(ans, output, n, open, close + 1);
        output.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    string output = "";
    int open = 0;
    int close = 0;
    solve(ans, output, n, open, close);
    return ans;
}