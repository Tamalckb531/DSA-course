
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> twoPointerMethod(vector<int> &arr, int k, int x)
{
    int low = 0, high = arr.size() - 1;

    while (high - low >= k)
    {
        int diffLeft = x - arr[low];
        int diffRight = arr[high] - x;

        if (diffLeft > diffRight)
            low++;
        else
            high--;
    }
    return vector<int>(arr.begin() + low, arr.begin() + high + 1);
}

vector<int> twoPointerMethodPractice(vector<int> &arr, int k, int x)
{
    int low = 0;
    int high = arr.size() - 1;

    while (high - low >= k)
    {
        int diffLeft = x - arr[low];
        int diffRight = arr[high] - x;

        if (diffLeft > diffRight)
            low++;
        else
            high--; //? satisfy both diffRight bigger or equal condition
    }

    return vector<int>(arr.begin() + low, arr.begin() + high + 1);
}

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    return twoPointerMethod(arr, k, x);
}

int main()
{
    return 0;
}