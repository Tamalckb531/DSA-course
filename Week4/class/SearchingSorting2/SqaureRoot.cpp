#include <iostream>
#include <vector>
using namespace std;

double mySqrt(int x)
{
    // search space pattern of Binary Search
    int start = 0;
    int end = x;
    long long int mid = start + (end - start) / 2;
    long long int ans = -1;

    while (start <= end)
    {
        if (mid * mid == x)
        {
            return mid;
        }
        else if (mid * mid < x)
        {
            // search in right
            ans = mid; // store and compute
            start = mid + 1;
        }
        else if (mid * mid > x)
        {
            // search in left
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main()
{
    int num = 54;
    double ans = mySqrt(num);
    cout << ans << endl;
    return 0;
}