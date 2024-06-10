#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main()
{

    vector<int> arr1(4);
    vector<int> arr2(4);
    vector<int> result;

    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;
    arr1[3] = 4;

    arr2[0] = 3;
    arr2[1] = 4;
    arr2[2] = 5;
    arr2[3] = 6;

    //? union

    // set_union(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), inserter(result, result.begin()));

    // for (int a : result)
    // {
    //     cout << a << " ";
    // }

    //? intersection

    // set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), inserter(result, result.begin()));

    // for (int a : result)
    // {
    //     cout << a << " ";
    // }

    // cout << endl;

    //? difference

    // set_difference(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), inserter(result, result.begin()));

    // for (int a : result)
    // {
    //     cout << a << " ";
    // }
    // cout << endl;

    //? symmetric difference

    set_symmetric_difference(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), inserter(result, result.begin()));

    for (int a : result)
    {
        cout << a << " ";
    }

    cout << endl;
    return 0;
}