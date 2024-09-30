#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &candidates, int target, vector<int> &combination, vector<vector<int>> &ans, int index)
{

    if (target == 0)
    {
        ans.push_back(combination);
        return;
    }
    if (target < 0)
    {
        return;
    }

    for (int i = index; i < candidates.size(); i++)
    {
        combination.push_back(candidates[i]);
        solve(candidates, target - candidates[i], combination, ans, i);
        combination.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<int> combination;
    vector<vector<int>> ans;
    int index = 0;
    solve(candidates, target, combination, ans, index);
    return ans;
}