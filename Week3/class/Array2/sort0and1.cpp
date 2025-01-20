#include <iostream>
using namespace std;

void sortZeroOne(int nums[], int size)
{
    int zeroCount = 0;
    int oneCount = 1;

    // counting
    for (int i = 0; i < size; i++)
    {
        if (nums[i] == 0)
        {
            zeroCount++;
        }
        if (nums[i] == 0)
        {
            oneCount++;
        }
    }

    // insertion
    for (int i = 0; i < zeroCount; i++)
    {
        nums[i] = 0;
    }
    for (int i = zeroCount; i < size; i++)
    {
        nums[i] = 1;
    }
}

int main()
{
    int arr[] = {0, 1, 1, 1, 0, 0, 1};
    int size = 7;

    sortZeroOne(arr, size);

    // printing the array -> should be {0,0,0,1,1,1,1}
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}