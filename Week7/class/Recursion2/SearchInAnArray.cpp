#include <iostream>
using namespace std;

bool Search(int arr[], int size, int index, int target)
{
    //? base case
    if (index == size)
        return false;

    //? processing
    if (arr[index] == target)
        return true;

    //? recursive call
    Search(arr, size, index + 1, target);
    // return false;
}

int main()
{

    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = 6;
    int index = 0;
    int target = 20;
    bool ans = Search(arr, size, index, target);

    cout << endl
         << ans << endl;
    return 0;
}