#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> seen;

    for (auto num : nums)
    {
        if (seen.count(num))
            return true;
        seen.insert(num);
    }

    return false;
}

int main()
{
    cout << "LeetCode 217. Contains Duplicate" << endl;
}