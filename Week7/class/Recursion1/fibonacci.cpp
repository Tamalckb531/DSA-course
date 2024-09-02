#include <iostream>
using namespace std;

int fibonacci(int n)
{
    //? base case
    if (n == 0 || n == 1)
    {
        return n;
    }

    //? recursive call

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{

    int ans = fibonacci(9);
    cout << ans << endl;

    return 0;
}