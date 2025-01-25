#include <iostream>
#include <algorithm>
#include <vector>
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

bool twoPointerCheck(vector<int> &arr, int target)
{

    int low = 0;
    int high = arr.size() - 1;

    while (low < high)
    {
        if (arr[low] + arr[high] == target)
            return true;
        else if (arr[low] + arr[high] < target)
            low++;
        else if (arr[low] + arr[high] > target)
            high++;
    }
    return false;
}

bool twoSum(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    return twoPointerCheck(arr, target);
}

int main()
{
    return 0;
}