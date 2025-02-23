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

double SqrtPractice(int num)
{
    int start = 0;
    int end = num; //? creation of search space;
    long long int mid = start + (end - start) / 2;
    long long int squareRoot = -1;

    while (start <= end)
    {
        if (mid * mid == num)
            return mid;
        else if (mid * mid < num)
        {
            //? mid in left -> store and compute -> search in right
            squareRoot = mid;
            start = mid + 1;
        }
        else
        {
            //? mid in right -> search in left
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    return squareRoot;
}

int main()
{
    int num = 54;
    double ans = mySqrt(num);
    double ans2 = SqrtPractice(num);
    cout << ans << " , " << ans2 << endl;
    return 0;
}