#include <iostream>
#include <climits>
using namespace std;

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

void maxInArray(int arr[], int size, int index, int &maximum)
{
    //? base case
    if (index == size)
        return;

    //? processing
    maximum = max(maximum, arr[index]);

    //? recursive call
    maxInArray(arr, size, index + 1, maximum);
}

int main()
{

    int arr[] = {10, 20, 80, 40, 50, 60};
    int size = 6;
    int index = 0;
    int maximum = INT_MIN;
    maxInArray(arr, size, index, maximum);

    cout << endl
         << maximum << endl;
    return 0;
}