#include <iostream>
using namespace std;

bool strictlySortedArray(int arr[], int n, int index)
{
    //? base case
    if (index == n - 1)
        return true;

    //? processing
    bool currAns = false;
    bool recursiveAns = false;

    if (arr[index + 1] > arr[index])
        currAns = true;

    //? recursive call
    recursiveAns = strictlySortedArray(arr, n, index + 1);

    return (currAns && recursiveAns);
}

int main()
{
    int arr[] = {10, 20, 300, 40, 50};
    int size = 4;
    int index = 0;

    bool ans = strictlySortedArray(arr, size, index);
    cout << ans << endl;
    cout << "Hello recursion" << endl;
    return 0;
}