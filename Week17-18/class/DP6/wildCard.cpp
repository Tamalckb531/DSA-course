#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

class Solution
{
public:
    bool solveRec(string &s, string &p, int i, int j)
    {
        //? base case
        if (i == s.length() && j == p.length())
            return true; //? pattern and stirng both end
        if (j == p.length())
            return false; //? pattern end but string still left
        if (i == s.length())
        {
            for (int k = j; k < p.length(); k++)
            {
                if (p[k] != '*')
                    return false;
            }
            return true;
        } //? pattern left

        //? logic
        if (s[i] == p[j] || p[j] == '?')
            return solveRec(s, p, i + 1, j + 1);
        else if (p[j] == '*')
            return solveRec(s, p, i + 1, j) || solveRec(s, p, i, j + 1);
        else
            return false;
    }

    bool solveMem(string &s, string &p, int i, int j, vector<vector<int>> &dp)
    {

        //? base case
        if (i == s.length() && j == p.length())
            return true; //? pattern and stirng both end
        if (j == p.length())
            return false; //? pattern end but string still left
        if (i == s.length())
        {
            for (int k = j; k < p.length(); k++)
            {
                if (p[k] != '*')
                    return false;
            }
            return true;
        } //? pattern left

        //? array check
        if (dp[i][j] != -1)
            return dp[i][j];

        //? logic
        if (s[i] == p[j] || p[j] == '?')
            dp[i][j] = solveMem(s, p, i + 1, j + 1, dp);
        else if (p[j] == '*')
            dp[i][j] = solveMem(s, p, i + 1, j, dp) || solveMem(s, p, i, j + 1, dp);
        else
            dp[i][j] = false;
        return dp[i][j];
    }

    bool solveTab(string s, string p, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[m][n] = true;

        for (int col = 0; col < n; col++)
        {
            bool flag = true;
            for (int k = col; k < p.length(); k++)
            {
                if (p[k] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[m][col] = flag;
        }

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n; j >= 0; j--)
            {
                bool ans;
                if (p[j] == '?' || s[i] == p[j])
                {
                    ans = dp[i + 1][j + 1];
                }
                else if (p[j] == '*')
                {
                    ans = dp[i + 1][j] || dp[i][j + 1];
                }
                else
                {
                    ans = false;
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }

    bool solveTabSO(string s, string p, int m, int n)
    {
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);
        next[n] = true;

        for (int col = 0; col < n; col++)
        {
            bool flag = true;
            for (int k = col; k < p.length(); k++)
            {
                if (p[k] != '*')
                {
                    flag = false;
                    break;
                }
            }
            next[col] = flag;
        }

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n; j >= 0; j--)
            {
                bool ans;
                if (p[j] == '?' || s[i] == p[j])
                {
                    ans = next[j + 1];
                }
                else if (p[j] == '*')
                {
                    ans = next[j] || curr[j + 1];
                }
                else
                {
                    ans = false;
                }
                curr[j] = ans;
            }
            // shiufting
            next = curr;
        }

        return next[0];
    }

    bool isMatch(string s, string p)
    {
        //? ------ Recursion ------
        // return solveRec(s,p,0,0);

        //? ------ Memoization ------
        // int n=s.length();
        // int m=p.length();

        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return solveMem(s,p,0,0,dp);

        //? ------ Tabulation ------
        // int n=s.length();
        // int m=p.length();

        // return solveTab(s,p,n,m);

        //? ------ Space Optimization ------
        int n = s.length();
        int m = p.length();

        return solveTabSO(s, p, n, m);
    }
};