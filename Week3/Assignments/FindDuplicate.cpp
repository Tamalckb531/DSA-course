#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    int firstElem = nums[0];
    while (firstElem != nums[firstElem])
    {
        swap(firstElem, nums[firstElem]);
    }
    return firstElem;
}

int main()
{
    return 0;
}