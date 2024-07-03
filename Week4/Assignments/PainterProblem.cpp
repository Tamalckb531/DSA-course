#include <iostream>
#include <numeric>
using namespace std;

bool isPaintingPossible(int arr[], int totalBoards, int totalPainters, long long int minBoardLengthTime)
{
    long long int paintTime = 0;
    int painterCount = 1;

    for (int i = 0; i < totalBoards; i++)
    {

        if (arr[i] > minBoardLengthTime)
            return false;

        if (paintTime + arr[i] > minBoardLengthTime)
        {
            painterCount++;
            paintTime = arr[i];
            if (painterCount > totalPainters)
                return false;
        }

        else
        {
            paintTime += arr[i];
        }
    }

    return true;
}

long long minTime(int arr[], int n, int k)
{
    int totalBoards = n;
    int totalPainters = k;

    long long start = 0;
    long long end = accumulate(arr, arr + n, 0);
    long long mid = start + (end - start) / 2;
    long long ans = -1;

    while (start <= end)
    {
        if (isPaintingPossible(arr, totalBoards, totalPainters, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }

    return ans;
}

int main()
{
    cout << "Hello World!\n";
    int n = 4;
    int arr[] = {12, 34, 67, 90};
    int m = 2;

    int ans = minTime(arr, n, m);
    cout << ans << endl;
}