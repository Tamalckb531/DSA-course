#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};
class Solution
{
public:
    TreeNode *solve(vector<int> &nums, int s, int e)
    {
        if (s > e)
            return NULL;

        int mid = s + (e - s) / 2;
        int element = nums[mid];

        TreeNode *root = new TreeNode(element);
        root->left = solve(nums, s, mid - 1);
        root->right = solve(nums, mid + 1, e);

        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int start = 0;
        int end = nums.size() - 1;
        TreeNode *root = solve(nums, start, end);
        return root;
    }
};