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
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int LeftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        int maxDepth = max(LeftDepth, rightDepth);
        int totalDepth = 1 + maxDepth;

        return totalDepth;
    }
};