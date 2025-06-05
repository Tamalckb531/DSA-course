#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (val == nums[i])
            nums.erase(nums.begin() + i);
    }

    return nums.size();
}
int removeElement(vector<int> &nums, int val)
{
    int k = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
            nums[k++] = nums[i];
    }

    return k;
}

int main()
{
    cout << "LeetCode 27. Remove Element" << endl;
}