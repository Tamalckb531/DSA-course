#include <iostream>
#include <algorithm>
using namespace std;

void quickSort(int arr[], int low, int high)
{
    //? Just put the end element in it's correct position -> where left element will be less than it and right element will be more than it. -> Do it recursively

    //? Base case
    if (low >= high)
        return;

    int pivot = high;
    int swapper = low - 1;
    int traverser = low;

    //? aligning the smaller element of pivot in it's left
    while (traverser < pivot)
    {
        if (arr[traverser] < arr[pivot])
        {
            swapper++;
            swap(arr[swapper], arr[traverser]);
        }
        traverser++;
    }

    //? getting the pivot in it's correct position
    swapper++;
    swap(arr[swapper], arr[pivot]);

    //? Recursive calling
    quickSort(arr, low, swapper - 1);  // left call
    quickSort(arr, swapper + 1, high); // left call
}

int main()
{
    return 0;
}