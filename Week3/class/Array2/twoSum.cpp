#include <iostream>
using namespace std;

void PrintTwoSum(int nums[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (nums[i] + nums[j] == target)
            {

                cout << "(" << nums[i] << "," << nums[j] << ")  ";
            }
        }
        cout << endl;
    }
}

void PrintTwoSumPrac(int nums[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                cout << "(" << nums[i] << "," << nums[j] << ")" << "  ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    int size = 4;
    int target = 60;

    PrintTwoSumPrac(arr, size, target);

    cout << endl;
    return 0;
}