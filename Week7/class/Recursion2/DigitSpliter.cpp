#include <iostream>
using namespace std;

void spiltThatShit(int n)
{
    //? base case
    if (n == 0)
        return;

    //? head processing
    int digit = n % 10;

    //? recursive call
    spiltThatShit(n / 10);

    //? tail processing
    cout << digit << ",";
}
int main()
{
    int n = 389;
    spiltThatShit(n);
    cout << endl;
    return 0;
}