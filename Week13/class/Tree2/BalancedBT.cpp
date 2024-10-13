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

    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;

        int leftH = getHeight(root->left);
        int rightH = getHeight(root->right);
        int Diff = abs(leftH - rightH);
        bool currStatus = Diff <= 1;

        bool leftStatus = isBalanced(root->left);
        bool rightStatus = isBalanced(root->right);

        return currStatus && leftStatus && rightStatus;
    }
};