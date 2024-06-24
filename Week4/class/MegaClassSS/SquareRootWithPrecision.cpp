#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int mySqrt(int n)
{
    int s = 0, e = n;
    int mid = s + (e - s) / 2;

    int ans = 0;

    while (s <= e)
    {
        if (mid * mid <= n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }

    return ans;
}

double myPrecisionSqrt(int n)
{
    double sqrt = mySqrt(n);
    int precision = 3;
    double step = 0.1;

    while (precision--)
    {
        double j = sqrt;
        while (j * j <= n)
        {
            sqrt = j;
            j += step;
        }

        step /= 10;
    }

    return sqrt;
}

int main()
{

    int n = 63;
    double root = myPrecisionSqrt(n);

    cout << root << endl;

    return 0;
}