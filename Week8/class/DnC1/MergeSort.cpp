#include <iostream>
using namespace std;

void mergeSortConquer(int arr[], int s, int e, int mid)
{

    //? creation of two array
    int leftLength = mid - s + 1;
    int rightLength = e - mid;

    int *leftArr = new int[leftLength];
    int *rightArr = new int[rightLength];

    //? Copying the values
    int Index = s;

    for (int i = 0; i < leftLength; i++)
    {
        leftArr[i] = arr[Index];
        Index++;
    }
    for (int j = 0; j < rightLength; j++)
    {
        rightArr[j] = arr[Index];
        Index++;
    }

    //? sorting logic

    int i = 0;
    int j = 0;
    int mainIndex = s;

    while (i < leftLength && j < rightLength)
    {
        if (leftArr[i] < rightArr[j])
        {
            arr[mainIndex] = leftArr[i];
            mainIndex++;
            i++;
        }
        else
        {
            arr[mainIndex] = rightArr[j];
            mainIndex++;
            j++;
        }
    }

    while (i < leftLength)
    {
        arr[mainIndex] = leftArr[i];
        mainIndex++;
        i++;
    }

    while (j < rightLength)
    {
        arr[mainIndex] = rightArr[j];
        mainIndex++;
        j++;
    }

    //? free memory
    delete[] leftArr;
    delete[] rightArr;
}

void mergeSortDivide(int arr[], int s, int e)
{
    if (s >= e)
        return;

    int mid = (s + e) / 2;

    //? left part divide
    mergeSortDivide(arr, s, mid);

    //? right part divide
    mergeSortDivide(arr, mid + 1, e);

    //? Conquer
    mergeSortConquer(arr, s, e, mid);
}

int main()
{
    int arr[] = {10, 80, 110, 90, 50, 30, 40, 20};
    int size = 8;
    int s = 0;
    int e = size - 1;

    cout << "BEfore: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSortDivide(arr, s, e);

    // printing entire array
    cout << "After: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << endl;
    return 0;
}