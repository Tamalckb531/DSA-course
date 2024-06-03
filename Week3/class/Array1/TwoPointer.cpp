#include <iostream>
using namespace std;

void ExtremePrint(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        if (left == right)
        {
            cout << arr[left] << " ";
            break;
        }

        cout << arr[left] << " ";
        left++;
        cout << arr[right] << " ";
        right--;
    }
}
int main()
{

    int arr[7] = {10, 20, 30, 40, 50, 60, 70};
    int size = 7;

    ExtremePrint(arr, size);

    cout << endl;
    return 0;
}