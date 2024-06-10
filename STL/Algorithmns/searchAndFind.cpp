#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main()
{

    vector<int> arr(6);

    arr[0] = 10;
    arr[1] = 21;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 53;
    arr[5] = 60;

    //? binary_search:
    // int target = 40;
    // auto boolVal = binary_search(arr.begin(), arr.end(), target);

    //? lower_bound:
    // int target = 35;
    // auto it = lower_bound(arr.begin(), arr.end(), target);
    // cout << *it << endl;

    //? upper_bound:
    int target = 30;
    auto it = upper_bound(arr.begin(), arr.end(), target);
    cout << *it << endl;

    cout << endl;
    return 0;
}