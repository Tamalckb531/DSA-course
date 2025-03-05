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

int mySqrtPractice(int n)
{
    int start = 0;
    int end = n;
    int mid = start + (end - start) / 2;
    int ans = 0;

    while (start <= end)
    {
        if (mid * mid == n)
            return mid;
        else if (mid * mid < n)
        {
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;

        mid = start + (end - start) / 2;
    }
    return ans;
}

double myPrecisionSqrtPractice(int n)
{
    double mainRoot = mySqrtPractice(n);
    int precession = 3;
    double fractionPoint = 0.1;

    while (precession)
    {
        double temp = mainRoot;
        while (temp * temp <= n)
        {
            mainRoot = temp;
            temp += fractionPoint;
        }
        fractionPoint /= 10;

        precession--;
    }

    return mainRoot;
}

int main()
{

    int n = 63;
    double root = myPrecisionSqrt(n);
    double root2 = myPrecisionSqrtPractice(n);

    cout << root << endl;
    cout << root2 << endl;

    return 0;
}