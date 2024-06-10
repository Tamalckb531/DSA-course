#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

void printDouble(int a)
{
    cout << 2 * a << " ";
}

bool checkEven(int a)
{
    return a % 2 == 0;
}

int main()
{

    vector<int> arr(6);
    vector<int> arr1(3);
    vector<int> arr2(3);

    arr[0] = 10;
    arr[1] = 21;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 53;
    arr[5] = 60;

    arr1[0] = 1;
    arr1[0] = 2;
    arr1[0] = 3;
    arr2[0] = 4;
    arr2[1] = 5;
    arr2[2] = 6;

    //? accumulate
    // int total = accumulate(arr.begin(), arr.end(), 0);
    // cout << total << endl;

    //? Inner product
    // int product = inner_product(arr1.begin(), arr1.end(),
    //                             arr2.begin(), 0);
    // cout << product << endl;

    //? partial_sum
    // vector<int> result(arr.size());
    // partial_sum(arr.begin(), arr.end(), result.begin());

    // for (int a : result)
    // {
    //     cout << a << " ";
    // }

    //? iota

    // vector<int> first(5);

    // iota(first.begin(), first.end(), 250);

    // for (int a : first)
    // {
    //     cout << a << " ";
    // }

    cout << endl;
    return 0;
}