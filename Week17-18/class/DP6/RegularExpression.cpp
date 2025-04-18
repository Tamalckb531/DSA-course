#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool solveUsingRec(string &s, string &p, int i, int j)
    {
        // base case
        if (i == s.length() && j == p.length())
        {
            return true;
        }
        if (j == p.length())
        {
            return false;
        }

        bool currMatch = (i < s.length()) && (p[j] == '.' || s[i] == p[j]);

        if (j + 1 < p.length() && p[j + 1] == '*')
        {
            bool emptyCase = solveUsingRec(s, p, i, j + 2);
            bool precedingCase = currMatch && solveUsingRec(s, p, i + 1, j);
            return emptyCase || precedingCase;
        }
        else if (currMatch)
        {
            return solveUsingRec(s, p, i + 1, j + 1);
        }
        else
        {
            return false;
        }
    }
    bool solveUsingMem(string &s, string &p, int i, int j, vector<vector<int>> &dp)
    {
        // base case
        if (i == s.length() && j == p.length())
        {
            return true;
        }
        if (j == p.length())
        {
            return false;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        bool currMatch = (i < s.length()) && (p[j] == '.' || s[i] == p[j]);
        bool ans;
        if (j + 1 < p.length() && p[j + 1] == '*')
        {
            bool emptyCase = solveUsingMem(s, p, i, j + 2, dp);
            bool precedingCase = currMatch && solveUsingMem(s, p, i + 1, j, dp);
            ans = emptyCase || precedingCase;
        }
        else if (currMatch)
        {
            ans = solveUsingMem(s, p, i + 1, j + 1, dp);
        }
        else
        {
            ans = false;
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int solveUsingTabulation(string s, string p, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[m][n] = 1;

        for (int i = m; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                bool currMatch = (i < s.length()) && (p[j] == '.' || s[i] == p[j]);
                bool ans;
                if (j + 1 < p.length() && p[j + 1] == '*')
                {
                    bool emptyCase = dp[i][j + 2];
                    bool precedingCase = currMatch && dp[i + 1][j];
                    ans = emptyCase || precedingCase;
                }
                else if (currMatch)
                {
                    ans = dp[i + 1][j + 1];
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
    int solveUsingTabulationSO(string s, string p, int m, int n)
    {
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);
        next[n] = 1;

        for (int i = m; i >= 0; i--)
        {
            if (i == m)
            {
                curr[n] = true;
            }
            else
            {
                curr[n] = false;
            }
            for (int j = n - 1; j >= 0; j--)
            {
                bool currMatch = (i < s.length()) && (p[j] == '.' || s[i] == p[j]);
                bool ans;
                if (j + 1 < p.length() && p[j + 1] == '*')
                {
                    bool emptyCase = curr[j + 2];
                    bool precedingCase = currMatch && next[j];
                    ans = emptyCase || precedingCase;
                }
                else if (currMatch)
                {
                    ans = next[j + 1];
                }
                else
                {
                    ans = false;
                }
                curr[j] = ans;
            }
            // shifting
            next = curr;
        }

        return next[0];
    }
    bool isMatch(string s, string p)
    {
        //? -------- Recursion --------
        // return solveUsingRec(s,p,0,0);

        //? -------- Memoization --------
        // int n = s.length();
        // int m = p.length();

        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return solveUsingMem(s,p,0,0,dp);

        //? -------- Tabulation --------
        // int n = s.length();
        // int m = p.length();

        // return solveUsingTabulation(s,p,n,m);

        //? -------- Space Optimization --------
        int n = s.length();
        int m = p.length();

        return solveUsingTabulationSO(s, p, n, m);
    }
};