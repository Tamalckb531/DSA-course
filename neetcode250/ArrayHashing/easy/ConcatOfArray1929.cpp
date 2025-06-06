#include <iostream>
#include <vector>
using namespace std;

vector<int> getConcatenation(vector<int> &nums)
{
    vector<int> ans;
    int size = nums.size();

    for (int i = 0; i < size; i++)
    {
        ans.push_back(nums[i]);
    }

    for (int i = 0; i < size; i++)
    {
        ans.push_back(nums[i]);
    }

    return ans;
}

int main()
{
    cout << "LeetCode 1929: Concatenation of Array" << endl;
}