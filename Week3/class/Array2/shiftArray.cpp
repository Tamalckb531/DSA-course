#include <iostream>
using namespace std;

void rotateArray(int arr[], int size, int shift)
{
    // step 1: copy the shifted element in the temporary array
    int finalShift = shift % size;
    if (finalShift == 0)
    {
        // It will return the same array
        return;
    }
    int temp[10000];
    int index = 0;
    for (int i = size - finalShift; i < size; i++)
    {
        temp[index] = arr[i];
        index++;
    }

    // step 2: Shift array element by shift place
    for (int i = size - 1; i >= 0; i--)
    {
        if (i - finalShift >= 0)
        {
            arr[i] = arr[i - finalShift];
        }
    }

    // step 3: Copy the elements into original array
    for (int i = 0; i < finalShift; i++)
    {
        arr[i] = temp[i];
    }
}

void rotateArrayPrac(int arr[], int size, int shift)
{
    //? step 1 : count the finalShift for optimal shifting

    int finalShift = shift % size;

    //? step 2 : move the items to shift in a temp array
    int temp[1000];
    int tmpIndex = 0;
    for (int i = size - finalShift; i < size; i++)
    {
        temp[tmpIndex++] = arr[i];
    }
    //? step 3 : shift the other items from left to right
    for (int i = size - 1; i >= finalShift; i--)
    {
        arr[i] = arr[i - finalShift];
    }
    //? step 4 : add the temp array item from left to right
    for (int i = 0; i < finalShift; i++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = 6;
    // cyclically rotate array by 2 places
    int shift = 13;

    cout << "Before : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    rotateArrayPrac(arr, size, shift);

    cout << "After : " << endl;
    //? should be like this : {50, 60, 10, 20, 30, 40}
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}