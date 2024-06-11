#include <iostream>
using namespace std;

void findFirstOccurrence(int arr[], int n, int target, int &ansIndex)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == target)
        {
            ansIndex = mid;
            //? we got the target but it may or may not be the first occurrence. So we will search on the left to get the target again until we find the first occurrence
            end = mid - 1;
        }
        else if (target > arr[mid])
        {
            start = mid + 1;
        }
        else if (target < arr[mid])
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
}

int main()
{
    int arr[] = {5, 10, 15, 20, 20, 20, 20, 30, 40, 50, 60};
    int n = 11;
    int target = 20;
    int ansIndex = -1;

    findFirstOccurrence(arr, n, target, ansIndex);
    cout << "First Occurrence Index: " << ansIndex + 1 << endl;

    return 0;
}