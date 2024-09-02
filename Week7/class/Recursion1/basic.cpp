#include <iostream>
using namespace std;

int getFactorial(int n)
{
    //? base case:
    if (n == 1)
        return 1;

    //? recursive call
    return n * getFactorial(n - 1);
}

int Power(int n)
{
    //? base case
    if (n == 0)
        return 1;

    //? recursive call
    return 2 * Power(n - 1);
}

int main()
{

    int n;
    cout << "Enter the value of n : " << endl;
    cin >> n;

    int ans = getFactorial(n);
    cout << "Factorial of " << n << " : " << ans << endl;

    int ans2 = Power(n);
    cout << "2 to the Power " << n << " : " << ans2 << endl;

    cout << "Hello Recursion" << endl;
    return 0;
}