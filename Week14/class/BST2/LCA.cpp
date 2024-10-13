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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return NULL;

        //? CASE 1: p and q are in left side
        if (p->val < root->val && q->val < root->val)
        {
            TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
            if (leftAns)
                return leftAns;
        }

        //? CASE 2: p and q are in right side
        if (p->val > root->val && q->val > root->val)
        {
            TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);
            if (rightAns)
                return rightAns;
        }

        //? CASE 3: p and q are in different side
        return root;
    }
};