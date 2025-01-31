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

int findDuplicate(vector<int> &nums)
{
    int firstNum = nums[0];
    while (firstNum != nums[firstNum])
    {
        swap(firstNum, nums[firstNum]);
    }
    return firstNum;
}

int main()
{
    return 0;
}