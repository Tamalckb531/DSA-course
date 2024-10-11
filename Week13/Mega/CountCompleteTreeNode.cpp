#include <iostream>
#include <algorithm>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
public:
    //? call until the left and right height are not same

    int leftHeight(TreeNode *root)
    {
        int count = 0;
        while (root)
        {
            count++;
            root = root->left;
        }

        return count;
    }

    int rightHeight(TreeNode *root)
    {
        int count = 0;
        while (root)
        {
            count++;
            root = root->right;
        }

        return count;
    }

    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if (lh == rh)
            return (pow(2, lh) - 1);

        int leftAns = countNodes(root->left);
        int rightAns = countNodes(root->right);

        return 1 + leftAns + rightAns;
    }
};