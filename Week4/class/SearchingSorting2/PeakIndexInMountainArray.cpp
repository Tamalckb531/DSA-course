#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int ansIndex = -1;

    while (start <= end)
    {
        // line 1: increasing order
        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        // line 2; decreasing order and peak index
        else if (arr[mid] > arr[mid + 1])
        {
            ansIndex = mid;
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return ansIndex;
}

int peakIndexInMountainArrayPractice(vector<int> &arr)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid = end + (start - end) / 2;
    int ansIndex = -1;

    while (start <= end)
    {
        if (arr[mid] < arr[mid + 1])
        {
            //? on increasing order -> search in right + can't be pick
            start = mid + 1;
        }
        else if (arr[mid] > arr[mid + 1])
        {
            //? on decreasing order -> search in left + can be pick
            ansIndex = mid;
            end = mid - 1;
        }
        mid = end + (start - end) / 2;
    }

    return ansIndex;
}

int main()
{
    return 0;
}