#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void solve(TreeNode *root, int targetSum, vector<int> &path, vector<vector<int>> &ans, int sum)
    {
        if (root == NULL)
            return;

        sum += root->val;
        path.push_back(root->val);

        if (root->left == NULL && root->right == NULL)
        {
            if (sum == targetSum)
                ans.push_back(path);
            path.pop_back(); //? for leaf node
            return;
        }

        solve(root->left, targetSum, path, ans, sum);
        solve(root->right, targetSum, path, ans, sum);

        path.pop_back(); //? for non-leaf node
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> path;
        vector<vector<int>> ans;
        int sum = 0;
        solve(root, targetSum, path, ans, sum);
        return ans;
    }
};