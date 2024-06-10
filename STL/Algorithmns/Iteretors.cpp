#include <iostream>
#include <algorithm>
#include <vector>

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

    arr[0] = 10;
    arr[1] = 21;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 53;
    arr[5] = 60;

    //? for_each
    // for_each(arr.begin(), arr.end(), printDouble);

    // cout << endl;

    //? find
    // int target = 40;
    // auto it = find(arr.begin(), arr.end(), target);

    // cout << *it;

    //? findIf
    // auto it = find_if(arr.begin(), arr.end(), checkEven);
    // cout << *it << endl;

    //? count
    // int target = 40;
    // int ans = count(arr.begin(), arr.end(), target);

    // cout << ans;

    //? sort
    // sort(arr.begin(), arr.end());

    //? reverse
    // reverse(arr.begin(), arr.end());

    //? rotate
    // rotate(arr.begin(), arr.begin() + 3, arr.end());
    // [40,50,60,10,20,30]

    //? Unique
    // auto it = unique(arr.begin(), arr.end());

    //? partition
    auto it = partition(arr.begin(), arr.end(), checkEven);

    for (int a : arr)
    {
        cout << a << " ";
    }

    cout << endl;
    return 0;
}