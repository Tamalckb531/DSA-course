// Given two integers one is a dividend and the other is the divisor, we need to find the quotient when the dividend is divided by the divisor without the use of any " / " and " % " operators.

//  Input: dividend = 10, divisor = 2
//  Output: 5
//  Explanation: 10/2 = 5

//  Input: dividend = 10, divisor = 3
//  Output: 3
//  Explanation: 10/3 = 3.33333... which is truncated to 3.

//  Input: dividend = 10, divisor = -2
//  Output: -5
//  Explanation: 10/-2 = -5

#include <iostream>
#include <vector>
using namespace std;

int divisionAlgo(int dividend, int divisor)
{
    int s = 0;
    int e = dividend;
    int midQuotient = s + ((e - s) >> 1);
    int ans = -1;

    while (s <= e)
    {
        if ((divisor * midQuotient) == dividend)
        {
            return midQuotient;
        }
        else if ((divisor * midQuotient) < dividend)
        {
            ans = midQuotient;
            s = midQuotient + 1;
        }
        else
        {
            e = midQuotient - 1;
        }
        midQuotient = s + ((e - s) >> 1);
    }

    return ans;
}

int divisionAlgoPractice(int dividend, int divisor)
{
    int start = 0;
    int end = dividend;
    int mid = start + start + ((end - start) >> 1);

    int storeAns = -1;

    while (start <= end)
    {
        if (mid * divisor == dividend)
            return mid;
        else if (mid * divisor < dividend)
        {
            storeAns = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;

        mid = start + start + ((end - start) >> 1);
    }

    return storeAns;
}

int main()
{
    int dividend = 15;
    int divisor = 5;

    int ans = divisionAlgoPractice(abs(dividend), abs(divisor));

    // negative handling :
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
    {
        ans = 0 - ans;
    }

    cout << "Final Ans: " << ans << endl;
    return 0;
}