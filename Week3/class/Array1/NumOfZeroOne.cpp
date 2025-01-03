#include <iostream>
using namespace std;

// void Counter(int arr[], int size)
// {
//     int zero = 0;
//     int one = 0;

//     for (int i = 0; i < size; i++)
//     {
//         int currentElem = arr[i];
//         if (currentElem == 0)
//         {
//             zero++;
//         }
//         if (currentElem == 1)
//         {
//             one++;
//         }
//     }
//     cout << "Total zero: " << zero << endl;
//     cout << "Total one: " << one << endl;
// }

void Counter(int arr[], int size)
{
    int zero = 0;
    int one = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
            zero++;

        if (arr[i] == 1)
            one++;
    }
    cout << "Number of zero : " << zero << endl
         << "Number of one : " << one << endl;
}

int main()
{
    int arr[] = {0, 1, 1, 0, 0, 1, 1, 1, 2, 5, 0, 0, 1, 1, 1};
    int size = 15;
    Counter(arr, size);
    return 0;
}