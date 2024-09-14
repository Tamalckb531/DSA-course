#include <iostream>
using namespace std;

/*

    ? - Do the math for n=1 and n=2;
    ? - Keep the last two same and diff. Diff means last one is same and the prev can be any.
    ? - Same will have the pattern match with n-2 and Diff will ahve the pattern match with n-1.
    ! - Add the both and multiply with (k-1). That's the main formula

*/

long long int countWays(int n, int k)
{
    if (n == 1)
        return k;
    if (n == 2)
        return k + k * (k - 1);

    int ans = (k - 1) * (countWays(n - 1, k) + countWays(n - 2, k));
    return ans;
}

int main()
{
    return 0;
}