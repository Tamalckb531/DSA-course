#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity.

    int solveRec(vector<int> &wt, vector<int> &val, int capacity, int index)
    {
        //? Base case
        if (index == 0)
        {
            //? single element
            if (wt[0] <= capacity)
            {
                return val[0];
            }
            return 0;
        }

        //? Processing
        int include = 0;
        if (wt[index] <= capacity)
            include = val[index] + solveRec(wt, val, capacity - wt[index], index - 1);
        int exclude = 0 + solveRec(wt, val, capacity, index - 1);

        int finalAns = max(include, exclude);
        return finalAns;
    }

    int solveMem(vector<int> &wt, vector<int> &val, int capacity, int index, vector<vector<int>> &dp)
    {
        //? Base case
        if (index == 0)
        {
            //? single element
            if (wt[0] <= capacity)
            {
                return val[0];
            }
            return 0;
        }

        if (dp[capacity][index] != -1)
            return dp[capacity][index];

        //? Processing
        int include = 0;
        if (wt[index] <= capacity)
            include = val[index] + solveMem(wt, val, capacity - wt[index], index - 1, dp);
        int exclude = 0 + solveMem(wt, val, capacity, index - 1, dp);

        dp[capacity][index] = max(include, exclude);
        return dp[capacity][index];
    }

    int solveTab(vector<int> &wt, vector<int> &val, int capacity)
    {

        int n = val.size() - 1;
        vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, 0));

        //? base case analysis
        for (int weight = wt[0]; weight <= capacity; weight++)
        {
            dp[weight][0] = val[0];
        }

        //? tabulation
        for (int weight = 0; weight <= capacity; weight++)
        {
            for (int index = 1; index <= n; index++)
            {
                int include = 0;
                if (wt[index] <= weight)
                    include = val[index] + dp[weight - wt[index]][index - 1];
                int exclude = 0 + dp[weight][index - 1];

                dp[weight][index] = max(include, exclude);
            }
        }

        return dp[capacity][n];
    }

    int knapSack(int capacity, vector<int> &val, vector<int> &wt)
    {
        //? ----------Recursion----------
        // int n = val.size()-1;
        // return solveRec(wt, val, capacity, n);

        //? ----------Memoization----------
        // int n = val.size()-1;
        // vector<vector<int>> dp(capacity+1, vector<int>(n+1, -1));
        // return solveMem(wt, val, capacity, n, dp);

        //? ----------Tabulation----------
        return solveTab(wt, val, capacity);
    }
};
