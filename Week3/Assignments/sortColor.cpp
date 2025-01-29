#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int> &nums)
{
    int zero, one, two;
    zero = one = two = 0;
    // counting the appearance
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            zero++;
        }
        else if (nums[i] == 1)
        {
            one++;
        }
        else
        {
            two++;
        }
    }

    int i = 0;
    while (zero)
    {
        nums[i] = 0;
        i++;
        zero--;
    }
    while (one)
    {
        nums[i] = 1;
        i++;
        one--;
    }
    while (two)
    {
        nums[i] = 2;
        i++;
        two--;
    }
}

void threePointerApproach(vector<int> &nums)
{
    int low, medium, high;
    low = medium = 0;
    high = nums.size() - 1;

    while (medium <= high)
    {
        if (nums[medium] == 0)
        {
            swap(nums[low], nums[medium]);
            low++;
            medium++;
        }
        else if (nums[medium] == 1)
        {
            medium++;
        }
        else
        {
            swap(nums[high], nums[medium]);
            high--;
        }
    }
}

void DutchNationalFlagApproach(vector<int> &nums)
{
    int zeroIndex, traverseIndex, twoIndex;
    zeroIndex = traverseIndex = 0;
    twoIndex = nums.size() - 1;

    while (traverseIndex <= twoIndex)
    {
        if (nums[traverseIndex] == 0)
        {
            swap(nums[traverseIndex], nums[zeroIndex]);
            traverseIndex++;
            zeroIndex++;
        }
        else if (nums[traverseIndex] == 1)
        {
            traverseIndex++;
        }
        else
        {
            swap(nums[traverseIndex], nums[twoIndex]);
            twoIndex--;
        }
    }
}

void sortColors(vector<int> &nums)
{
    // countingSort(nums);
    threePointerApproach(nums);
}

int main()
{
    return 0;
}