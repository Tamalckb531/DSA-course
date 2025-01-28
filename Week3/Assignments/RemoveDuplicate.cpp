#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int checker = 1;
    int unique = 0;

    while (checker < nums.size())
    {
        if (nums[checker] == nums[unique])
            checker++;
        else
        {
            unique++;
            nums[unique] = nums[checker];
            checker++;
        }
    }

    return unique + 1;
}

int removeDuplicatesPractice(vector<int> &nums)
{
    int uniqueElementIndex = 0; //? taking first element unique
    int traversalIndex = 1;     //? as first element is unique so traversing from the second index

    while (traversalIndex < nums.size())
    {
        if (nums[uniqueElementIndex] == nums[traversalIndex])
            traversalIndex++;
        else
        {
            // uniqueElementIndex++;
            nums[++uniqueElementIndex] = nums[traversalIndex++];
            // traversalIndex++;
        }
    }

    return uniqueElementIndex + 1; //? as index starts from 0
}

int main()
{
    return 0;
}