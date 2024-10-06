#include <iostream>
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
    bool solve(TreeNode *root, int targetSum, int sum)
    {
        if (root == NULL)
            return false;

        //? processing
        sum += root->val;

        if (root->left == NULL && root->right == NULL)
            return sum == targetSum;

        bool leftAns = solve(root->left, targetSum, sum);
        bool rightAns = solve(root->right, targetSum, sum);

        return leftAns || rightAns;
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        int sum = 0;
        bool ans = solve(root, targetSum, sum);
        return ans;
    }
};