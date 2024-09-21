#include <bits/stdc++.h>
using namespace std;

int numSqrHelper(int n)
{
    //? base case
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    int ans = INT_MAX;
    int i = 1;
    int end = sqrt(n);

    while (i <= end)
    {
        int perfectSquare = i * i;
        int numberOfPerfectSquare = 1 + numSqrHelper(n - perfectSquare);
        if (numberOfPerfectSquare < ans)
        {
            ans = numberOfPerfectSquare;
        }
        ++i;
    }
    return ans;
}

int numSquares(int n)
{
    return numSqrHelper(n) - 1;
}