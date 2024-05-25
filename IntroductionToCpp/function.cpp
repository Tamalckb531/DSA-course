#include <iostream>
using namespace std;

void printCounting()
{
    for (int i = 0; i <= 5; i++)
    {
        cout << i << " ";
    }
    cout << endl;
}

int sum(int a, int b)
{
    return a + b;
}

int main()
{
    cout << "Hello!" << endl;

    //? repetition of code

    // printCounting();

    // cout << "After first time" << endl;

    // printCounting();

    // cout << "After second time" << endl;

    // printCounting();

    // cout << "After third time" << endl;

    //? non-void return value

    int ans = sum(5, 10);
    cout << ans << endl;

    return 0;
}