#include <iostream>
using namespace std;

void pairPrint(int nums[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "(" << nums[i] << "," << nums[j] << ")  ";
        }
        cout << endl;
    }
}

void pairPrintPrac(int nums[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "(" << nums[i] << "," << nums[j] << ")" << "  ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    int size = 4;

    pairPrintPrac(arr, size);

    cout << endl;
    return 0;
}