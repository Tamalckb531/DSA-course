#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void mergeArray(vector<int> &nums, int start, int end, int mid)
{
    //? Creation of two array
    int leftLength = mid - start + 1;
    int rightLength = end - mid;

    int *leftArr = new int[leftLength];
    int *rightArr = new int[rightLength];

    //? Copying the values
    int Index = start;

    for (int i = 0; i < leftLength; i++)
    {
        leftArr[i] = nums[Index];
        Index++;
    }
    for (int j = 0; j < rightLength; j++)
    {
        rightArr[j] = nums[Index];
        Index++;
    }

    //? Sorting logic

    int i = 0;
    int j = 0;
    int mainIndex = start;

    while (i < leftLength && j < rightLength)
    {
        if (leftArr[i] < rightArr[j])
        {
            nums[mainIndex++] = leftArr[i++];
        }
        else
        {
            nums[mainIndex++] = rightArr[j++];
        }
    }

    while (i < leftLength)
    {
        nums[mainIndex++] = leftArr[i++];
    }
    while (i < leftLength)
    {
        nums[mainIndex++] = rightArr[j++];
    }

    //? free memory
    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(vector<int> &nums, int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    //? Left part divide
    mergeSort(nums, start, mid);

    //? Right part divide
    mergeSort(nums, mid + 1, end);

    //? sort the array and merge them (merge two sorted array)
    mergeArray(nums, start, end, mid);
}

vector<int> sortArray(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;
    mergeSort(nums, start, end);

    return nums;
}

int main()
{
    cout << "LeetCode 912. Sort an Array" << endl;
}