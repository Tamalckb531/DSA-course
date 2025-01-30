#include <iostream>
#include <vector>
using namespace std;

void moveAllNegToLeft(int *arr, int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {

        if (arr[left] < 0)
        {
            left++;
        }
        else if (arr[right] > 0)
        {
            right--;
        }
        else
        {
            swap(arr[left], arr[right]);
        }
    }
}

void moveAllNegToLeftPrac(int *arr, int n)
{
    int negativeIndex = 0;
    int positiveIndex = n - 1;

    while (negativeIndex < positiveIndex)
    {
        if (arr[negativeIndex] > 0 && arr[positiveIndex] < 0)
        {
            swap(arr[negativeIndex++], arr[positiveIndex--]);
        }
        else if (arr[negativeIndex] < 0)
        {
            negativeIndex++;
        }
        else
        {
            positiveIndex--;
        }
    }
}

void moveAllNegToRight(int *arr, int n)
{
    int negativeIndex = n - 1;
    int positiveIndex = 0;

    while (negativeIndex > positiveIndex)
    {
        if (arr[negativeIndex] > 0 && arr[positiveIndex] < 0)
        {
            swap(arr[negativeIndex--], arr[positiveIndex++]);
        }
        else if (arr[negativeIndex] < 0)
        {
            negativeIndex--;
        }
        else
        {
            positiveIndex++;
        }
    }
}

int main()
{
    int arr[] = {1, 2, -3, 4, -5, 6};
    int n = sizeof(arr) / sizeof(int);

    cout << "Before: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    moveAllNegToRight(arr, n);

    cout << "After: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}