#include <iostream>
using namespace std;

int singleNumber(int nums[], int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ nums[i];
    }

    return ans;
}

int main()
{
    return 0;
}