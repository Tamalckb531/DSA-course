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

int main()
{
    return 0;
}