#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int Binary_Search(int arr[], int start, int end, int element)
{
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (element > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return -1;
}

int expSearch(int arr[], int size, int elem)
{
    int i = 1;

    while (i < size && arr[i] <= elem)
    {
        i = i * 2; //? for getting the range like : 1-2, 2-4, 4-8, 8-16, 16-32 etc
    }

    int startIndex = i / 2;          //? startvalue of the desired range
    int endIndex = min(i, size - 1); //? endvalue of the desired range, but it can go beyond size so the min

    return Binary_Search(arr, startIndex, endIndex, elem); //? search only for the range
}

int main()
{
    int a[] = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    int n = sizeof(a) / sizeof(int);

    int x = 13;

    int ans = expSearch(a, n, x);
    cout << ans << endl;
    return 0;
}