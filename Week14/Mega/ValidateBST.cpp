#include <iostream>
#include <vector>
#include <climits>
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
    bool solve(TreeNode *root, long long lb, long long ub)
    {
        if (!root)
            return true;

        return (root->val > lb) &&
               (root->val < ub) &&
               solve(root->left, lb, root->val) &&
               solve(root->right, root->val, ub);
    }

    bool isValidBST(TreeNode *root)
    {
        long long lowerBound = LONG_MIN;
        long long upperBound = LONG_MAX;

        return solve(root, lowerBound, upperBound);
    }
};