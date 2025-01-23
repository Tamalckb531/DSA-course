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

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = 6;
    // cyclically rotate array by 2 places
    int shift = 2;

    cout << "Before : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    rotateArray(arr, size, shift);

    cout << "After : " << endl;
    //? should be like this : {50, 60, 10, 20, 30, 40}
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}