#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &ans, vector<int> &output, int start, int n, int k)
{

    if (k == 0)
    {
        ans.push_back(output);
        return;
    }
    if (start > n)
        return;

    for (int i = start; i <= n; i++)
    {
        output.push_back(i);
        solve(ans, output, i + 1, n, k - 1);
        output.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> ans;
    vector<int> output;
    int start = 1;
    solve(ans, output, start, n, k);
    return ans;
}