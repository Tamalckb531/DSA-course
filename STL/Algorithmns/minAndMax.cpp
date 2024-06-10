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

    int a = 10;
    int b = 15;

    cout << max(a, b) << endl;
    cout << min(a, b) << endl;

    auto it = min_element(arr.begin(), arr.end());
    cout << *it << endl;

    auto it2 = max_element(arr.begin(), arr.end());
    cout << *it2 << endl;

    cout << endl;
    return 0;
}