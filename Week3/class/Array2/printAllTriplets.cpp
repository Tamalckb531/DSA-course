#include <iostream>
using namespace std;

void PrintAllTriplets(int nums[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                cout << nums[i] << " " << nums[j] << " " << nums[k] << endl
                     << endl;
                count++;
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "Total Printed Triplet : " << count << endl;
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    int size = 4;

    PrintAllTriplets(arr, size);

    cout << endl;
    return 0;
}