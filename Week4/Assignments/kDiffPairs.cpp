#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int twoPointerApproach(vector<int> &nums, int k)
{
    // 1 : sort the array
    sort(nums.begin(), nums.end());

    // 2 : get the pair
    int n = nums.size();
    set<pair<int, int>> ans;
    int i = 0, j = 1;

    while (j < n)
    {
        int diff = nums[j] - nums[i];

        if (diff == k)
        {
            ans.insert({nums[i], nums[j]});
            i++;
            j++;
        }
        else if (diff > k)
        {
            i++;
        }
        else
        {
            j++;
        }
        if (i == j)
            j++;
    }

    return ans.size();
}

int twoPointerApproachPractice(vector<int> &nums, int diff)
{
    sort(nums.begin(), nums.end());

    int diffReduce = 0;
    int diffExpand = 1;

    set<pair<int, int>> ans;

    while (diffExpand < nums.size())
    {
        int currDiff = nums[diffExpand] - nums[diffReduce];

        if (currDiff == diff)
        {
            //? got one solution
            ans.insert({nums[diffReduce], nums[diffExpand]});
            diffReduce++;
            diffExpand++;
        }
        else if (currDiff > diff)
        {
            //? need reduce diff
            diffReduce++;
        }
        else
        {
            diffExpand++;
        }

        if (diffReduce == diffExpand)
            diffExpand++; //? diff = 0 condition handled
    }

    return ans.size();
}

bool binarySearch(vector<int> &nums, int start, int rightSideVal)
{
    int end = nums.size() - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (rightSideVal == nums[mid])
        {
            return true;
        }
        else if (rightSideVal < nums[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }

    return false;
}

int binarySearchApproach(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    set<pair<int, int>> ans;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        // k = a[j] - a[i]
        // a[j] = k + a[i] -> this is right side value which we will find in the right of the array.
        int rightSideValue = nums[i] + k;
        if (binarySearch(nums, i + 1, rightSideValue))
        {
            ans.insert({nums[i], nums[i] + k});
        }
    }

    return ans.size();
}

int findPairs(vector<int> &nums, int k)
{
    int ans = twoPointerApproach(nums, k);
    return ans;
}

int main()
{
    return 0;
}