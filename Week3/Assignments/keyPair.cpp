#include <iostream>
#include <algorithm>
using namespace std;

bool twoPointerKeyPair(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        if (arr[low] + arr[high] == x)
            return true;
        else if (arr[low] + arr[high] < x)
            low++;
        else if (arr[low] + arr[high] > x)
            high--;
    }

    return false;
}

bool hasArrayTwoCandidates(int arr[], int n, int x)
{
    // code here
    std::sort(arr, arr + n);
    return twoPointerKeyPair(arr, n, x);
}

int main()
{
    return 0;
}