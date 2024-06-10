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

    //? make_heap

    make_heap(arr.begin(), arr.end());

    //? push_heap
    arr.push_back(99);
    push_heap(arr.begin(), arr.end());

    for (int a : arr)
    {
        cout << a << " ";
    }

    cout << endl;

    //? pop_heap
    pop_heap(arr.begin(), arr.end());
    arr.pop_back();

    for (int a : arr)
    {
        cout << a << " ";
    }

    cout << endl;

    //? sort_heap
    sort_heap(arr.begin(), arr.end());

    for (int a : arr)
    {
        cout << a << " ";
    }

    cout << endl;
    return 0;
}