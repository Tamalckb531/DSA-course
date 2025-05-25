#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int single = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        single = single ^ nums[i];
    }

    return single;
}

int main()
{
    return 0;
}