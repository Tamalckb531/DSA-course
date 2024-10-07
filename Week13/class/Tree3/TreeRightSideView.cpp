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
    //? on each traversal, we will increase the level and first access the right -> that's how we getting the top right of each level by matching level and ans.size()

    void solve(TreeNode *root, vector<int> &ans, int level)
    {
        if (root == NULL)
            return;

        if (level == ans.size())
            ans.push_back(root->val);

        solve(root->right, ans, level + 1);
        solve(root->left, ans, level + 1);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};