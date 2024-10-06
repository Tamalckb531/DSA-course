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
    int getHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int left = getHeight(root->left);
        int right = getHeight(root->right);
        int totalHeight = max(left, right) + 1;
        return totalHeight;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int optionLeft = diameterOfBinaryTree(root->left);
        int optionRight = diameterOfBinaryTree(root->right);
        int optionBoth = getHeight(root->left) + getHeight(root->right);

        int maxDiameter = max(optionLeft, max(optionRight, optionBoth));

        return maxDiameter;
    }
};