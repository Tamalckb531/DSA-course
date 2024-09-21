#include <bits/stdc++.h>
using namespace std;

int numRollsToTarget(int n, int k, int target)
{
    if (target < 0)
        return 0;
    if (n == 0 && target != 0)
        return 0;
    if (n != 0 && target == 0)
        return 0;
    if (n == 0 && target == 0)
        return 1;

    int ans = 0;
    for (int i = 0; i <= k; i++)
    {
        ans = ans + numRollsToTarget(n - 1, k, target - i);
    }
    return ans;
}