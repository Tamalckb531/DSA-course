#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solveRec(string text1, string text2, int i, int j)
    {

        if (i >= text1.size() || j >= text2.size())
            return 0;

        int ans = 0;
        if (text1[i] == text2[j])
            ans = 1 + solveRec(text1, text2, i + 1, j + 1);
        else
            ans = 0 + max(solveRec(text1, text2, i + 1, j), solveRec(text1, text2, i, j + 1));
        return ans;
    }
    int solveMem(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
    {

        if (i >= text1.size() || j >= text2.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (text1[i] == text2[j])
            dp[i][j] = 1 + solveMem(text1, text2, i + 1, j + 1, dp);
        else
            dp[i][j] = 0 + max(solveMem(text1, text2, i + 1, j, dp), solveMem(text1, text2, i, j + 1, dp));
        return dp[i][j];
    }

    int solveTab(string &text1, string &text2)
    {
        int size1 = text1.length();
        int size2 = text2.length();

        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));

        for (int i = size1 - 1; i >= 0; i--)
        {
            for (int j = size2 - 1; j >= 0; j--)
            {
                if (text1[i] == text2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = 0 + max(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        return dp[0][0];
    }

    int solveTabSO(string &text1, string &text2)
    {
        int size1 = text1.length();
        int size2 = text2.length();

        vector<int> prev(size2 + 1, 0);
        vector<int> curr(size2 + 1, 0);

        for (int i = size1 - 1; i >= 0; i--)
        {
            for (int j = size2 - 1; j >= 0; j--)
            {
                if (text1[i] == text2[j])
                    curr[j] = 1 + prev[j + 1];
                else
                    curr[j] = 0 + max(prev[j], curr[j + 1]);
            }
            prev = curr;
        }

        return prev[0];
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        //? --------- Recursion ---------
        // return solveRec(text1, text2, 0, 0);

        //? --------- Memoization ---------
        // int n = text1.size();
        // int m = text2.size();
        // vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        // return solveMem(text1, text2, 0, 0, dp);

        //? --------- Tabulation ---------
        // return solveTab(text1, text2);

        //? --------- Space Optimization ---------
        return solveTabSO(text1, text2);
    }
};